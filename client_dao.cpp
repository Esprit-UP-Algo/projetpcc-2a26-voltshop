#include "client_dao.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QRegularExpression>

// ==========================================
//    FONCTION DE VALIDATION DES DONNÉES
// ==========================================

bool ClientDAO::validateClient(const Client& c, QString& errorMessage) {
    // 1. Vérifier que le CIN n'est pas vide
    if (c.CIN.trimmed().isEmpty()) {
        errorMessage = "❌ Le CIN est obligatoire.";
        return false;
    }

    // 2. Vérifier que le CIN contient exactement 8 chiffres
    QRegularExpression cinRegex("^[0-9]{8}$");
    if (!cinRegex.match(c.CIN.trimmed()).hasMatch()) {
        errorMessage = "❌ Le CIN doit contenir exactement 8 chiffres.\nExemple : 12345678";
        return false;
    }

    // 3. Vérifier que le prénom n'est pas vide
    if (c.FIRST_NAME.trimmed().isEmpty()) {
        errorMessage = "❌ Le prénom est obligatoire.";
        return false;
    }

    // 4. Vérifier que le prénom contient uniquement des lettres
    QRegularExpression nameRegex("^[a-zA-ZÀ-ÿ\\s-]{2,50}$");
    if (!nameRegex.match(c.FIRST_NAME.trimmed()).hasMatch()) {
        errorMessage = "❌ Le prénom doit contenir uniquement des lettres (2-50 caractères).\nExemple : Ahmed, Marie-Claire";
        return false;
    }

    // 5. Vérifier que le nom n'est pas vide
    if (c.LAST_NAME.trimmed().isEmpty()) {
        errorMessage = "❌ Le nom est obligatoire.";
        return false;
    }

    // 6. Vérifier que le nom contient uniquement des lettres
    if (!nameRegex.match(c.LAST_NAME.trimmed()).hasMatch()) {
        errorMessage = "❌ Le nom doit contenir uniquement des lettres (2-50 caractères).\nExemple : Ben Ali, Dupont";
        return false;
    }

    // 7. Vérifier que l'email n'est pas vide
    if (c.EMAIL.trimmed().isEmpty()) {
        errorMessage = "❌ L'email est obligatoire.";
        return false;
    }

    // 8. Vérifier le format de l'email
    QRegularExpression emailRegex("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$");
    if (!emailRegex.match(c.EMAIL.trimmed()).hasMatch()) {
        errorMessage = "❌ Format d'email invalide.\nExemple : exemple@email.com";
        return false;
    }

    // 9. Vérifier que le numéro de téléphone n'est pas vide
    if (c.PHONE_NBR.trimmed().isEmpty()) {
        errorMessage = "❌ Le numéro de téléphone est obligatoire.";
        return false;
    }

    // 10. Vérifier le format du numéro de téléphone (8 chiffres ou format international)
    QRegularExpression phoneRegex("^(\\+216)?[0-9]{8}$");
    if (!phoneRegex.match(c.PHONE_NBR.trimmed().replace(" ", "")).hasMatch()) {
        errorMessage = "❌ Format de téléphone invalide.\nExemple : 12345678 ou +21612345678";
        return false;
    }

    // 11. Vérifier que l'adresse n'est pas vide
    if (c.ADRESS.trimmed().isEmpty()) {
        errorMessage = "❌ L'adresse est obligatoire.";
        return false;
    }

    // 12. Vérifier que l'adresse a une longueur minimale
    if (c.ADRESS.trimmed().length() < 5) {
        errorMessage = "❌ L'adresse doit contenir au moins 5 caractères.";
        return false;
    }

    // Toutes les validations ont réussi
    return true;
}

// ==========================================
//    CREATE - AVEC VALIDATION
// ==========================================

bool ClientDAO::create(const Client& c) {
    // Valider les données avant l'insertion
    QString errorMessage;
    if (!validateClient(c, errorMessage)) {
        QMessageBox::warning(nullptr, "Validation échouée", errorMessage);
        return false;
    }

    QSqlQuery q;
    q.prepare(R"(
        INSERT INTO TAB_CLIENT
            (CIN, FIRST_NAME, LAST_NAME, EMAIL, PHONE_NBR, ADRESS)
        VALUES (:cin, :fn, :ln, :em, :ph, :ad)
    )");
    q.bindValue(":cin", c.CIN.trimmed());
    q.bindValue(":fn",  c.FIRST_NAME.trimmed());
    q.bindValue(":ln",  c.LAST_NAME.trimmed());
    q.bindValue(":em",  c.EMAIL.trimmed());
    q.bindValue(":ph",  c.PHONE_NBR.trimmed());
    q.bindValue(":ad",  c.ADRESS.trimmed());

    auto db = QSqlDatabase::database();
    db.transaction();
    const bool ok = q.exec();

    if (ok) {
        db.commit();
        QMessageBox::information(nullptr, "✅ Succès",
                                 "Le client a été ajouté avec succès !");
    } else {
        db.rollback();
        QMessageBox::critical(nullptr, "❌ Erreur",
                              QString("Erreur lors de l'ajout : %1").arg(q.lastError().text()));
    }

    return ok;
}

