#ifndef CHATBOTDIALOG_H
#define CHATBOTDIALOG_H

#include <QDialog>
#include <QNetworkAccessManager>
#include "ui_chatbotdialog.h"

namespace Ui {
class chatbotdialog;
}

class ChatBotDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ChatBotDialog(QWidget *parent = nullptr);
    ~ChatBotDialog();

private slots:
    void sendMessage();

private:
    Ui::chatbotdialog *ui;
    QNetworkAccessManager *manager;  // must declare
};

#endif // CHATBOTDIALOG_H
