    #ifndef MAINWINDOW_H
    #define MAINWINDOW_H
    #include "face_recognition.h"
    #include <opencv2/opencv.hpp>
    #include <QMainWindow>
    #include <QPushButton>
    #include <QTableWidget>
    #include <QWidget>
    #include <QMessageBox>// ✅ Needed for confirmation messages
    #include "connection.h"
    #include <QMainWindow>
    #include <QPushButton>
    #include <QTableWidget>

    #include <QPdfWriter>
    #include <QPainter>
    #include <QFileDialog>
    #include <QMap>
    #include <QFile>
    #include <QJsonDocument>
    #include <QJsonObject>

    #include "article_dao.h"
    #include "client_dao.h"
    #include "commande.h"
    #include "gestion_employee.h"

    QT_BEGIN_NAMESPACE
    namespace Ui { class MainWindow; }
    QT_END_NAMESPACE

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
        void on_confirm_clicked();
        void on_delete_2_clicked();
        void on_DEL_clicked();
        void on_tab_Art_cellChanged(int row, int column);

        // ====== CLIENTS ======
        void on_c_confirm_clicked();
        void on_c_delete_clicked();
        void on_c_DEL_clicked();

        // ====== COMMANDES ======
        void on_pushButton_ajouter_clicked();
        void on_pushButton_supprimer_clicked();
        void on_tableauCommande_clicked(const QModelIndex &index);
        void on_pushButton_edit_clicked();
        void on_pushButton_cancel_clicked();
        void trierCommandes(const QString &critere);
        void on_pushButton_search_clicked();
        void on_lineEdit_search_textChanged(const QString &text);


<<<<<<< HEAD
        // ====== TRANSACTIONS ======
        void on_pushButton_25_clicked();
        void on_pushButton_28_clicked();
        void on_pushButton_27_clicked();
=======
    // ====== TRANSACTIONS ======
    void on_pushButton_25_clicked();
    void on_pushButton_28_clicked();
    void on_pushButton_27_clicked();
    void on_lineEdit_17_textChanged(const QString &arg1);
>>>>>>> fa065ab36e11e25d1251f5a8cdc9329a165d3f94

        // ====== EMPLOYEES ======
        void on_confirmb_clicked();   // Confirm Add button
        void on_pushButton_31_clicked();
        void on_lineEdit_19_textChanged(const QString &arg1);
        void on_tab_Employee_cellClicked(int row, int column);
        void on_comboBox_Emp_Sort_currentTextChanged(const QString &sortBy);
        void on_pushButton_Emp_Stats_clicked();
        void on_btnPointage_clicked();
        void on_chat_bot_clicked();
    private:
        Ui::MainWindow *ui;

        // ====== ARTICLES ======
        bool m_loading    = false;
        bool m_isEditMode = false;
        int  m_currentRow = -1;

        // ====== CLIENTS ======
        bool m_clientEditMode = false;
        int  m_clientRow = -1;
        bool m_clientTableInit = false;

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

<<<<<<< HEAD
        QMap<QString, QString> clientsMap; // Associe code_commande → client
=======
    void on_pushButton_exportpdf_clicked();
    QMap<QString, QString> clientsMap; // Associe code_commande → client
>>>>>>> fa065ab36e11e25d1251f5a8cdc9329a165d3f94

        void sauvegarderClients(const QString &code, const QString &client);  // Sauvegarde JSON
        void chargerClientsComboBox();
        void  chargerClientsFichier();    // Lecture JSON
        void mettreAJourComboBoxClients();

    ///////////////////
        void afficherTransactions();
        void afficherTransactionsSorted(const QString &sortBy);
        void populateStatusChart();
        PieChartWidget *statusChartViewWidget = nullptr;



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
        cv::VideoCapture camera;
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
