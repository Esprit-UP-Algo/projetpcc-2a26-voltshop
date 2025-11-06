#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QTableWidget>

// Use a generic QWidget pointer for the chart view in the header to avoid
// pulling heavy QtCharts headers into moc-generated files. The concrete
// QtCharts types are included and used inside the .cpp implementation.
#include <QWidget>

#include "article_dao.h"  // DAO Articles (pur C++)
#include "client_dao.h"   // DAO Clients  (pur C++)
#include "commande.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

// forward declare the PieChartWidget implemented in piechartwidget.h
class PieChartWidget;

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
    void on_delete_2_clicked();                  // Delete via sélection (Articles)
    void on_DEL_clicked();                     // Delete via Line_rech (Articles)
    void on_tab_Art_cellChanged(int row, int column); // (désactivé, on garde pour compat)

    // ====== CLIENTS ======
    void on_c_confirm_clicked();               // Add / Update (formulaire Clients)
    void on_c_delete_clicked();                // Delete via sélection (Clients)
    void on_c_DEL_clicked();                   // Delete via c_Line_rech (Clients)

    //cmd
    void on_pushButton_ajouter_clicked();
    void on_pushButton_supprimer_clicked();
    void on_tableauCommande_clicked(const QModelIndex &index);
    void on_pushButton_edit_clicked();
    void on_pushButton_cancel_clicked();
    // Transactions (Payments)
    void on_pushButton_25_clicked(); // Add Payment
    void on_pushButton_28_clicked(); // Delete Payment
    void on_pushButton_27_clicked(); // Export to Excel (CSV)
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
    void populateTransactionFormFromRow(int row);
    void clearTransactionFields();




    // ====== COMMANDES ======
    void rafraichirTableau();
    bool editing = false;
    int editingCode = -1;
    void clearFields();
    void afficherCommandes();
    void afficherTransactions();
    void afficherTransactionsSorted(const QString &sortBy);
    // Populate the pie chart that shows transaction status distribution
    void populateStatusChart();
    // Use a lightweight PieChartWidget (no QtCharts dependency)
    PieChartWidget *statusChartViewWidget = nullptr; // allocated in .cpp
    
    int selectedRow = -1;



};







#endif // MAINWINDOW_H
