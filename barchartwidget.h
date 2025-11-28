#ifndef BARCHARTWIDGET_H
#define BARCHARTWIDGET_H

#include <QWidget>
#include <QMap>

class BarChartWidget : public QWidget
{
    Q_OBJECT
public:

    explicit BarChartWidget(QWidget *parent = nullptr);
    void setData(const QMap<QString,int> &data);
    void setTitle(const QString &title) { m_title = title; update(); }

protected:
    void paintEvent(QPaintEvent *event) override;
    QSize minimumSizeHint() const override { return QSize(300,200); }

private:
    QMap<QString,int> m_data;
    QString m_title;
    QList<QColor> m_colors;
};

#endif // BARCHARTWIDGET_H
