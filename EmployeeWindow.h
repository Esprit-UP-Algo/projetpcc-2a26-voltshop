#ifndef EMPLOYEEWINDOW_H
#define EMPLOYEEWINDOW_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class EmployeeWindow; }
QT_END_NAMESPACE

class EmployeeWindow : public QWidget
{
    Q_OBJECT
public:
    explicit EmployeeWindow(QWidget *parent = nullptr);
    ~EmployeeWindow();

signals:
    void backRequested();              // émis par un bouton "Retour" si tu en mets un

private:
    Ui::EmployeeWindow *ui;
};

#endif // EMPLOYEEWINDOW_H
