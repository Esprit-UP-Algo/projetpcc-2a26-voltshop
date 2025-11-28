#include "aiinsightsdialog.h"
#include <QVBoxLayout>
#include <QHeaderView>
#include <QPushButton>

AiInsightsDialog::AiInsightsDialog(const QVector<StockInsight>& insights,
                                   QWidget* parent)
    : QDialog(parent)
{
    setWindowTitle("AI Stock Insights");
    setModal(true);
    resize(700, 500);

    setupUi();
    fillTable(insights);
}

void AiInsightsDialog::setupUi()
{
    auto* layout = new QVBoxLayout(this);

    // ---- Titre / résumé ----
    m_summaryLabel = new QLabel(this);
    m_summaryLabel->setText("Analyse intelligente des articles");
    m_summaryLabel->setStyleSheet(
        "font-size: 18px; font-weight: bold; color: #004c99; margin: 4px 0 8px 0;"
        );

    layout->addWidget(m_summaryLabel);

    // ---- Tableau ----
    m_table = new QTableWidget(this);
    m_table->setColumnCount(3);
    QStringList headers;
    headers << "SKU" << "Statut" << "Recommandation";
    m_table->setHorizontalHeaderLabels(headers);
    m_table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    m_table->setAlternatingRowColors(true);
    m_table->setSelectionBehavior(QAbstractItemView::SelectRows);
    m_table->setEditTriggers(QAbstractItemView::NoEditTriggers);

    m_table->setStyleSheet(R"(
        QTableWidget {
            background: #f7fbff;
            gridline-color: #d0d7e2;
            font-size: 13px;
        }
        QHeaderView::section {
            background-color: #004c99;
            color: black;
            padding: 6px;
            border: none;
            font-weight: bold;
        }
        QTableWidget::item {
            padding: 4px;
        }
    )");

    layout->addWidget(m_table);

    // ---- Bouton Fermer ----
    auto* closeBtn = new QPushButton("Fermer", this);
    closeBtn->setFixedWidth(100);
    closeBtn->setStyleSheet(R"(
        QPushButton {
            background-color: #004c99;
            color: white;
            border-radius: 6px;
            padding: 6px 12px;
        }
        QPushButton:hover {
            background-color: #0066cc;
        }
    )");
    connect(closeBtn, &QPushButton::clicked, this, &QDialog::accept);

    auto* bottomLayout = new QHBoxLayout();
    bottomLayout->addStretch();
    bottomLayout->addWidget(closeBtn);

    layout->addLayout(bottomLayout);
}

void AiInsightsDialog::fillTable(const QVector<StockInsight>& insights)
{
    m_table->setRowCount(insights.size());

    int nbDormant = 0;
    int nbInter   = 0;
    int nbActif   = 0;

    for (int i = 0; i < insights.size(); ++i) {
        const auto& si = insights[i];

        auto* skuItem   = new QTableWidgetItem(si.sku);
        auto* typeItem  = new QTableWidgetItem(si.clusterName);
        auto* recoItem  = new QTableWidgetItem(si.recommendation);

        // 🎨 Couleurs pastel très claires
        QColor bg;

        if (si.clusterName.startsWith("Dormant", Qt::CaseInsensitive)) {
            bg = QColor("#FF0000");   // 🌸 rose pastel clair
            nbDormant++;
        }
        else if (si.clusterName.startsWith("Intermédiaire", Qt::CaseInsensitive)) {
            bg = QColor("#FFFF00");   // 🌼 beige crème très doux
            nbInter++;
        }
        else if (si.clusterName.startsWith("Actif", Qt::CaseInsensitive)) {
            bg = QColor("#008000");   // 🌿 vert menthe clair
            nbActif++;
        }
        else {
            bg = QColor("#F0F0F0");
        }

        skuItem->setBackground(bg);
        typeItem->setBackground(bg);
        recoItem->setBackground(bg);
        skuItem->setForeground(Qt::black);
        typeItem->setForeground(Qt::black);
        recoItem->setForeground(Qt::black);

        m_table->setItem(i, 0, skuItem);
        m_table->setItem(i, 1, typeItem);
        m_table->setItem(i, 2, recoItem);
    }

    // Mise à jour du texte résumé
    m_summaryLabel->setText(
        QString("Analyse intelligente des articles  •  %1 Dormants  •  %2 Intermédiaires  •  %3 Actifs")
            .arg(nbDormant)
            .arg(nbInter)
            .arg(nbActif)
        );
}
