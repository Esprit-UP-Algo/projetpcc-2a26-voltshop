#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class GcommandeWindow;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void openGcommandeModule();
    void onGcommandeBack();
    void showStockModule();        // réaffiche le tabWidget (stock)

private:
    void showOnly(QWidget* w);     // affiche un widget à la place du tabWidget (à droite seulement)

private:
    Ui::MainWindow *ui;
    QWidget *rightContainer = nullptr;  // parent de tabWidget (zone droite)
    GcommandeWindow *gcommandeWindow = nullptr;
};

#endif // MAINWINDOW_H
