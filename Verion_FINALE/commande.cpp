#include "commande.h"
#include "connection.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QTextDocument>
#include <QTextTable>
#include <QPrinter>
#include <QMessageBox>
#include <QDate>
#include <QDateTime>
#include <QTextCursor>


#include <QtMath>
#include <QMap>

Commande::Commande() {}

Commande::Commande(QString code, QDate date_commande, QString produits, double total, QString statut)
{
    this->code = code;
    this->date_commande = date_commande;
    this->produits = produits;
    this->total = total;
    this->statut = statut;
}

bool Commande::ajouter()
{
    // Vérifier que la connexion est ouverte
    Connection& conn = Connection::getInstance();
    if (!conn.getDatabase().isOpen()) {
        qDebug() << "Base de données non connectée";
        return false;
    }
    QSqlQuery query;
    query.prepare("INSERT INTO TAB_COMMANDE (CODE, DATE_COMMANDE, PRODUCTS, TOTAL, STATUS, PSTATUS) "
                  "VALUES (:CODE, :DATE_COMMANDE, :PRODUCTS, :TOTAL, :STATUS, :PSTATUS)");

    query.bindValue(":CODE", code);
    query.bindValue(":DATE_COMMANDE", date_commande);
    query.bindValue(":PRODUCTS", produits);
    query.bindValue(":TOTAL", total);
    query.bindValue(":STATUS", statut);
    query.bindValue(":PSTATUS", pstatus);


    if (!query.exec()) {
        qDebug() << "❌ Erreur ajout commande :" << query.lastError().text();
        qDebug() << "Requête:" << query.lastQuery();
        return false;
    }

    qDebug() << "✅ Commande ajoutée avec succès, code:" << code;
    return true;
}
bool Commande::supprimer(QString code)
{
    Connection& conn = Connection::getInstance();
    if (!conn.getDatabase().isOpen()) {
        qDebug() << "❌ Base de données non connectée";
        return false;
    }

    QSqlDatabase db = conn.getDatabase();
    // Use a transaction to ensure both CONCERNER and TAB_COMMANDE are updated atomically
    if (!db.transaction()) {
        qDebug() << "❌ Failed to start DB transaction:" << db.lastError().text();
        return false;
    }

    QSqlQuery q(db);

    // 1) Delete related lines in CONCERNER (if any)
    if (!q.prepare("DELETE FROM CONCERNER WHERE CODE = :CODE")) {
        qDebug() << "❌ Prepare failed for DELETE CONCERNER:" << q.lastError().text();
        db.rollback();
        return false;
    }
    q.bindValue(":CODE", code);
    if (!q.exec()) {
        qDebug() << "❌ Erreur suppression CONCERNER :" << q.lastError().text();
        db.rollback();
        return false;
    }
    qDebug() << "✅ Suppression CONCERNER - Lignes affectées:" << q.numRowsAffected();

    // 2) Now delete the main order row
    if (!q.prepare("DELETE FROM TAB_COMMANDE WHERE CODE = :CODE")) {
        qDebug() << "❌ Prepare failed for DELETE TAB_COMMANDE:" << q.lastError().text();
        db.rollback();
        return false;
    }
    q.bindValue(":CODE", code);
    if (!q.exec()) {
        qDebug() << "❌ Erreur suppression TAB_COMMANDE :" << q.lastError().text();
        db.rollback();
        return false;
    }

    qDebug() << "✅ Suppression TAB_COMMANDE - Lignes affectées:" << q.numRowsAffected();

    if (!db.commit()) {
        qDebug() << "❌ Commit failed:" << db.lastError().text();
        db.rollback();
        return false;
    }

    return true;
}



QSqlQueryModel* Commande::afficher()
{
    // Vérifier que la connexion est ouverte
    Connection& conn = Connection::getInstance();
    if (!conn.getDatabase().isOpen()) {
        qDebug() << "Base de données non connectée";
        return new QSqlQueryModel(); // Retourne un modèle vide
    }

    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT CODE, DATE_COMMANDE, PRODUCTS, TOTAL, STATUS, PSTATUS FROM TAB_COMMANDE");


    if (model->lastError().isValid()) {
        qDebug() << "❌ Erreur lors de l'affichage:" << model->lastError().text();
    } else {
        qDebug() << "✅ Données chargées, nombre de lignes:" << model->rowCount();
    }

    return model;
}

