#ifndef EMPLOYEEWINDOW_H
#define EMPLOYEEWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class EmployeeWindow;
}
QT_END_NAMESPACE

class EmployeeWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit EmployeeWindow(QWidget *parent = nullptr);
    ~EmployeeWindow();

signals:
    void backRequested();

private slots:
    void on_quit_clicked();

private:
    Ui::EmployeeWindow *ui;
};

#endif // EMPLOYEEWINDOW_H