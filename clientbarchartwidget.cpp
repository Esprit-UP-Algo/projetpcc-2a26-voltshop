#include "clientbarchartwidget.h"
#include <QPainter>
#include <QStyleOption>
#include <QPropertyAnimation>
#include <QShowEvent>

ClientBarChartWidget::ClientBarChartWidget(QWidget *parent)
    : QWidget(parent)
{
    m_opacityEffect = new QGraphicsOpacityEffect(this);
    m_opacityEffect->setOpacity(0.0);
    setGraphicsEffect(m_opacityEffect);

    m_fadeIn = new QPropertyAnimation(m_opacityEffect, "opacity", this);
    m_fadeIn->setDuration(400);
    m_fadeIn->setStartValue(0.0);
    m_fadeIn->setEndValue(1.0);
}

void ClientBarChartWidget::setData(const QMap<QString,int> &data)
{
    m_data = data;
    update();
}

void ClientBarChartWidget::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing);

    QStyleOption opt;
    opt.initFrom(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);

    if (m_data.isEmpty())
        return;

    int margin = 20;
    QRect area = rect().adjusted(margin, margin + 20, -margin, -margin);

    // Title
    if (!m_title.isEmpty()) {
        QFont f = p.font();
        f.setPointSize(13);
        f.setBold(true);
        p.setFont(f);

        p.drawText(QRect(rect().left(), rect().top(), rect().width(), 30),
                   Qt::AlignLeft | Qt::AlignVCenter,
                   m_title);
    }

    // Determine max value
    int maxVal = 0;
    for (int v : m_data.values()) maxVal = qMax(maxVal, v);

    int barHeight = 26;
    int spacing = 14;
    int y = area.top();

    QFont f = p.font();
    f.setBold(true);
    p.setFont(f);

    for (auto it = m_data.begin(); it != m_data.end(); ++it)
    {
        QString key = it.key();
        int value = it.value();

        // Text
        p.setPen(Qt::black);
        p.drawText(area.left(), y, 120, barHeight,
                   Qt::AlignLeft | Qt::AlignVCenter,
                   key);

        // Bar width
        double ratio = (double)value / maxVal;
        int barWidth = ratio * (area.width() - 150);

        // Bar color
        QColor barColor(2, 62, 138);  // bleu foncé pro
        p.fillRect(area.left() + 130, y + 4, barWidth, barHeight - 8, barColor);

        // Value
        p.setPen(Qt::white);
        p.drawText(area.left() + 140, y,
                   barWidth, barHeight,
                   Qt::AlignRight | Qt::AlignVCenter,
                   QString::number(value));

        y += barHeight + spacing;
    }

    if (m_fadeIn && m_opacityEffect->opacity() == 0.0)
        m_fadeIn->start();
}
