import oracledb
import pandas as pd
from sklearn.cluster import KMeans
import numpy as np

# ============================================================
# 0) Initialisation du client Oracle
#    ⚠️ Garde EXACTEMENT ce chemin qui marche chez toi
# ============================================================
oracledb.init_oracle_client(lib_dir=r"C:\oracle\instantclient_21_19")

# ============================================================
# 1) Connexion Oracle
# ============================================================
USERNAME = "HOUSSEM"
PASSWORD = "esprit25"
HOST     = "localhost"
PORT     = 1521
SERVICE  = "XE"

dsn = (
    f"(DESCRIPTION="
    f"(ADDRESS=(PROTOCOL=TCP)(HOST={HOST})(PORT={PORT}))"
    f"(CONNECT_DATA=(SERVICE_NAME={SERVICE}))"
    f")"
)

conn = oracledb.connect(user=USERNAME, password=PASSWORD, dsn=dsn)

# ============================================================
# 2) Requête SQL : activité des articles
#    NB_VENTES = nb de commandes contenant l’article
#    DAYS_SINCE_LAST_SALE = jours depuis la dernière commande
# ============================================================
sql = """
SELECT a.SKU,
       a.STOCK,
       COUNT(cn.CODE) AS NB_VENTES,
       NVL(TRUNC(SYSDATE - MAX(co.DATE_COMMANDE)), 9999) AS DAYS_SINCE_LAST_SALE
FROM TAB_ART a
LEFT JOIN CONCERNER cn ON cn.SKU = a.SKU
LEFT JOIN TAB_COMMANDE co ON co.CODE = cn.CODE
GROUP BY a.SKU, a.STOCK
ORDER BY a.SKU
"""

df = pd.read_sql(sql, conn)

# On peut fermer la connexion, on a toutes les données
conn.close()

# ============================================================
# 2bis) Sauvegarde brute -> articles_activity.csv
#      (toujours le reflet direct de la base)
# ============================================================
activity_cols = ["SKU", "STOCK", "NB_VENTES", "DAYS_SINCE_LAST_SALE"]
df[activity_cols].to_csv("articles_activity.csv", index=False, encoding="utf-8")

if df.empty:
    print("Aucun article trouvé dans la base.")
    # on met quand même un classified vide
    df.to_csv("articles_classified.csv", index=False, encoding="utf-8")
    raise SystemExit(0)

# ============================================================
# 3) Préparation des données pour KMeans
#    Features = [STOCK, NB_VENTES, DAYS_SINCE_LAST_SALE]
# ============================================================
features = df[["STOCK", "NB_VENTES", "DAYS_SINCE_LAST_SALE"]].astype(float)

# Si on a moins de 3 articles, on adapte le nombre de clusters
n_clusters = 3 if len(df) >= 3 else len(df)

kmeans = KMeans(n_clusters=n_clusters, n_init=10, random_state=42)
df["CLUSTER"] = kmeans.fit_predict(features)

# ============================================================
# 4) Traduire les clusters en labels lisibles
#    On calcule un SCORE d’activité :
#      SCORE = NB_VENTES - (DAYS_SINCE_LAST_SALE / 30)
#    Plus le score est grand -> plus l’article est ACTIF
# ============================================================
centers = pd.DataFrame(
    kmeans.cluster_centers_,
    columns=["STOCK", "NB_VENTES", "DAYS_SINCE_LAST_SALE"]
)
centers["CLUSTER"] = centers.index

centers["SCORE"] = centers["NB_VENTES"] - centers["DAYS_SINCE_LAST_SALE"] / 30.0
centers = centers.sort_values("SCORE")

labels = [
    "Dormant (vendu très rarement)",
    "Intermédiaire",
    "Actif (ventes régulières)"
]

cluster_to_name = {}
for i, (_, row) in enumerate(centers.iterrows()):
    cluster_to_name[int(row["CLUSTER"])] = labels[i]

df["CLUSTER_NAME"] = df["CLUSTER"].map(cluster_to_name)

# ============================================================
# 5) Export final -> articles_classified.csv
# ============================================================
out_cols = ["SKU", "STOCK", "NB_VENTES", "DAYS_SINCE_LAST_SALE", "CLUSTER_NAME"]
df[out_cols].to_csv("articles_classified.csv", index=False, encoding="utf-8")

print("✅ articles_activity.csv et articles_classified.csv mis à jour (ORACLE + K-Means).")










