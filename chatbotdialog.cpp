#include "chatbotdialog.h"
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QMessageBox>

#define MISTRAL_API_KEY "9aCfi4vFPBCCljc5nxTd4k5EwrzHaMpY"  // Replace with your Mistral key

ChatBotDialog::ChatBotDialog(QWidget *parent)
    : QDialog(parent),
    ui(new Ui::chatbotdialog)   // MUST MATCH the generated class
{
    ui->setupUi(this);

    // ✅ Initialize the network manager
    manager = new QNetworkAccessManager(this);

    // ✅ Connect send button
    connect(ui->sendBtn, &QPushButton::clicked, this, &ChatBotDialog::sendMessage);
}

ChatBotDialog::~ChatBotDialog()
{
    delete ui;
}

void ChatBotDialog::sendMessage()
{
    QString userInput = ui->inputBox->text().trimmed();
    if(userInput.isEmpty()) return;

    ui->chatView->append("🟩 You: " + userInput);
    ui->inputBox->clear();

    // Build JSON payload
    QJsonObject json;
    json["model"] = "mistral-small-latest";

    QJsonArray messages;

    // Add system instruction with VoltShop project context
    QJsonObject systemMsg;
    systemMsg["role"] = "system";
    systemMsg["content"] = "You are an assistant that only answers questions about the VoltShop project. "
                           "VoltShop is an application to modernize electronics store management in Tunisia, "
                           "centralizing products, clients, employees, and sales information. "
                           "It has several modules: Clients (CRUD, loyalty system, statistics), "
                           "Orders (CRUD, tracking, suggestions), Stock & Parts (CRUD, export, analytics), "
                           "Payments (CRUD, statistics, fraud detection), Service After-Sales (SAV) "
                           "(requests management, tracking, reporting). "
                           "UI is developed in Qt with a focus on usability, security, and performance. "
                           "If asked about unrelated topics, respond: 'I can only answer questions about the VoltShop project.'";
    messages.append(systemMsg);

    // Add user's actual message
    QJsonObject userMsg;
    userMsg["role"] = "user";
    userMsg["content"] = userInput;
    messages.append(userMsg);

    json["messages"] = messages;

    QNetworkRequest request(QUrl("https://api.mistral.ai/v1/chat/completions"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader("Authorization", "Bearer " MISTRAL_API_KEY);

    QNetworkReply* reply = manager->post(request, QJsonDocument(json).toJson());

    connect(reply, &QNetworkReply::finished, [=]() {
        QByteArray data = reply->readAll();
        QJsonDocument doc = QJsonDocument::fromJson(data);

        if(!doc.isObject()) {
            ui->chatView->append("❌ Error parsing response");
            reply->deleteLater();
            return;
        }

        QJsonObject obj = doc.object();
        QJsonArray choices = obj["choices"].toArray();
        if(!choices.isEmpty()) {
            QJsonObject first = choices[0].toObject();
            QJsonObject message = first["message"].toObject();
            QString botReply = message["content"].toString();
            ui->chatView->append("🤖 Bot: " + botReply);
        }

        reply->deleteLater();
    });
}

