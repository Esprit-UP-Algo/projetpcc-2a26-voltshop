#ifndef CLIENTBARCHARTWIDGET_H
#define CLIENTBARCHARTWIDGET_H

#include <QWidget>
#include <QMap>
#include <QGraphicsOpacityEffect>

class QPropertyAnimation;

class ClientBarChartWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ClientBarChartWidget(QWidget *parent = nullptr);
    void setData(const QMap<QString,int> &data);
    void setTitle(const QString &title) { m_title = title; update(); }

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    QMap<QString,int> m_data;
    QString m_title;

    QGraphicsOpacityEffect *m_opacityEffect = nullptr;
    QPropertyAnimation *m_fadeIn = nullptr;
};

#endif
