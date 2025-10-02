#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class ClientWindow;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void openClientModule();
    void showPaymentModule();
    void logout();

private:
    Ui::MainWindow *ui;
    ClientWindow *clientWindow;

};
#endif // MAINWINDOW_H
