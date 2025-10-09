#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gcommandewindow.h"

#include <QPushButton>
#include <QLayout>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 1) Déterminer AUTOMATIQUEMENT la zone de droite (= parent direct du tabWidget)
    if (!ui->tabWidget) {
        qWarning() << "[MainWindow] ui->tabWidget introuvable ! Vérifie l'objectName dans l'UI.";
    } else {
        rightContainer = ui->tabWidget->parentWidget();
        if (!rightContainer) {
            // fallback: au pire, utilise la zone centrale
            rightContainer = ui->centralwidget;
        }
        // s'assurer qu'il y a un layout sur la zone de droite (sinon, on en met un)
        if (!rightContainer->layout()) {
            auto v = new QVBoxLayout(rightContainer);
            v->setContentsMargins(0,0,0,0);
            v->setSpacing(0);
            rightContainer->setLayout(v);
        }
    }

    // 2) Bouton Gcommande (objectName = btn_com)
    if (auto btn = findChild<QPushButton*>("btn_com")) {
        connect(btn, &QPushButton::clicked, this, &MainWindow::openGcommandeModule);
    } else {
        qWarning() << "[MainWindow] Bouton 'btn_com' introuvable dans l'UI.";
    }
}

MainWindow::~MainWindow()
{
    delete ui;
    delete gcommandeWindow;
}

// ---------- utilitaire : afficher uniquement w dans la zone droite ----------
void MainWindow::showOnly(QWidget *w)
{
    if (!rightContainer) rightContainer = ui->centralwidget;

    // 1) cacher l’écran Stock (tabWidget)
    if (ui->tabWidget) ui->tabWidget->hide();

    // 2) placer w dans le même parent que tabWidget (zone droite)
    if (w->parent() != rightContainer) {
        w->setParent(rightContainer);
    }

    // 3) si la zone de droite a un layout, ajoute w dedans une seule fois
    if (auto lay = rightContainer->layout()) {
        if (lay->indexOf(w) == -1) {
            lay->addWidget(w);
        }
    }

    // 4) s’assurer qu’il occupe toute la zone
    w->setGeometry(rightContainer->rect());
    w->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    // 5) afficher
    w->show();
    w->raise();
    w->activateWindow();
}

// ---------- revenir à la vue Stock (tabWidget) ----------
void MainWindow::showStockModule()
{
    if (gcommandeWindow) gcommandeWindow->hide();

    if (ui->tabWidget) {
        ui->tabWidget->show();
        ui->tabWidget->raise();
        ui->tabWidget->activateWindow();
    }
}

// ---------- ouvrir Gcommande ----------
void MainWindow::openGcommandeModule()
{
    if (!rightContainer) {
        qWarning() << "[MainWindow] rightContainer null — vérifie que tabWidget existe dans l'UI.";
        return;
    }

    if (!gcommandeWindow) {
        gcommandeWindow = new GcommandeWindow(rightContainer);
        // brancher le retour si tu as un bouton retour dans l'UI Gcommande (btnBackGcom)
        connect(gcommandeWindow, &GcommandeWindow::backRequested,
                this, &MainWindow::onGcommandeBack);
    }

    showOnly(gcommandeWindow);  // 👉 remplace seulement la zone droite
    qDebug() << "✅ GcommandeWindow affiché (sidebar intact)";
}

// ---------- retour depuis Gcommande ----------
void MainWindow::onGcommandeBack()
{
    showStockModule();
}
