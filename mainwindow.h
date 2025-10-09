#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include <QTableWidgetItem>

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
    void addPaymentToTable(); // New slot to add payment data to table
    void toggleDarkMode(); // Dark mode toggle function

private:
    Ui::MainWindow *ui;
    ClientWindow *clientWindow;
    int paymentIdCounter = 1; // Counter for payment IDs
    bool isDarkMode = false; // Track dark mode state

};
#endif // MAINWINDOW_H
