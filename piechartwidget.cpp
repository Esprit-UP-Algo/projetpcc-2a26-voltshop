#include "piechartwidget.h"
#include <QPainter>
#include <QStyleOption>
#include <QPainterPath>
#include <cmath>

static const double PI_CONST = 3.14159265358979323846;

PieChartWidget::PieChartWidget(QWidget *parent)
    : QWidget(parent)
{
    // A simple palette of colors
    m_colors = {
        QColor(52, 152, 219), // blue
        QColor(231, 76, 60),  // red
        QColor(243, 156, 18), // orange
        QColor(46, 204, 113), // green
        QColor(155, 89, 182), // purple
        QColor(52, 73, 94)    // dark
    };
}

void PieChartWidget::setData(const QMap<QString,int> &data)
{
    m_data = data;
    update();
}

void PieChartWidget::paintEvent(QPaintEvent * /*event*/)
{
    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing);

    // draw background/style
    QStyleOption opt;
    opt.initFrom(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);

    const int margin = 12;
    QRect r = rect().adjusted(margin, margin, -margin, -margin);

    // reserve right area for legend
    int legendWidth = qMin(220, r.width() / 3);
    QRect pieRect = r.adjusted(0, 28, -legendWidth - 12, -12);
    QRect legendRect = QRect(r.right() - legendWidth + 6, r.top() + 6, legendWidth - 12, r.height() - 12);

    // title (left-aligned above pie area)
    if (!m_title.isEmpty()) {
        QFont titleFont = p.font();
        titleFont.setPointSize(qMax(10, r.height() / 24));
        titleFont.setBold(true);
        p.setFont(titleFont);
        p.setPen(palette().windowText().color());
        QRect titleRect = QRect(pieRect.left(), r.top(), pieRect.width(), 26);
        p.drawText(titleRect, Qt::AlignLeft | Qt::AlignVCenter, m_title);
    }

    int total = 0;
    for (auto v : m_data) total += v;
    if (total <= 0) {
        // draw placeholder
        p.setPen(palette().text().color());
        p.drawText(pieRect, Qt::AlignCenter, "No Data");
        return;
    }

    // draw pie with a small 'explode' offset for each slice and border
    QRectF pieF(pieRect);
    qreal startAngle = 0.0; // degrees
    int colorIndex = 0;
    QMapIterator<QString,int> it(m_data);
    const qreal explodeDist = qMax(6.0, pieRect.width() * 0.03);
    qreal centerX = pieF.center().x();
    qreal centerY = pieF.center().y();
    qreal radius = qMin(pieF.width(), pieF.height()) / 2.0;

    // draw slices
    while (it.hasNext()) {
        it.next();
        int value = it.value();
        qreal span = (qreal)value / total * 360.0;

        QColor col = m_colors[colorIndex % m_colors.size()];
        colorIndex++;

        // compute offset for explode effect
        qreal mid = startAngle + span / 2.0;
    qreal dx = std::cos(mid * PI_CONST / 180.0) * explodeDist;
    qreal dy = std::sin(mid * PI_CONST / 180.0) * explodeDist;

        QRectF shifted = pieF.translated(dx, dy);

        QPainterPath path;
        path.moveTo(shifted.center());
        path.arcTo(shifted, -startAngle, -span);
        path.closeSubpath();

        QBrush brush(col);
        p.setBrush(brush);
        p.setPen(QPen(Qt::white, 1));
        p.drawPath(path);

        startAngle += span;
    }

    // draw labels on slices (percentages) and legend
    startAngle = 0.0;
    colorIndex = 0;
    it.toFront();
    int y = legendRect.top();
    QFont labelFont = p.font();
    labelFont.setPointSize(qMax(8, r.height() / 40));
    p.setFont(labelFont);

    while (it.hasNext()) {
        it.next();
        QString key = it.key();
        int value = it.value();
        qreal span = (qreal)value / total * 360.0;
        qreal pct = (qreal)value * 100.0 / total;

        QColor col = m_colors[colorIndex % m_colors.size()];
        // label on slice if large enough
        qreal mid = startAngle + span / 2.0;
    qreal labelAngle = mid * PI_CONST / 180.0;
        qreal dx = std::cos(labelAngle) * (radius * 0.45);
        qreal dy = std::sin(labelAngle) * (radius * 0.45);
        QPointF labelCenter(centerX + dx, centerY + dy);

        QString inside = QString::number(pct, 'f', 1) + "%";
        if (span > 8.0) {
            QFont insideFont = p.font();
            insideFont.setBold(true);
            insideFont.setPointSize(qMax(8, r.height() / 48));
            p.setFont(insideFont);
            p.setPen(Qt::white);
            p.drawText(QRectF(labelCenter.x()-40, labelCenter.y()-10, 80, 20), Qt::AlignCenter, inside);
        }

        // legend entry: colored square + text on single line
        QRect sw(legendRect.left(), y, 18, 14);
        p.fillRect(sw, col);
        p.setPen(palette().text().color());
        p.drawRect(sw);

        QString legendText = QString("%1 (%2) — %3 %").arg(key).arg(value).arg(QString::number(pct,'f',1));
        QRect textR = QRect(sw.right() + 8, y - 2, legendRect.width() - (sw.width() + 8), 18);
        p.drawText(textR, Qt::AlignLeft | Qt::AlignVCenter, legendText);

        y += 22;
        startAngle += span;
        colorIndex++;
        if (y > legendRect.bottom() - 20) break; // avoid overflow
    }
}



