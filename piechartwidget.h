#ifndef PIECHARTWIDGET_H
#define PIECHARTWIDGET_H

#include <QWidget>
#include <QMap>
#include <QGraphicsOpacityEffect>

class QPropertyAnimation;
class QShowEvent;

class PieChartWidget : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(qreal popScale READ popScale WRITE setPopScale)
public:
    explicit PieChartWidget(QWidget *parent = nullptr);
    void setData(const QMap<QString,int> &data);
    void setTitle(const QString &title) { m_title = title; update(); }
    // animate when widget becomes visible
    void showEvent(QShowEvent *event) override;

protected:
    void paintEvent(QPaintEvent *event) override;
    QSize minimumSizeHint() const override { return QSize(200,150); }

private:
    QMap<QString,int> m_data;
    QString m_title;
    QList<QColor> m_colors;
    QGraphicsOpacityEffect *m_opacityEffect = nullptr;
    QPropertyAnimation *m_fadeIn = nullptr;
    QPropertyAnimation *m_scaleAnim = nullptr;
    qreal m_popScale = 1.0;
    // popScale accessors for animation
    qreal popScale() const { return m_popScale; }
    void setPopScale(qreal s) { m_popScale = s; update(); }
};

#endif // PIECHARTWIDGET_H
