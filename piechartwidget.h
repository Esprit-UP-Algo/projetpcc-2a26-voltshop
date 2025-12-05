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
    void setColors(const QMap<QString, QColor> &colors);
    QColor getColorForItem(const QString &key, int index) const;

    void setTitle(const QString &title) { m_title = title; update(); }
    void setTextColor(const QColor &color) { m_textColor = color; update(); }
    void setTitleColor(const QColor &color) { m_titleColor = color; update(); }

protected:
    void showEvent(QShowEvent *event) override;
    void paintEvent(QPaintEvent *event) override;
    QSize minimumSizeHint() const override { return QSize(200,150); }

private:
    // Données
    QMap<QString,int> m_data;
    QMap<QString,QColor> m_customColors;
    QList<QColor> m_colors;
    QList<QColor> m_defaultColors;

    // Animation
    QGraphicsOpacityEffect *m_opacityEffect = nullptr;
    QPropertyAnimation *m_fadeIn = nullptr;
    QPropertyAnimation *m_scaleAnim = nullptr;

    // pop animation scaling
    qreal m_popScale = 1.0;
    qreal popScale() const { return m_popScale; }
    void setPopScale(qreal s) { m_popScale = s; update(); }

    // Style
    QString m_title;
    QColor m_textColor = Qt::black;
    QColor m_titleColor = Qt::black;
};

#endif // PIECHARTWIDGET_H