bool Commande::modifier()
{
    Connection& conn = Connection::getInstance();
    if (!conn.getDatabase().isOpen()) {
        qDebug() << "Base de données non connectée";
        return false;
    }

    QSqlQuery query;
    QString queryStr = "UPDATE TAB_COMMANDE "
                       "SET DATE_COMMANDE = :DATE_COMMANDE, PRODUCTS = :PRODUCTS, "
                       "TOTAL = :TOTAL, STATUS = :STATUS, PSTATUS = :PSTATUS "
                       "WHERE CODE = :CODE";

    // ✅ Préparation de la requête
    if (!query.prepare(queryStr)) {
        qDebug() << "❌ Erreur préparation requête :" << query.lastError().text();
        return false;
    }

    // ✅ Liaison des valeurs
    query.bindValue(":CODE", code);
    query.bindValue(":DATE_COMMANDE", date_commande);
    query.bindValue(":PRODUCTS", produits);
    query.bindValue(":TOTAL", total);
    query.bindValue(":STATUS", statut);
    query.bindValue(":PSTATUS", pstatus);

    // ✅ Exécution
    if (!query.exec()) {
        qDebug() << "❌ Erreur modification commande :" << query.lastError().text();
        return false;
    }

    qDebug() << "✅ Commande mise à jour avec succès, code:" << code;
    return true;
}

bool Commande::updatePstatus(QString code, QString pstatus)
{
    Connection& conn = Connection::getInstance();
    if (!conn.getDatabase().isOpen()) {
        qDebug() << "❌ Base de données non connectée in updatePstatus";
        return false;
    }

    qDebug() << "🔄 updatePstatus called: code=" << code << ", pstatus=" << pstatus;

    QSqlQuery query;
    query.prepare("UPDATE TAB_COMMANDE SET PSTATUS = :PSTATUS WHERE CODE = :CODE");
    query.bindValue(":PSTATUS", pstatus);
    query.bindValue(":CODE", code);

    qDebug() << "🔄 Executing query:" << query.lastQuery();

    if (!query.exec()) {
        qDebug() << "❌ Erreur mise à jour PSTATUS :" << query.lastError().text();
        qDebug() << "❌ Query was:" << query.lastQuery();
        return false;
    }

    int rowsAffected = query.numRowsAffected();
    qDebug() << "✅ Product status updated. Rows affected:" << rowsAffected;
    if (rowsAffected == 0) {
        qDebug() << "⚠️ WARNING: No rows updated! Code may not exist in database:" << code;
    }
    
    return true;
}

int Commande::stat_total_commandes() {
    QSqlQuery query("SELECT COUNT(*) FROM TAB_COMMANDE");
    if (query.next()) {
        int result = query.value(0).toInt();
        qDebug() << "Total commands in TAB_COMMANDE:" << result;
        return result;
    }
    return 0;
}

double Commande::stat_revenu_total() {
    QSqlQuery query("SELECT SUM(TOTAL) FROM TAB_COMMANDE");
    if (query.next()) {
        double result = query.value(0).toDouble();
        qDebug() << "Total revenue in TAB_COMMANDE:" << result;
        return result;
    }
    return 0;
}

QMap<QString, int> Commande::stat_statuts() {
    QMap<QString, int> map;
    QSqlQuery query("SELECT STATUS, COUNT(*) FROM TAB_COMMANDE GROUP BY STATUS");
    qDebug() << "Status statistics from TAB_COMMANDE:";
    while (query.next()) {
        QString st = query.value(0).toString();
        int c = query.value(1).toInt();
        map[st] = c;
        qDebug() << " - " << st << ":" << c;
    }
    return map;
}

QMap<QString, int> Commande::stat_par_mois() {
    QMap<QString, int> map;
    QSqlQuery query("SELECT TO_CHAR(DATE_COMMANDE, 'MM'), COUNT(*) FROM TAB_COMMANDE GROUP BY TO_CHAR(DATE_COMMANDE, 'MM') ORDER BY TO_CHAR(DATE_COMMANDE, 'MM')");

    qDebug() << "Month statistics from TAB_COMMANDE:";
    if (query.lastError().isValid()) {
        qDebug() << "Error in month query:" << query.lastError().text();
        return map;
    }

    while (query.next()) {
        QString mois = query.value(0).toString();
        int count = query.value(1).toInt();
        map[mois] = count;
        qDebug() << " - Month" << mois << ":" << count << "commands";
    }
    return map;
}







