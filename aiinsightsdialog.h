#ifndef AIINSIGHTSDIALOG_H
#define AIINSIGHTSDIALOG_H

#include <QDialog>
#include <QVector>
#include <QTableWidget>
#include <QLabel>

#include "mainwindow.h"  // pour le struct StockInsight (ou recopie le struct ici)

class AiInsightsDialog : public QDialog
{
    Q_OBJECT
public:
    explicit AiInsightsDialog(const QVector<StockInsight>& insights,
                              QWidget* parent = nullptr);

private:
    QTableWidget* m_table;
    QLabel* m_summaryLabel;

    void setupUi();
    void fillTable(const QVector<StockInsight>& insights);
};

#endif // AIINSIGHTSDIALOG_H
