#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_quit_clicked();

    // Edit button slots for each row
    void on_pushButton_10_clicked(); // Row 0 edit button
    void on_pushButton_14_clicked(); // Row 1 edit button
    void on_pushButton_11_clicked(); // Row 2 edit button
    void on_pushButton_13_clicked(); // Row 3 edit button
    void on_pushButton_12_clicked(); // Row 4 edit button
    void on_pushButton_15_clicked(); // Row 5 edit button

    // Form button slots
    void on_pushButton_3_clicked();  // Cancel button

    // ✅ AJOUT : bouton principal Add/Update (même nom que dans ton UI)
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

    // Helper function to populate form from table row
    void populateFormFromTableRow(int row);

    // Helper function to reset form to add mode
    void resetFormToAddMode();

    // Track if we're in edit mode and which row
    bool isEditMode;
    int currentEditRow;

    // ✅ AJOUTS : Oracle + TableWidget
    void setupClientsTableWidget();     // prépare le QTableWidget
    void loadClientsFromDatabase();     // SELECT Oracle -> remplit le tableau

    bool insertClientToDatabase(        // INSERT Oracle
        const QString& cinVal,
        const QString& firstName,
        const QString& lastName,
        const QString& email,
        const QString& address,
        const QString& phone);

    bool updateClientInDatabase(        // UPDATE Oracle (par CIN)
        const QString& cinVal,
        const QString& firstName,
        const QString& lastName,
        const QString& email,
        const QString& address,
        const QString& phone);
};

#endif // MAINWINDOW_H