Location Commande::getCoordinate(QString name)
{
    QString normalized = name.toLower().trimmed();

    static QMap<QString, Location> map = {

    // ==================== TUNIS - QUARTIERS (PRÉCIS) ====================
    {"centre ville tunis", {"Centre Ville Tunis", 36.7989, 10.1655}},
        {"bab bhar", {"Bab Bhar", 36.7972, 10.1750}},
        {"bab souika", {"Bab Souika", 36.8028, 10.1683}},
        {"bardo", {"Bardo", 36.8092, 10.1394}},
        {"cite el khadra", {"Cité El Khadra", 36.8286, 10.1114}},
        {"el menzah", {"El Menzah", 36.8421, 10.1673}},
        {"el menzah 1", {"El Menzah 1", 36.8421, 10.1673}},
        {"el menzah 2", {"El Menzah 2", 36.8450, 10.1720}},
        {"el menzah 3", {"El Menzah 3", 36.8480, 10.1750}},
        {"el menzah 4", {"El Menzah 4", 36.8510, 10.1780}},
        {"el menzah 5", {"El Menzah 5", 36.8540, 10.1810}},
        {"el menzah 6", {"El Menzah 6", 36.8570, 10.1840}},
        {"el omrane", {"El Omrane", 36.8097, 10.1701}},
        {"ezzahrouni", {"Ezzahrouni", 36.8150, 10.1250}},
        {"khereddine", {"Khereddine", 36.8361, 10.1019}},
        {"lac", {"Lac", 36.8389, 10.2436}},
        {"lac 1", {"Lac 1", 36.8389, 10.2436}},
        {"lac 2", {"Lac 2", 36.8420, 10.2470}},
        {"berges du lac", {"Berges du Lac", 36.8400, 10.2500}},
        {"le belvedere", {"Le Belvédère", 36.8236, 10.1797}},
        {"montplaisir", {"Montplaisir", 36.8380, 10.2080}},
        {"mutuelleville", {"Mutuelleville", 36.8374, 10.1781}},
        {"passage", {"Passage", 36.8069, 10.1819}},

        // ==================== TUNIS - BANLIEUES NORD ====================
        {"la marsa", {"La Marsa", 36.8782, 10.3239}},
        {"carthage", {"Carthage", 36.8614, 10.3319}},
        {"sidi bou said", {"Sidi Bou Said", 36.8689, 10.3417}},
        {"gamarth", {"Gammarth", 36.8989, 10.3050}},
        {"gammarth", {"Gammarth", 36.8989, 10.3050}},
        {"salambo", {"Salammbô", 36.8450, 10.3150}},
        {"amilcar", {"Amilcar", 36.8550, 10.3250}},

        // ==================== TUNIS - BANLIEUES SUD ====================
        {"megrine", {"Mégrine", 36.7700, 10.2350}},
        {"megrine coteau", {"Mégrine Coteau", 36.7750, 10.2250}},
        {"rades", {"Radès", 36.7681, 10.2750}},
        {"hammam lif", {"Hammam Lif", 36.7300, 10.3417}},
        {"hammam chott", {"Hammam Chott", 36.7150, 10.3350}},
        {"borj cedria", {"Borj Cedria", 36.7167, 10.4333}},
        {"mohamadia", {"Mohamadia", 36.6764, 10.1567}},

        // ==================== ARIANA - QUARTIERS ====================
        {"ariana ville", {"Ariana Ville", 36.8625, 10.1956}},
        {"ariana sup", {"Ariana Sup", 36.8550, 10.1850}},
        {"cite el ghazala", {"Cité El Ghazala", 36.8990, 10.1890}},
        {"el ghazala", {"El Ghazala", 36.8990, 10.1890}},
        {"cite ennasr", {"Cité Ennasr", 36.8623, 10.1688}},
        {"ennasr", {"Cité Ennasr", 36.8623, 10.1688}},
        {"ennasr 1", {"Ennasr 1", 36.8650, 10.1700}},
        {"ennasr 2", {"Ennasr 2", 36.8680, 10.1730}},
        {"chotrana", {"Chotrana", 36.8500, 10.2000}},
        {"chotrana 1", {"Chotrana 1", 36.8480, 10.1980}},
        {"chotrana 2", {"Chotrana 2", 36.8460, 10.2020}},
        {"riadh andalous", {"Riadh Andalous", 36.8300, 10.2100}},
        {"nasr", {"Nasr", 36.8650, 10.1750}},
        {"la soukra", {"La Soukra", 36.8800, 10.2500}},
        {"sidi thabet", {"Sidi Thabet", 36.9000, 10.1000}},
        {"kalâat el andalous", {"Kalâat el Andalous", 36.8964, 10.1917}},
        {"ettadhamen", {"Ettadhamen", 36.8333, 10.1000}},
        {"douar hicher", {"Douar Hicher", 36.8167, 10.1167}},

        // ==================== BEN AROUS - QUARTIERS ====================
        {"ben arous ville", {"Ben Arous Ville", 36.7435, 10.2317}},
        {"mourouj", {"Mourouj", 36.7211, 10.2152}},
        {"mourouj 1", {"Mourouj 1", 36.7130, 10.2120}},
        {"mourouj 2", {"Mourouj 2", 36.7160, 10.2180}},
        {"mourouj 3", {"Mourouj 3", 36.7205, 10.2231}},
        {"mourouj 4", {"Mourouj 4", 36.7230, 10.2280}},
        {"mourouj 5", {"Mourouj 5", 36.7260, 10.2330}},
        {"mourouj 6", {"Mourouj 6", 36.7290, 10.2380}},
        {"mourouj 7", {"Mourouj 7", 36.7320, 10.2430}},
        {"el mourouj", {"El Mourouj", 36.7211, 10.2152}},
        {"ezzahra", {"Ezzahra", 36.7417, 10.3000}},
        {"fouchana", {"Fouchana", 36.7000, 10.1833}},
        {"mornag", {"Mornag", 36.6800, 10.2833}},

        // ==================== MANOUBA - QUARTIERS ====================
        {"manouba ville", {"Manouba Ville", 36.8106, 10.0973}},
        {"den den", {"Den Den", 36.8333, 10.1000}},
        {"el battan", {"El Battan", 36.7833, 10.1500}},
        {"jedaida", {"Jedaida", 36.8500, 10.0333}},
        {"mornaguia", {"Mornaguia", 36.7500, 10.0167}},
        {"oued ellil", {"Oued Ellil", 36.8333, 10.0500}},
        {"tebourba", {"Tebourba", 36.9500, 9.8333}},

        // ==================== NABEUL - LIEUX PRINCIPAUX ====================
        {"nabeul ville", {"Nabeul Ville", 36.4560, 10.7376}},
        {"hammamet", {"Hammamet", 36.4000, 10.6167}},
        {"dar chaabane", {"Dar Chaabane", 36.4667, 10.7500}},
        {"beni khiar", {"Beni Khiar", 36.4667, 10.7833}},
        {"grombalia", {"Grombalia", 36.6000, 10.5000}},
        {"kelibia", {"Kélibia", 36.8472, 11.0939}},
        {"korba", {"Korba", 36.5786, 10.8586}},
        {"mida", {"Mida", 36.4500, 10.8333}},
        {"soliman", {"Soliman", 36.6961, 10.4922}},

        // ==================== SOUSSE - LIEUX PRINCIPAUX ====================
        {"sousse ville", {"Sousse Ville", 35.8256, 10.6369}},
        {"sousse medina", {"Sousse Médina", 35.8272, 10.6389}},
        {"sahloul", {"Sahloul", 35.8500, 10.5833}},
        {"ksibet el mediouni", {"Ksibet El Mediouni", 35.6833, 10.8500}},
        {"msaken", {"Msaken", 35.7333, 10.5833}},
        {"akouda", {"Akouda", 35.8694, 10.5681}},
        {"hammam sousse", {"Hammam Sousse", 35.8583, 10.5931}},
        {"kalaa kebira", {"Kalaa Kebira", 35.8667, 10.5333}},
        {"kalaa seghira", {"Kalaa Seghira", 35.8167, 10.5833}},
        {"messaadine", {"Messaadine", 35.8333, 10.6333}},
        {"bouficha", {"Bouficha", 36.3333, 10.4667}},
        {"ennfidha", {"Ennfidha", 36.1333, 10.3833}},
        {"port el kantaoui", {"Port El Kantaoui", 35.8917, 10.5931}},

        // ==================== MONASTIR - LIEUX PRINCIPAUX ====================
        {"monastir ville", {"Monastir Ville", 35.7833, 10.8333}},
        {"jemmel", {"Jemmel", 35.6333, 10.7667}},
        {"moknine", {"Moknine", 35.6306, 10.9917}},
        {"sahline", {"Sahline", 35.7500, 10.7167}},
        {"téboulba", {"Téboulba", 35.6403, 10.9619}},
        {"bekalta", {"Bekalta", 35.6167, 10.9833}},
        {"ksar hellal", {"Ksar Hellal", 35.6500, 10.9000}},
        {"ouardanine", {"Ouardanine", 35.7167, 10.6667}},

        // ==================== MAHDIA - LIEUX PRINCIPAUX ====================
        {"mahdia ville", {"Mahdia Ville", 35.5047, 11.0622}},
        {"chebba", {"Chebba", 35.2333, 11.1167}},
        {"hibrun", {"Hibrun", 35.3833, 11.0500}},
        {"ksour essaf", {"Ksour Essaf", 35.4167, 11.0000}},
        {"mellouleche", {"Mellouleche", 35.1667, 11.0333}},

        // ==================== SFAX - LIEUX PRINCIPAUX ====================
        {"sfax ville", {"Sfax Ville", 34.7406, 10.7603}},
        {"sakiet ezzit", {"Sakiet Ezzit", 34.7500, 10.7833}},
        {"sakiet eddaier", {"Sakiet Eddaier", 34.7333, 10.7500}},
        {"agareb", {"Agareb", 34.7333, 10.5167}},
        {"djebeniana", {"Djebeniana", 35.0333, 10.9167}},
        {"el hencha", {"El Hencha", 34.9333, 10.6833}},
        {"gremda", {"Gremda", 34.7167, 10.7833}},
        {"mahres", {"Mahres", 34.5333, 10.5000}},

        // ==================== KAIROUAN - LIEUX PRINCIPAUX ====================
        {"kairouan ville", {"Kairouan Ville", 35.6781, 10.0967}},
        {"haffouz", {"Haffouz", 35.6333, 9.6833}},
        {"ousseltia", {"Ousseltia", 35.8667, 9.5333}},
        {"sbikha", {"Sbikha", 35.9333, 10.0167}},

        // ==================== BIZERTE - LIEUX PRINCIPAUX ====================
        {"bizerte ville", {"Bizerte Ville", 37.2744, 9.8739}},
        {"menzel bourguiba", {"Menzel Bourguiba", 37.1536, 9.7879}},
        {"menzel jemil", {"Menzel Jemil", 37.2333, 9.9167}},
        {"ras jebel", {"Ras Jebel", 37.2167, 10.1167}},
        {"mateur", {"Mateur", 37.0406, 9.6656}},
        {"sedjnane", {"Sedjnane", 37.0500, 9.2333}},

        // ==================== AUTRES VILLES IMPORTANTES ====================
        // JENDOUBA
        {"jendouba ville", {"Jendouba Ville", 36.5012, 8.7806}},
        {"ain drahem", {"Aïn Drahem", 36.7750, 8.6917}},
        {"bou salem", {"Bou Salem", 36.6167, 8.9667}},
        {"fernana", {"Fernana", 36.6550, 8.6961}},
        {"ghardimaou", {"Ghardimaou", 36.4500, 8.4333}},

        // LE KEF
        {"le kef ville", {"Le Kef Ville", 36.1822, 8.7147}},
        {"dahmani", {"Dahmani", 35.9500, 8.8333}},
        {"jerissa", {"Jerissa", 35.9000, 8.5833}},
        {"sakiet sidi youssef", {"Sakiet Sidi Youssef", 36.2222, 8.3556}},
        {"tajerouine", {"Tajerouine", 35.8833, 8.5500}},

        // BEJA
        {"beja ville", {"Béja Ville", 36.7256, 9.1817}},
        {"goubellat", {"Goubellat", 36.5500, 9.6667}},
        {"medjez el beb", {"Medjez el Beb", 36.6500, 9.6000}},
        {"nefza", {"Nefza", 36.1333, 9.2000}},
        {"téboursouk", {"Téboursouk", 36.4500, 9.2500}},
        {"testour", {"Testour", 36.5500, 9.4500}},

        // GABES
        {"gabes ville", {"Gabès Ville", 33.8814, 10.0983}},
        {"ghannouch", {"Ghannouch", 33.9500, 10.0667}},
        {"matmata", {"Matmata", 33.5447, 9.9744}},
        {"mareth", {"Mareth", 33.6333, 10.2833}},

        // MEDENINE
        {"medenine ville", {"Médenine Ville", 33.3547, 10.5053}},
        {"ben guerdane", {"Ben Guerdane", 33.1333, 11.2167}},
        {"djerba", {"Djerba", 33.8667, 10.8500}},
        {"houmt souk", {"Houmt Souk", 33.8747, 10.8572}},
        {"midoun", {"Midoun", 33.8083, 10.9950}},
        {"zarzis", {"Zarzis", 33.5000, 11.1167}},

        // GAFSA
        {"gafsa ville", {"Gafsa Ville", 34.4250, 8.7842}},
        {"el guettar", {"El Guettar", 34.3333, 8.9500}},
        {"metlaoui", {"Metlaoui", 34.3208, 8.4011}},
        {"moularès", {"Moularès", 34.5333, 8.5667}},
        {"redeyef", {"Redeyef", 34.3833, 8.1500}},

        // TOZEUR
        {"tozeur ville", {"Tozeur Ville", 33.9197, 8.1336}},
        {"nefta", {"Nefta", 33.8739, 7.8778}},

        // KEBILI
        {"kebili ville", {"Kébili Ville", 33.7044, 8.9694}},
    {"douz", {"Douz", 33.4667, 9.0167}}
    // ... [votre map complète reste inchangée] ...
};

// 🔍 RECHERCHE AMÉLIORÉE
// 1. Recherche exacte
if (map.contains(normalized)) {
    qDebug() << "[BASE] Trouvé exactement:" << normalized << "->" << map[normalized].name;
    return map[normalized];
}

// 2. Recherche avec espaces et tirets
QString normalizedWithSpaces = normalized;
normalizedWithSpaces.replace("-", " ");

if (map.contains(normalizedWithSpaces)) {
    qDebug() << "[BASE] Trouvé avec espaces:" << normalizedWithSpaces;
    return map[normalizedWithSpaces];
}

// 3. Recherche par mots-clés - CORRECTION ICI :
// ⚠️ REMPLACEZ QRegExp par QRegularExpression
QStringList searchTerms = normalized.split(QRegularExpression("[\\s,-]+"), Qt::SkipEmptyParts);

// Priorité aux termes longs
std::sort(searchTerms.begin(), searchTerms.end(),
          [](const QString &a, const QString &b) { return a.length() > b.length(); });

for (const QString &term : searchTerms) {
    if (term.length() > 2) {
        for (auto it = map.begin(); it != map.end(); ++it) {
            if (it.key().contains(term, Qt::CaseInsensitive)) {
                qDebug() << "[BASE] Trouvé par mot-clé:" << term << "->" << it.key();
                return it.value();
            }
        }
    }
}

qDebug() << "[BASE] Aucune correspondance pour:" << normalized;
return {"Unknown", 0, 0};
}
double Commande::calculateDistance(Location a, Location b)
{
    // ⚠ CORRECTION : Formule Haversine pour les distances réelles
    const double R = 6371.0; // Rayon de la Terre en km
    double lat1 = a.latitude * M_PI / 180.0;
    double lat2 = b.latitude * M_PI / 180.0;
    double dLat = (b.latitude - a.latitude) * M_PI / 180.0;
    double dLon = (b.longitude - a.longitude) * M_PI / 180.0;

    double x = qSin(dLat/2) * qSin(dLat/2) +
               qCos(lat1) * qCos(lat2) *
                   qSin(dLon/2) * qSin(dLon/2);
    double y = 2 * qAtan2(qSqrt(x), qSqrt(1-x));

    return R * y; // Distance en km
}






