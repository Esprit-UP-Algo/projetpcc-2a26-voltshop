#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include "article_dao.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // Navigation (stackedWidget)
    void showSClient();
    void showCommande();
    void showStock();
    void showTransaction();
    void showEmployee();

    // CRUD côté UI (appellent le DAO)
    void on_confirm_clicked();                 // Add / Update (selon mode)
    void on_delete_clicked();                  // delete via sélection (bouton global "delete")
    void on_DEL_clicked();                     // delete via Line_rech (bouton global "DEL")

    // Désactivé (on n'édite plus dans la grille)
    void on_tab_Art_cellChanged(int row, int column);

private:
    Ui::MainWindow *ui;

    // État écran
    bool m_loading    = false;   // évite signaux pendant remplissage
    bool m_isEditMode = false;   // false=Add, true=Update
    int  m_currentRow = -1;      // ligne courante

    // Préparation & affichage
    void setupTabArt();            // prépare le QTableWidget (colonnes, properties)
    void refreshArticlesGrid();    // fetchAll() -> remplit le tableau + ajoute boutons actions

    // Helpers UI
    void setFormMode(bool edit);           // bascule Add <-> Update (verrouille SKU, change bouton)
    void populateFormFromRow(int row);     // copie la ligne dans le formulaire
    Article readFormArticle() const;       // lit le formulaire -> Article
    void addActionButtonsForRow(int row);  // ajoute stylo + DEL (option B robuste)

    // (Conservé pour compatibilité)
    QString columnNameFor(int column) const;
};

#endif // MAINWINDOW_H
