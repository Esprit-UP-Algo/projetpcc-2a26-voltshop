#ifndef QRDIALOG_H
#define QRDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

class QrDialog : public QDialog {
    Q_OBJECT
public:
    explicit QrDialog(const QString &chartUrl, const QString &secret, const QString &otpUrl, QWidget *parent = nullptr);
    ~QrDialog();

private:
    QLabel *imgLabel;
    QLabel *secretLabel;
    QPushButton *okButton;
    QString m_otpUrl;
};

#endif // QRDIALOG_H
