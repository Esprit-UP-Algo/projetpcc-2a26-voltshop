#ifndef MAINWINDOW_H
#define MAINWINDOW_H
//#include "face_recognition.h"
//#include <opencv2/opencv.hpp>
#include <QMainWindow>
#include <QPushButton>
#include <QTableWidget>
#include <QWidget>
#include <QMessageBox>// ✅ Needed for confirmation messages
#include "arduinoserialcom.h"
#include "connection.h"
#include "arduino.h"
#include <QSerialPort>
#include <QMainWindow>
#include <QPushButton>
#include <QTableWidget>
#include "clientpiechartwidget.h"
#include "clientbarchartwidget.h"
#include <QInputDialog>

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
#include <QRandomGenerator>

#include "article_dao.h"
#include "client_dao.h"
#include "commande.h"
#include "gestion_employee.h"
#include "excelexporter.h"
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QTimer>
#include <QSystemTrayIcon>
#include "VoltShopFeedbackPanel.h"
#include <QPushButton>


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
    
    // Role-based access control
    void setInitialRole(const QString &username, const QString &role);
    static bool s_skipHeavyInit;
    
    // Arduino LCD display
    void sendOrderToLCD(const QString &total, const QString &products);

private slots:
    // ----- Navigation (stackedWidget) -----
    void showSClient();
    void showCommande();
    void showStock();
    void showTransaction();
    void showEmployee();
    
    // ----- Logout -----
    void on_quit_clicked();
    void on_btn_Client_clicked();
    void on_btn_Commande_clicked();
    void on_btn_Stock_clicked();
    void on_btn_Transaction_clicked();
    void on_btn_Employee_clicked();

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

    void onGeocodeFinished(QNetworkReply *reply);
    void trierCommandes(const QString &critere);
    void on_pushButton_search_clicked();
    void on_lineEdit_search_textChanged(const QString &text);
    void on_pushButton_deliveryTracking_clicked();
    void on_btnExportCatalogue_clicked();
    void update_statistiques_from_database();
    void check_tab_commande_data();


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
    void on_comboBox_Emp_Sort_currentTextChanged(const QString &sortBy);
    void on_pushButton_Emp_Stats_clicked();
    void on_btnPointage_clicked();
    void on_chat_bot_clicked();
    void on_export_pp_clicked();
    void onideReceived(const QString &ide);
    

    void onArduinoConnectionChanged(bool connected);
    void onArduinoError(const QString &error);
    void testArduinoConnection();
    void handleArduinoMessage(const QString &msg);


private:
    Ui::MainWindow *ui;
    ArduinoSerialCom *m_arduinoCom;
    // Role-based access control members
    QString m_currentUsername;
    QString m_currentRole;
    void openRoleTab(const QString &role);
    void applyRoleRestrictions(const QString &role);
    
    // Excel export for transactions
    ExcelExporter *m_excelExporter;
    
    // Arduino integration
    ArduinoManager *arduino;
    QSerialPort *lcdPort;

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
    void highlightSidebar(QPushButton *active);





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


    void chargerClientsComboBox();
    void  chargerClientsFichier();    // Lecture JSON
    void mettreAJourComboBoxClients();

    void update_statistiques_from_table();
    void sauvegarderClients(const QString &code, const QString &client);  // Ancienne
    void sauvegarderClients(const QString &code, const QString &client, bool deleteMode);  // Nouvel

     bool validateClientAddress(const QString &address);

    // === FONCTIONS PDF ===
    QMap<QString, double> generateRandomPromos();
    void drawPresentationPage(QPainter &painter, QPdfWriter &pdf, const QMap<QString, double> &productPromos);
    void drawCategoryHeader(QPainter &painter, QPdfWriter &pdf, const QString &category, int y);
    void drawProductCard(QPainter &painter, QPdfWriter &pdf, int row, int y, double randomPromo);
    void drawPromoBadge(QPainter &painter, int x, int y, double promoRate);
    void drawStockIndicator(QPainter &painter, int x, int y, int stock);
    void drawFooter(QPainter &painter, QPdfWriter &pdf, int pageNumber);
    void drawPromoSummaryPage(QPainter &painter, QPdfWriter &pdf, const QMap<QString, double> &productPromos, int &pageNumber);
    QColor getCategoryColor(const QString &category);






    void envoyerNotificationEmail(const QString &emailClient,
                                  const QString &code,
                                  const QDate &date,
                                  const QString &produits,
                                  double total,
                                  const QString &statut);
    QString obtenirEmailClientParNom(const QString &nomClient);


    QNetworkAccessManager *netManager;

    // Dans mainwindow.h
    // Dans mainwindow.h
    QString generateMapHtml(const QString &status, const QString &clientName, const QString &address,
                            double startLat, double startLon, double destLat, double destLon,
                            double progress, double arianaLat, double arianaLon);



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
    QString currentEmployeeSort;
    PieChartWidget *empChartWidget = nullptr;
    //cv::VideoCapture camera; // DISABLED
    bool getOpenSession(const QString &cin, QDateTime &timeIn, int &attendanceId);
    void clockInEmployee(const QString &cin);
    void clockOutEmployee(int attendanceId,
                          const QDateTime &timeIn,
                          const QString &cin);
    double calculateHourlyRate(const QString &position);
    void updateEmployeeSalary(const QString &cin, double hoursWorked);
    double getWorkedHours(const QDateTime &timeIn, const QDateTime &timeOut);
};

#endif // MAINWINDOW_H
