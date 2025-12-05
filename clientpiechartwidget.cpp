#include "clientpiechartwidget.h"
#include <QPainter>
#include <QStyleOption>
#include <QPainterPath>
#include <QGraphicsOpacityEffect>
#include <QPropertyAnimation>
#include <QShowEvent>
#include <QAbstractAnimation>
#include <QEasingCurve>
#include <cmath>

static const double PI_CONST = 3.14159265358979323846;

ClientPieChartWidget::ClientPieChartWidget(QWidget *parent)
    : QWidget(parent)
{
    // Couleurs : 18-25, 25-40, 40-60, +60
    m_colors = {
        QColor(46,204,113),   // 18-25  (vert)
        QColor(102,179,231),  // 25-40  (bleu clair)
        QColor(2, 62, 138),   // 40-60  (bleu foncé)
        QColor(87, 75, 144)   // +60    (violet)
    };

    // Fade-in
    m_opacityEffect = new QGraphicsOpacityEffect(this);
    m_opacityEffect->setOpacity(0.0);
    setGraphicsEffect(m_opacityEffect);

    m_fadeIn = new QPropertyAnimation(m_opacityEffect, "opacity", this);
    m_fadeIn->setDuration(350);
    m_fadeIn->setStartValue(0.0);
    m_fadeIn->setEndValue(1.0);

    // Scale animation (pop)
    m_scaleAnim = new QPropertyAnimation(this, "popScale", this);
    m_scaleAnim->setDuration(300);
    m_scaleAnim->setStartValue(0.95);
    m_scaleAnim->setEndValue(1.0);
    m_scaleAnim->setEasingCurve(QEasingCurve::OutBack);
}

void ClientPieChartWidget::showEvent(QShowEvent *event)
{
    QWidget::showEvent(event);

    if (m_fadeIn) {
        m_fadeIn->stop();
        m_fadeIn->start();
    }
    if (m_scaleAnim) {
        m_scaleAnim->stop();
        m_scaleAnim->start();
    }
}

void ClientPieChartWidget::setData(const QMap<QString,int> &data)
{
    m_data = data;
    update();
}

void ClientPieChartWidget::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing);

    // Animation scale (pop)
    if (!qFuzzyCompare(m_popScale, (qreal)1.0)) {
        p.save();
        const qreal cx = width() * 0.5;
        const qreal cy = height() * 0.5;
        p.translate(cx, cy);
        p.scale(m_popScale, m_popScale);
        p.translate(-cx, -cy);
    }

    // Fond
    QStyleOption opt;
    opt.initFrom(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);

    const int margin = 12;
    QRect r = rect().adjusted(margin, margin, -margin, -margin);

    // Zone du camembert (on garde tout l’espace)
    QRect pieRect = r.adjusted(0, 40, 0, -12);

    // Titre
    if (!m_title.isEmpty()) {
        QFont titleFont = p.font();
        titleFont.setPointSize(qMax(10, r.height() / 24));
        titleFont.setBold(true);
        p.setFont(titleFont);
        p.setPen(Qt::black);

        QRect titleRect(pieRect.left(), r.top() + 5, pieRect.width(), 28);
        p.drawText(titleRect, Qt::AlignLeft | Qt::AlignVCenter, m_title);
    }

    // Total des valeurs
    int total = 0;
    for (int v : m_data.values())
        total += v;

    if (total <= 0) {
        p.setPen(Qt::black);
        p.drawText(pieRect, Qt::AlignCenter, "No Data");
        if (!qFuzzyCompare(m_popScale, (qreal)1.0))
            p.restore();
        return;
    }

    // Couleurs FIXES par tranche d'âge
    const QMap<QString, QColor> ageColors = {
        { "18-25", QColor(46,204,113) },   // vert
        { "25-40", QColor(102,179,231) },  // bleu clair
        { "40-60", QColor(  2, 62,138) },  // bleu foncé
        { "+60",   QColor( 87, 75,144) }   // violet
    };

    // Ordre d’affichage des tranches
    const QStringList orderedKeys = { "18-25", "25-40", "40-60", "+60" };

    // Géométrie du camembert
    QRectF pieF(pieRect);
    qreal centerX = pieF.center().x();
    qreal centerY = pieF.center().y();
    qreal radius  = qMin(pieF.width(), pieF.height()) / 2.0;
    const qreal explodeDist = qMax(6.0, pieRect.width() * 0.03);

    // ====================
    // 1) Dessin des parts
    // ====================
    qreal startAngle = 0.0;

    for (const QString &key : orderedKeys) {

        if (!m_data.contains(key))
            continue;

        int value = m_data.value(key);
        if (value <= 0)
            continue;

        qreal span = (qreal)value / (qreal)total * 360.0;
        QColor col = ageColors.value(key, Qt::gray);

        // Décalage "explode"
        qreal mid = startAngle + span / 2.0;
        qreal dx  = std::cos(mid * PI_CONST / 180.0) * explodeDist;
        qreal dy  = std::sin(mid * PI_CONST / 180.0) * explodeDist;
        QRectF shifted = pieF.translated(dx, dy);

        QPainterPath path;
        path.moveTo(shifted.center());
        path.arcTo(shifted, -startAngle, -span);
        path.closeSubpath();

        p.setBrush(col);
        p.setPen(QPen(Qt::white, 1));
        p.drawPath(path);

        startAngle += span;
    }

    // ==========================
    // 2) Labels (pourcentages)
    // ==========================
    startAngle = 0.0;

    QFont percentFont = p.font();
    percentFont.setBold(true);
    percentFont.setPointSize(qMax(9, r.height() / 40));

    for (const QString &key : orderedKeys) {

        if (!m_data.contains(key))
            continue;

        int value = m_data.value(key);
        if (value <= 0)
            continue;

        qreal span = (qreal)value / (qreal)total * 360.0;
        qreal pct  = (qreal)value * 100.0 / (qreal)total;

        QColor col = ageColors.value(key, Qt::gray);

        // Plus la part est petite, plus on pousse le label vers l’extérieur
        qreal mid    = startAngle + span / 2.0;
        qreal rad    = mid * PI_CONST / 180.0;
        qreal factor = (span < 30.0) ? 0.70 : 0.50;
        qreal dx     = std::cos(rad) * (radius * factor);
        qreal dy     = std::sin(rad) * (radius * factor);
        QPointF label(centerX + dx, centerY + dy);

        QRectF textRect(label.x() - 40, label.y() - 10, 80, 20);

        p.setFont(percentFont);
        p.setPen(col.lightness() < 140 ? Qt::white : Qt::black);
        p.drawText(textRect,
                   Qt::AlignCenter,
                   QString("%1%").arg(QString::number(pct, 'f', 1)));

        startAngle += span;
    }

    if (!qFuzzyCompare(m_popScale, (qreal)1.0))
        p.restore();
}

