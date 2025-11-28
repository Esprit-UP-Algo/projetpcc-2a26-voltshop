#ifndef CLIENTPIECHARTWIDGET_H
#define CLIENTPIECHARTWIDGET_H

#include <QWidget>
#include <QMap>
#include <QGraphicsOpacityEffect>

class QPropertyAnimation;
class QShowEvent;

class ClientPieChartWidget : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(qreal popScale READ popScale WRITE setPopScale)

public:
    explicit ClientPieChartWidget(QWidget *parent = nullptr);

    void setData(const QMap<QString,int> &data);
    void setTitle(const QString &title) { m_title = title; update(); }

protected:
    void paintEvent(QPaintEvent *event) override;
    void showEvent(QShowEvent *event) override;
    QSize minimumSizeHint() const override { return QSize(220, 180); }

private:
    // Données du graphique : label -> valeur
    QMap<QString,int> m_data;
    QString m_title;

    // Palette utilisée pour les tranches d'âge client
    QList<QColor> m_colors;

    // Animations
    QGraphicsOpacityEffect *m_opacityEffect = nullptr;
    QPropertyAnimation *m_fadeIn = nullptr;
    QPropertyAnimation *m_scaleAnim = nullptr;

    // Propriété animée (zoom)
    qreal m_popScale = 1.0;
    qreal popScale() const { return m_popScale; }
    void setPopScale(qreal s) { m_popScale = s; update(); }
};

#endif // CLIENTPIECHARTWIDGET_H
