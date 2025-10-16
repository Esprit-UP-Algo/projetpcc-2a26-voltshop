#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    bool m_loading = false;      // évite UPDATE pendant le remplissage
    void setupTabArt();          // prépare tab_Art
    void loadTabArt();           // SELECT -> remplit tab_Art
    QString columnNameFor(int column) const;

private slots:
    void on_confirm_clicked();                 // bouton "confirm"
    void on_delete_clicked();                  // bouton "delete"
    void on_tab_Art_cellChanged(int row, int column); // édition -> UPDATE
};

#endif // MAINWINDOW_H