// ==========================================
//    UPDATE - AVEC VALIDATION
// ==========================================

bool ClientDAO::update(const Client& c) {
    // Valider les données avant la mise à jour
    QString errorMessage;
    if (!validateClient(c, errorMessage)) {
        QMessageBox::warning(nullptr, "Validation échouée", errorMessage);
        return false;
    }

    // Vérifier si le client existe
    if (!exists(c.CIN)) {
        QMessageBox::warning(nullptr, "Client introuvable",
                             QString("Aucun client avec le CIN '%1' n'existe.").arg(c.CIN));
        return false;
    }

    QSqlQuery q;
    q.prepare(R"(
        UPDATE TAB_CLIENT
           SET FIRST_NAME = :fn,
               LAST_NAME  = :ln,
               EMAIL      = :em,
               PHONE_NBR  = :ph,
               ADRESS     = :ad
         WHERE CIN        = :cin
    )");
    q.bindValue(":fn",  c.FIRST_NAME.trimmed());
    q.bindValue(":ln",  c.LAST_NAME.trimmed());
    q.bindValue(":em",  c.EMAIL.trimmed());
    q.bindValue(":ph",  c.PHONE_NBR.trimmed());
    q.bindValue(":ad",  c.ADRESS.trimmed());
    q.bindValue(":cin", c.CIN.trimmed());

    auto db = QSqlDatabase::database();
    db.transaction();
    const bool ok = q.exec();

    if (ok) {
        db.commit();
        QMessageBox::information(nullptr, "✅ Succès",
                                 "Le client a été modifié avec succès !");
    } else {
        db.rollback();
        QMessageBox::critical(nullptr, "❌ Erreur",
                              QString("Erreur lors de la modification : %1").arg(q.lastError().text()));
    }

    return ok;
}

// ==========================================
//    REMOVE - AVEC VÉRIFICATION
// ==========================================

bool ClientDAO::remove(const QString& cin) {
    // Vérifier que le CIN n'est pas vide
    if (cin.trimmed().isEmpty()) {
        QMessageBox::warning(nullptr, "CIN vide",
                             "Veuillez entrer un CIN à supprimer.");
        return false;
    }

    // Vérifier si le client existe
    if (!exists(cin)) {
        QMessageBox::warning(nullptr, "❌ Client introuvable",
                             QString("Aucun client avec le CIN '%1' n'a été trouvé dans la base de données.").arg(cin));
        return false;
    }

    QSqlQuery q;
    q.prepare("DELETE FROM TAB_CLIENT WHERE CIN=:cin");
    q.bindValue(":cin", cin.trimmed());

    auto db = QSqlDatabase::database();
    db.transaction();
    const bool ok = q.exec();

    if (ok) {
        db.commit();
        QMessageBox::information(nullptr, "✅ Succès",
                                 QString("Le client avec le CIN '%1' a été supprimé avec succès.").arg(cin));
    } else {
        db.rollback();
        QMessageBox::critical(nullptr, "❌ Erreur",
                              QString("Erreur lors de la suppression : %1").arg(q.lastError().text()));
    }

    return ok;
}

// ==========================================
//    EXISTS
// ==========================================

bool ClientDAO::exists(const QString& cin) {
    QSqlQuery q;
    q.prepare("SELECT 1 FROM TAB_CLIENT WHERE CIN=:cin");
    q.bindValue(":cin", cin.trimmed());
    return q.exec() && q.next();
}

// ==========================================
//    FETCH ALL
// ==========================================

QVector<Client> ClientDAO::fetchAll() {
    QVector<Client> out;
    QSqlQuery q(R"(
        SELECT CIN, FIRST_NAME, LAST_NAME, EMAIL, PHONE_NBR, ADRESS
          FROM TAB_CLIENT
         ORDER BY CIN
    )");
    while (q.next()) {
        Client c;
        c.CIN        = q.value(0).toString();
        c.FIRST_NAME = q.value(1).toString();
        c.LAST_NAME  = q.value(2).toString();
        c.EMAIL      = q.value(3).toString();
        c.PHONE_NBR  = q.value(4).toString();
        c.ADRESS     = q.value(5).toString();
        out.push_back(c);
    }
    return out;
}
