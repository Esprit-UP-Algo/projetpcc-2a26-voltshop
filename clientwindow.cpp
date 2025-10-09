#include "clientwindow.h"
#include "ui_clientwindow.h"
#include <QPixmap>
#include "mainwindow.h"

ClientWindow::ClientWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ClientWindow)
    , isDarkMode(false)
{
    ui->setupUi(this);
    
    // Connect the dark mode button
    connect(ui->darkmode_button, &QPushButton::clicked, this, &ClientWindow::toggleDarkMode);
    
    // You can add the statistics chart later
    // QPixmap pix_stat("ressource/customer_stats.png");
    // if (!pix_stat.isNull()) {
    //     ui->stat->setPixmap(pix_stat.scaled(700,700,Qt::KeepAspectRatio));
    // }
}

ClientWindow::~ClientWindow()
{
    delete ui;
}

void ClientWindow::logout()
{
    // Close this window and show the main window login screen
    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();
    this->close();
}

void ClientWindow::toggleDarkMode()
{
    isDarkMode = !isDarkMode;
    
    if (isDarkMode) {
        // Dark mode styles
        ui->tabWidget->setStyleSheet(
            "QTabWidget::pane {"
            "    border: 1px solid #444444;"
            "    background: #2D2D2D;"
            "    border-radius: 6px;"
            "    padding: 6px;"
            "}"
            /*"QTabBar::tab {"
            "    background: #1A1A1A;"
            "    color: #CCCCCC;"
            "    padding: 8px 16px;"
            "    border-top-left-radius: 6px;"
            "    border-top-right-radius: 6px;"
            "    margin-right: 2px;"
            "    font-weight: bold;"
            "}"
            "QTabBar::tab:selected {"
            "    background: #444444;"
            "    color: #FFFFFF;"
            "}"
            "QTabBar::tab:hover {"
            "    background: #555555;"
            "    color: #FFFFFF;"
            "}"*/
        );
        
        // Update other widgets in dark mode
       /* ui->groupBox->setStyleSheet(
            "QGroupBox {"
            "    background-color: #444444;"
            "    border: 2px solid #555555;"
            "    border-radius: 6px;"
            "    margin-top: 20px;"
            "    padding: 10px;"
            "    font-family: Segoe UI, Arial;"
            "    font-size: 14px;"
            "    font-weight: bold;"
            "    color: #CCCCCC;"
            "}"
            "QGroupBox::title {"
            "    subcontrol-origin: margin;"
            "    subcontrol-position: top left;"
            "    padding: 2px 8px;"
            "    background-color: #555555;"
            "    color: white;"
            "    border-radius: 4px;"
            "}"
        );
        
        // Update table widget in dark mode
        ui->tableWidget->setStyleSheet(
            "QTableWidget {"
            "    background-color: #2D2D2D;"
            "    alternate-background-color: #3A3A3A;"
            "    gridline-color: #555555;"
            "    border: 1px solid #555555;"
            "    selection-background-color: #0066CC;"
            "    selection-color: white;"
            "    font-family: Segoe UI, Arial;"
            "    font-size: 13px;"
            "    color: #CCCCCC;"
            "}"
            "QHeaderView::section {"
            "    background-color: #444444;"
            "    color: #CCCCCC;"
            "    padding: 6px;"
            "    border: none;"
            "    font-weight: bold;"
            "}"
            "QTableCornerButton::section {"
            "    background-color: #444444;"
            "    border: none;"
            "}"
        );
        
        // Update labels in dark mode
        QList<QLabel*> labels = ui->tabWidget->findChildren<QLabel*>();
        for (QLabel* label : labels) {
            label->setStyleSheet("color: #CCCCCC;");
        }
        
        // Update line edits in dark mode
        QList<QLineEdit*> lineEdits = ui->tabWidget->findChildren<QLineEdit*>();
        for (QLineEdit* lineEdit : lineEdits) {
            lineEdit->setStyleSheet(
                "QLineEdit {"
                "    background-color: #3A3A3A;"
                "    border: 2px solid #555555;"
                "    border-radius: 6px;"
                "    padding: 6px 10px;"
                "    font-size: 14px;"
                "    color: #CCCCCC;"
                "}"
                "QLineEdit:focus {"
                "    border: 2px solid #0066CC;"
                "    background-color: #444444;"
                "}"
            );
        }*/
        
        // Update buttons in dark mode
        /*QList<QPushButton*> buttons = ui->tabWidget->findChildren<QPushButton*>();
        for (QPushButton* button : buttons) {
            if (button != ui->darkmode_button) {
                button->setStyleSheet(
                    "QPushButton {"
                    "    background-color: #444444;"
                    "    color: #CCCCCC;"
                    "    border-radius: 6px;"
                    "    padding: 6px 12px;"
                    "    font-weight: bold;"
                    "    border: 2px solid #555555;"
                    "}"
                    "QPushButton:hover { background-color: #555555; }"
                    "QPushButton:pressed { background-color: #333333; }"
                );
            }
        }*/
    } else {
        // Light mode (default) styles
        ui->tabWidget->setStyleSheet(
            "QTabWidget::pane {"
            "    border: 1px solid #00A3E0;"
            "    background: #E6F2FA;"
            "    border-radius: 6px;"
            "    padding: 6px;"
            "}"
            "QTabBar::tab {"
            "    background: #003271;"
            "    color: white;"
            "    padding: 8px 16px;"
            "    border-top-left-radius: 6px;"
            "    border-top-right-radius: 6px;"
            "    margin-right: 2px;"
            "    font-weight: bold;"
            "}"
            "QTabBar::tab:selected {"
            "    background: #ADD8E6;"
            "    color: white;"
            "}"
            "QTabBar::tab:hover {"
            "    background: #004599;"
            "    color: white;"
            "}"
        );
        
        // Reset other widgets to light mode
        ui->groupBox->setStyleSheet(
            "QGroupBox {"
            "     background-color: rgb(173, 216, 230);"
            "     border: 2px solid #00A3E0;"
            "     border-radius: 6px;"
            "     margin-top: 20px;"
            "     padding: 10px;"
            "     font-family: Segoe UI, Arial;"
            "     font-size: 14px;"
            "     font-weight: bold;"
            "     color: #003271;"
            " }"
            " QGroupBox::title {"
            "     subcontrol-origin: margin;"
            "     subcontrol-position: top left;"
            "     padding: 2px 8px;"
            "     background-color: #00A3E0;"
            "     color: white;"
            "     border-radius: 4px;"
            " }"
        );
        
        // Reset table widget to light mode
        ui->tableWidget->setStyleSheet(
            "QTableWidget {"
            "     background-color: white;"
            "     alternate-background-color: #E6F2FA;"
            "     gridline-color: #ADD8E6;"
            "     border: 1px solid #ADD8E6;"
            "     selection-background-color: #003271;"
            "     selection-color: white;"
            "     font-family: Segoe UI, Arial;"
            "     font-size: 13px;"
            " }"
            " QHeaderView::section {"
            "     background-color: #ADD8E6;"
            "     color: black;"
            "     padding: 6px;"
            "     border: none;"
            "     font-weight: bold;"
            " }"
            " QTableCornerButton::section {"
            "     background-color: #ADD8E6;"
            "     border: none;"
            " }"
        );
        

    }
}
