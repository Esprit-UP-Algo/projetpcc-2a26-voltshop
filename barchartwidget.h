#ifndef BARCHARTWIDGET_H
#define BARCHARTWIDGET_H

#include <QWidget>
#include <QMap>
#include <QColor>

class BarChartWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BarChartWidget(QWidget *parent = nullptr);

    void setData(const QMap<QString,int> &data);
    void setColors(const QMap<QString, QColor> &colors);

    void setTitle(const QString &title) { m_title = title; update(); }
    void setTextColor(const QColor &color) { m_textColor = color; update(); }
    void setTitleColor(const QColor &color) { m_titleColor = color; update(); }
    void setAxisLabelColor(const QColor &color) { m_axisLabelColor = color; update(); }
    void setGridColor(const QColor &color) { m_gridColor = color; update(); }

protected:
    void paintEvent(QPaintEvent *event) override;
    QSize minimumSizeHint() const override { return QSize(300,200); }

private:
    QMap<QString,int> m_data;
    QMap<QString,QColor> m_customColors;

    QString m_title;
    QList<QColor> m_colors;

    QColor m_textColor = Qt::black;
    QColor m_titleColor = Qt::black;
    QColor m_axisLabelColor = Qt::black;
    QColor m_gridColor = QColor(200, 200, 200);
};

#endif // BARCHARTWIDGET_H
