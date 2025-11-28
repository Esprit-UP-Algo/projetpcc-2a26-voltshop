#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QTableWidget>
#include <QWidget>
#include <QMessageBox>// ✅ Needed for confirmation messages
#include "connection.h"
#include <QMainWindow>
#include <QPushButton>
#include <QTableWidget>
#include "clientpiechartwidget.h"
#include "clientbarchartwidget.h"


#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>
#include <QMap>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QtCharts/QChartGlobal>
#include <QtCharts/QChartView>
#include <QtCharts/QChart>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
// ❗ AUCUN namespace ici

#include "article_dao.h"
#include "client_dao.h"
#include "commande.h"
#include "gestion_employee.h"
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QTimer>
#include <QSystemTrayIcon>
#include "VoltShopFeedbackPanel.h"

struct StockInsight
{
    QString sku;
    QString clusterName;
    QString recommendation;
};


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class PieChartWidget;
class BarChartWidget;

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
    void on_confirm_clicked();
    void on_delete_2_clicked();
    void on_DEL_clicked();
    void on_tab_Art_cellChanged(int row, int column);
    void on_btn_pdf_clicked();
    void on_btn_stats_clicked();
    void on_btn_ai_stock_clicked();

    // ====== CLIENTS ======
    void on_c_confirm_clicked();
    void on_c_delete_clicked();
    void on_c_DEL_clicked();
    void on_pushButton_8_clicked();



    // ====== COMMANDES ======
    void on_pushButton_ajouter_clicked();
    void on_pushButton_supprimer_clicked();
    void on_tableauCommande_clicked(const QModelIndex &index);
    //void on_pushButton_edit_clicked();
    void on_pushButton_cancel_clicked();
    void onCommandeSelected(int row, int column);


    void trierCommandes(const QString &critere);
    void on_pushButton_search_clicked();
    void on_lineEdit_search_textChanged(const QString &text);

    // ====== TRANSACTIONS ======
    void on_pushButton_25_clicked();
    void on_pushButton_28_clicked();
    void on_pushButton_27_clicked();
    void on_lineEdit_17_textChanged(const QString &arg1);

    // ====== EMPLOYEES ======
    void on_confirmb_clicked();   // Confirm Add button
    void on_pushButton_31_clicked();
    void on_lineEdit_19_textChanged(const QString &arg1);
    void on_tab_Employee_cellClicked(int row, int column);
private:
    Ui::MainWindow *ui;

    // ====== ARTICLES ======
    void setupStockTableStyle();
    bool m_loading    = false;
    bool m_isEditMode = false;
    int  m_currentRow = -1;
    QChartView *m_stockStatsViewLeft  = nullptr;
    QChartView *m_stockStatsViewRight = nullptr;
    void buildStockStatsCharts();
    bool runPythonStockAnalysis();   // <--- ajoute cette ligne
    void fillArticlesTable(const QVector<Article>& rows);
    void refreshArticlesGridSortedByStock(bool ascending = true);
    void loadArticlesSortedByStockFromDb();
    QString buildStockAlertsHtmlForPdf();




    // ====== CLIENTS ======
    bool m_clientEditMode = false;
    int  m_clientRow = -1;
    bool m_clientTableInit = false;
    ClientPieChartWidget *clientAgeChart = nullptr;
    void buildClientAddressStats();
    QChartView *m_clientAddressChartView = nullptr;
    void journalAdd(const QString &action, const Client &c);
    void journalRefresh();
    VoltShopFeedbackPanel *feedbackPanel;











    // ====== ARTICLES methods ======
    void setupTabArt();
    void refreshArticlesGrid();
    void addActionButtonsForRow(int row);
    Article readFormArticle() const;
    void setFormMode(bool edit);
    void populateFormFromRow(int row);
    QString columnNameFor(int column) const;

    // ====== CLIENTS methods ======
    void setupTabClient();
    void refreshClientsGrid();
    void addClientEditPenForRow(int row);
    Client readClientForm() const;
    void setClientFormMode(bool edit);
    void populateClientFormFromRow(int row);
    void populateTransactionFormFromRow(int row);
    void clearTransactionFields();

    // ====== COMMANDES ======
    void rafraichirTableau();
    bool editing = false;
    QString editingCodeC ="";
    void clearFields();
    void afficherCommandes();
    int selectedRow = -1;
    bool validerChamps(QString code, QDate date, QString produits, double total, QString statut,QString client);
    void exporterPDFCommandes();
    bool validateSku3(QString &errorMsg);
    bool saveConcernerLinks(const QString &code, const QString &skuList);
    void loadSkuForOrder(const QString& code);

    void on_pushButton_exportpdf_clicked();
    void on_pushButton_6_clicked();
    QMap<QString, QString> clientsMap; // Associe code_commande → client

    void sauvegarderClients(const QString &code, const QString &client);  // Sauvegarde JSON
    void chargerClientsComboBox();
    void  chargerClientsFichier();    // Lecture JSON
    void mettreAJourComboBoxClients();

    void update_statistiques_from_table();



///////////////////
    void afficherTransactions();
    void afficherTransactionsSorted(const QString &sortBy);
    void populateStatusChart();
    PieChartWidget *statusChartViewWidget = nullptr;
    void populatePaymentMethodChart();
    BarChartWidget *paymentMethodChartWidget = nullptr;
    void populateAgeChart();
    PieChartWidget *cityChartViewWidget = nullptr;



    // ====== EMPLOYEES ======
    GestionEmployee g_emp;
    void populateEmployeeFormFromRow(int row);
    void refreshEmployeeTable();  // ✅ make sure this repopulates QTableWidget after add
    Employee readEmployeeForm() const;
    void clearEmployeeForm();
    bool m_employeeEditMode = false;
    QString m_editingCin;
};

#endif // MAINWINDOW_H
