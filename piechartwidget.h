#ifndef PIECHARTWIDGET_H
#define PIECHARTWIDGET_H

#include <QWidget>
#include <QMap>

class PieChartWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PieChartWidget(QWidget *parent = nullptr);
    void setData(const QMap<QString,int> &data);
    void setTitle(const QString &title) { m_title = title; update(); }

protected:
    void paintEvent(QPaintEvent *event) override;
    QSize minimumSizeHint() const override { return QSize(200,150); }

private:
    QMap<QString,int> m_data;
    QString m_title;
    QList<QColor> m_colors;
};

#endif // PIECHARTWIDGET_H
