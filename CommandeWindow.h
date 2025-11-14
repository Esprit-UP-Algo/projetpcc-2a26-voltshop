#ifndef COMMANDEWINDOW_H
#define COMMANDEWINDOW_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class CommandeWindow; }
QT_END_NAMESPACE

class CommandeWindow : public QWidget
{
    Q_OBJECT

public:
    explicit CommandeWindow(QWidget *parent = nullptr);
    ~CommandeWindow();

signals:
    void backRequested(); // pour revenir vers paiement

private:
    Ui::CommandeWindow *ui;
};

#endif // COMMANDEWINDOW_H
