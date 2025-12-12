# Excel Export - Bilan Financier

## Installation Instructions

### 1. Install Python Dependencies

Open PowerShell and run:

```powershell
cd "C:\Users\lastg\Desktop\Verion_FINALE\Verion_FINALE\python_scripts"
pip install -r requirements.txt
```

Or install directly:
```powershell
pip install openpyxl
```

### 2. Manual Code Integration (IMPORTANT!)

Since automatic replacement didn't work, you need to **manually replace** the `on_pushButton_27_clicked()` function in `mainwindow.cpp`.

**Find this function around line 643:**
```cpp
void MainWindow::on_pushButton_27_clicked()
{
    QTableWidget *table = ui->tableWidget_4;
    // ... lots of CSV export code ...
}
```

**Replace it entirely with:**
```cpp
void MainWindow::on_pushButton_27_clicked()
{
    // Export transactions to Excel Bilan Financier
    LOG_INFO("Excel export button clicked");
    
    // Check if we have transactions
    QTableWidget *table = ui->tableWidget_4;
    if (!table || table->rowCount() == 0) {
        QMessageBox::information(this, 
            "Export Excel", 
            "Aucune transaction à exporter.\\n\\nAjoutez des transactions avant d'exporter le Bilan Financier.");
        return;
    }
    
    // Ask user where to save
    QString docsPath = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
    QString suggestedName = QDateTime::currentDateTime().toString("'Bilan_Financier_'yyyyMMdd_HHmmss'.xlsx'");
    
    QString fileName = QFileDialog::getSaveFileName(
        this,
        "💾 Exporter Bilan Financier Excel",
        docsPath + "/" + suggestedName,
        "Fichiers Excel (*.xlsx);;Tous les fichiers (*.*)"
    );
    
    if (fileName.isEmpty()) {
        return; // User cancelled
    }
    
    // Ensure .xlsx extension
    if (!fileName.endsWith(".xlsx", Qt::CaseInsensitive)) {
        fileName += ".xlsx";
    }
    
    // Show progress message
    QMessageBox *progressBox = new QMessageBox(this);
    progressBox->setWindowTitle("Export en cours...");
    progressBox->setText("Génération du Bilan Financier en cours...");
    progressBox->setStandardButtons(QMessageBox::NoButton);
    progressBox->setModal(true);
    progressBox->show();
    QApplication::processEvents();
    
    // Perform export
    bool success = m_excelExporter->exportTransactionsToBilan(fileName);
    
    // Close progress dialog
    progressBox->close();
    delete progressBox;
    
    if (success) {
        // Show success message with option to open file/folder
        QMessageBox msg(this);
        msg.setIcon(QMessageBox::Information);
        msg.setWindowTitle("✅ Export réussi");
        msg.setText("Le Bilan Financier a été exporté avec succès.");
        msg.setInformativeText(QString("Fichier enregistré sous :\\n%1").arg(fileName));
        
        QPushButton *openFileBtn = msg.addButton("📄 Ouvrir le fichier", QMessageBox::ActionRole);
        QPushButton *openFolderBtn = msg.addButton("📂 Ouvrir le dossier", QMessageBox::ActionRole);
        msg.addButton(QMessageBox::Ok);
        
        msg.exec();
        
        if (msg.clickedButton() == openFileBtn) {
            QDesktopServices::openUrl(QUrl::fromLocalFile(fileName));
        } else if (msg.clickedButton() == openFolderBtn) {
            QString folderPath = QFileInfo(fileName).absolutePath();
            QDesktopServices::openUrl(QUrl::fromLocalFile(folderPath));
        }
        
        if (statusBar()) {
            statusBar()->showMessage(QString("✅ Bilan Financier exporté: %1").arg(QFileInfo(fileName).fileName()), 5000);
        }
    } else {
        QMessageBox::critical(this,
            "❌ Erreur d'export",
            "Erreur lors de l'export du Bilan Financier.\\n\\n"
            "Vérifiez que Python et openpyxl sont installés.\\n"
            "Consultez le fichier voltshop_debug.log pour plus de détails.");
    }
}
```

### 3. Rebuild Project

In Qt Creator:
- **Build → Clean All** (Nettoyer tout)
- **Build → Run qmake** (Exécuter qmake)
- **Build → Rebuild All** (Tout recompiler)

### 4. Test the Export

1. Run the application
2. Log in as any user
3. Go to Transaction tab
4. Click "Export to Excel" button
5. Choose save location
6. Excel file will be generated with professional Bilan Financier template

## What's Included in the Bilan Financier

The Excel file contains:
- **Header**: Company name, report date
- **Actifs (Assets)**: Current assets, cash, receivables
- **Passifs (Liabilities)**: Current liabilities, payables
- **Capitaux Propres (Equity)**: Calculated equity
- **Résumé Financier**: Revenue, expenses, net result
- **Payment Method Breakdown**: Transactions grouped by payment method
- **Transaction Details**: Full list of all transactions with formatting

## File Structure

```
Verion_FINALE/
├── excelexporter.h          ✅ Created
├── excelexporter.cpp        ✅ Created
├── mainwindow.h             ✅ Modified (added ExcelExporter member)
├── mainwindow.cpp           ⚠️ NEEDS MANUAL EDIT (replace on_pushButton_27_clicked)
├── Version_F.pro            ✅ Modified (added excelexporter files)
└── python_scripts/
    ├── financial_export.py  ✅ Created
    └── requirements.txt     ✅ Created
```

## Troubleshooting

### Python not found
- Install Python from python.org
- Make sure Python is in PATH
- Test: `python --version` in PowerShell

### openpyxl not installed
```powershell
pip install openpyxl
```

### Script not found error
- Check python_scripts folder exists
- Check financial_export.py exists
- Check path in excelexporter.cpp (should be relative: `../../python_scripts/financial_export.py`)

### No data to export
- Add some transactions in the Transaction tab first
- The export button checks if table has rows

## Features

✅ Professional French accounting "Bilan Financier" template  
✅ Automatic calculations (totals, balances, equity)  
✅ Color-coded sections and styling  
✅ Transaction categorization by status and payment method  
✅ Formatted currency values (DT - Tunisian Dinar)  
✅ Date formatting (DD/MM/YYYY)  
✅ Complete transaction details table  
✅ Opens Excel file automatically after generation  

## Database Query

The export fetches data using:
```sql
SELECT IDT, ID, AMOUNT, PAY_METHOD, TO_CHAR(DATE_TRANS, 'DD/MM/YYYY') AS DATE_TRANS, STATUS 
FROM TAB_TRANS 
ORDER BY DATE_TRANS DESC
```

All transactions are included in the export.
