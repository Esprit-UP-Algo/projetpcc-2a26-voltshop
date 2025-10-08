#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidgetItem>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class ClientWindow;
class StockWindow;
class CommandeWindow;
class EmployeeWindow;                 // ✅ nouveau

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void openClientModule();
    void openStockModule();
    void openCommandeModule();
    void openEmployeeModule();        // ✅ nouveau
    void onStockBack();
    void onCommandeBack();
    void onEmployeeBack();            // ✅ nouveau
    void showPaymentModule();
    void logout();
    void addPaymentToTable();
    void toggleDarkMode();

private:
    Ui::MainWindow *ui;
    ClientWindow   *clientWindow;
    StockWindow    *stockWindow;
    CommandeWindow *commandeWindow;
    EmployeeWindow *employeeWindow;   // ✅ nouveau
    int  paymentIdCounter = 1;
    bool isDarkMode = false;
};

#endif // MAINWINDOW_H
