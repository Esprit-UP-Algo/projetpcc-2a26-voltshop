#ifndef GCOMMANDEWINDOW_H
#define GCOMMANDEWINDOW_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class GcommandeWindow; }
QT_END_NAMESPACE

class GcommandeWindow : public QWidget
{
    Q_OBJECT
public:
    explicit GcommandeWindow(QWidget *parent = nullptr);
    ~GcommandeWindow();

signals:
    // Émis par ton bouton "Retour" (si tu en mets un dans l'UI)
    void backRequested();

private:
    Ui::GcommandeWindow *ui;
};

#endif // GCOMMANDEWINDOW_H
