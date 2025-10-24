#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QTableWidget>

#include "article_dao.h"  // DAO Articles (pur C++)
#include "client_dao.h"   // DAO Clients  (pur C++)

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
    // ----- Navigation (stackedWidget) -----
    void showSClient();
    void showCommande();
    void showStock();
    void showTransaction();
    void showEmployee();

    // ====== ARTICLES ======
    void on_confirm_clicked();                 // Add / Update (formulaire Articles)
    void on_delete_clicked();                  // Delete via sélection (Articles)
    void on_DEL_clicked();                     // Delete via Line_rech (Articles)
    void on_tab_Art_cellChanged(int row, int column); // (désactivé, on garde pour compat)

    // ====== CLIENTS ======
    void on_c_confirm_clicked();               // Add / Update (formulaire Clients)
    void on_c_delete_clicked();                // Delete via sélection (Clients)
    void on_c_DEL_clicked();                   // Delete via c_Line_rech (Clients)

private:
    Ui::MainWindow *ui;

    // ====== ARTICLES - état écran ======
    bool m_loading    = false;   // évite signaux pendant remplissage tab_Art
    bool m_isEditMode = false;   // false=Add, true=Update
    int  m_currentRow = -1;      // ligne sélectionnée

    // ====== CLIENTS - état écran ======
    bool m_clientEditMode = false;
    int  m_clientRow = -1;
    bool m_clientTableInit = false; // prépare tab_Client au 1er accès

    // ====== ARTICLES - préparation & affichage ======
    void setupTabArt();                // prépare QTableWidget Articles
    void refreshArticlesGrid();        // fetchAll -> remplit tableau
    void addActionButtonsForRow(int row); // stylo (colonne 0)
    Article readFormArticle() const;   // lit le formulaire
    void setFormMode(bool edit);       // bascule Add/Update
    void populateFormFromRow(int row); // alimente formulaire depuis la ligne
    QString columnNameFor(int column) const;

    // ====== CLIENTS - préparation & affichage ======
    void setupTabClient();                 // prépare QTableWidget Clients
    void refreshClientsGrid();             // fetchAll -> remplit tableau
    void addClientEditPenForRow(int row);  // stylo (colonne 0)
    Client readClientForm() const;         // lit le formulaire
    void setClientFormMode(bool edit);     // bascule Add/Update
    void populateClientFormFromRow(int row);
};

#endif // MAINWINDOW_H
