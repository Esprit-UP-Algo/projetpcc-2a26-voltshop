#include "barchartwidget.h"
#include <QPainter>
#include <QStyleOption>

BarChartWidget::BarChartWidget(QWidget *parent)
    : QWidget(parent)
{
    m_colors = {
        QColor(44,130,201), // primary blue
        QColor(90,180,240),
        QColor(46,204,113),
        QColor(243,156,18),
        QColor(155,89,182)
    };
}

void BarChartWidget::setData(const QMap<QString,int> &data)
{
    m_data = data;
    update();
}


void BarChartWidget::setColors(const QMap<QString, QColor> &colors)
{
    m_customColors = colors;
    update();
}

void BarChartWidget::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing);

    // draw background
    QStyleOption opt;
    opt.initFrom(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);

    const int margin = 20;
    QRect r = rect().adjusted(margin, margin, -margin, -margin);

    // Title
    if (!m_title.isEmpty()) {
        QFont f = p.font(); f.setPointSize(14); f.setBold(true);
        p.setFont(f);
        p.setPen(Qt::white);
        p.drawText(QRect(r.left(), r.top(), r.width(), 24), Qt::AlignCenter, m_title);
    }

    // Chart area
    QRect chartRect = r.adjusted(0, 30, 0, -20);
    if (m_data.isEmpty()) {
        p.setPen(Qt::white);
        p.drawText(chartRect, Qt::AlignCenter, "No Data");
        return;
    }

    int maxVal = 0;
    for (auto v : m_data) maxVal = qMax(maxVal, v);
    if (maxVal <= 0) maxVal = 1;

    int barCount = m_data.size();
    int spacing = 16;
    int totalSpacing = spacing * (barCount + 1);
    int barAreaWidth = chartRect.width() - totalSpacing;
    int barWidth = qMax(8, barAreaWidth / qMax(1, barCount));

    int x = chartRect.left() + spacing;
    int colorIndex = 0;
    QFont labelFont = p.font(); labelFont.setPointSize(9);
    p.setFont(labelFont);

    // Y axis lines (3 ticks)
    p.setPen(QPen(QColor(200,200,200), 1));
    for (int i = 0; i <= 4; ++i) {
        int yy = chartRect.bottom() - (chartRect.height() - 30) * i / 4;
        p.drawLine(chartRect.left(), yy, chartRect.right(), yy);
    }

    // Draw bars and labels
    for (auto it = m_data.constBegin(); it != m_data.constEnd(); ++it) {
        int val = it.value();
        qreal h = (qreal)val / maxVal * (chartRect.height() - 40);
        QRectF barRect(x, chartRect.bottom() - h - 10, barWidth, h);
        QColor col = m_colors[colorIndex % m_colors.size()];
        p.setBrush(col);
        p.setPen(Qt::NoPen);
        p.drawRoundedRect(barRect, 4, 4);

        // value above bar
        p.setPen(Qt::black);
        p.drawText(QRectF(x, barRect.top() - 18, barWidth, 16), Qt::AlignCenter, QString::number(val));

        // label below
        QString label = it.key();
        QRectF labRect(x - spacing/2, chartRect.bottom() - 6, barWidth + spacing, 20);
        p.drawText(labRect, Qt::AlignCenter | Qt::TextWordWrap, label);

        x += barWidth + spacing;
        colorIndex++;
    }
}
