#ifndef STOCKWINDOW_H
#define STOCKWINDOW_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class StockWindow; }
QT_END_NAMESPACE

class StockWindow : public QWidget
{
    Q_OBJECT
public:
    explicit StockWindow(QWidget *parent = nullptr);
    ~StockWindow();

signals:
    void backRequested(); // ✅ signal émis si bouton "Retour" cliqué

private:
    Ui::StockWindow *ui;
};

#endif // STOCKWINDOW_H
