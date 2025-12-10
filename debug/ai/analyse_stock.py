import os
import sys
import oracledb
import pandas as pd

# ============================================================
# 0) Initialisation du client Oracle
#    Try to initialize the Oracle "thick" client (Instant Client).
#    If that fails, fall back to oracledb "thin" mode (no Instant Client).
#    You can override the Instant Client directory with the
#    environment variable ORACLE_INSTANTCLIENT_DIR.
# ============================================================
lib_dir = os.environ.get("ORACLE_INSTANTCLIENT_DIR", r"C:\oracle\instantclient_21_19")
try:
    oracledb.init_oracle_client(lib_dir=lib_dir)
except Exception as e:
    print(
        f"Warning: Oracle Instant Client init failed (lib_dir={lib_dir}).\n"
        f"Falling back to oracledb thin mode. Error: {e}",
        file=sys.stderr,
    )

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

# Helper: discover join column between TAB_ART and CONCERNER
def discover_join_column(connection):
    cur = connection.cursor()
    try:
        cur.execute("SELECT COLUMN_NAME FROM USER_TAB_COLUMNS WHERE TABLE_NAME = 'CONCERNER'")
        concerner_cols = {r[0] for r in cur.fetchall()}
    except Exception:
        concerner_cols = set()
    try:
        cur.execute("SELECT COLUMN_NAME FROM USER_TAB_COLUMNS WHERE TABLE_NAME = 'TAB_ART'")
        art_cols = {r[0] for r in cur.fetchall()}
    except Exception:
        art_cols = set()

    # prefer obvious common names
    preferred = ['SKU', 'ART_SKU', 'ID_ART', 'REF_ART', 'ARTICLE_SKU', 'PRODUCT_ID']
    for p in preferred:
        if p in concerner_cols and p in art_cols:
            return p

    # otherwise find any intersection (excluding CODE/QTE)
    intersection = (concerner_cols & art_cols) - {'CODE', 'QTE'}
    if intersection:
        # return the most likely (SKU if present else first)
        if 'SKU' in intersection:
            return 'SKU'
        return sorted(intersection)[0]

    return None

# determine join column (uppercase names returned by Oracle)
join_col = discover_join_column(conn)

# ============================================================
# 2) Requête SQL : activité des articles
#    -> nombre de ventes + jours depuis dernière vente
# ============================================================
if join_col:
    # use discovered join column
    sql = f"""
    SELECT a.SKU,
           a.STOCK,
           COUNT(cn.CODE) AS NB_VENTES,
           NVL(TRUNC(SYSDATE - MAX(co.DATE_COMMANDE)), 9999) AS DAYS_SINCE_LAST_SALE
    FROM TAB_ART a
    LEFT JOIN CONCERNER cn ON cn.{join_col} = a.{join_col}
    LEFT JOIN TAB_COMMANDE co ON co.CODE = cn.CODE
    GROUP BY a.SKU, a.STOCK
    ORDER BY a.SKU
    """
else:
    # could not detect a join column: fall back to a safe query (no sales data)
    sql = """
    SELECT a.SKU,
           a.STOCK,
           0 AS NB_VENTES,
           9999 AS DAYS_SINCE_LAST_SALE
    FROM TAB_ART a
    ORDER BY a.SKU
    """

# try executing the SQL; if it fails, fall back to a safe, no-join query
try:
    df = pd.read_sql(sql, conn)
except Exception as e:
    print(f"Warning: main query failed ({e}). Falling back to safe no-join query.", file=sys.stderr)
    safe_sql = """
    SELECT a.SKU,
           a.STOCK,
           0 AS NB_VENTES,
           9999 AS DAYS_SINCE_LAST_SALE
    FROM TAB_ART a
    ORDER BY a.SKU
    """
    df = pd.read_sql(safe_sql, conn)

# On peut fermer la connexion, on a toutes les données
conn.close()

# ============================================================
# 2bis) Sauvegarde brute -> articles_activity.csv
#      (toujours le reflet direct de la base)
# ============================================================
activity_cols = ["SKU", "STOCK", "NB_VENTES", "DAYS_SINCE_LAST_SALE"]
df[activity_cols].to_csv("articles_activity.csv", index=False, encoding="utf-8")

if df.empty:
    print("No article found in database. Empty CSV generated.")
    df.to_csv("articles_classified.csv", index=False, encoding="utf-8")
    raise SystemExit(0)

# ============================================================
# 3) IA basée sur des règles métier (PAS de K-Means)
#
#    Logique simple et justifiable :
#    - Dormant :
#         * aucune vente ET dernier mouvement très ancien
#         * ou dernière vente très ancienne (> 120 jours)
#    - Actif :
#         * ventes récentes et fréquentes
#    - Intermédiaire :
#         * entre les deux (ni complètement mort, ni très dynamique)
# ============================================================

def classify_article(row):
    ventes = int(row["NB_VENTES"])
    days   = int(row["DAYS_SINCE_LAST_SALE"])
    stock  = int(row["STOCK"])

    # ---- Cas 1 : aucun vente enregistrée ----
    # Nouveau produit ou produit jamais vendu
    if ventes == 0:
        # S'il est là depuis longtemps sans vente -> Dormant
        if days >= 60:
            return "Dormant"
        # Sinon on le laisse en Intermédiaire (nouveau, à surveiller)
        return "Intermédiaire"

    # ---- Cas 2 : produit avec ventes récentes et fréquentes -> Actif ----
    # Beaucoup de ventes sur une période récente
    if days <= 30 and ventes >= 2:
        return "Actif"
    # Vente très récente (moins d'une semaine) -> Actif même avec 1 vente
    if days <= 7 and ventes >= 1:
        return "Actif"

    # ---- Cas 3 : produit vendu mais très anciennement -> Dormant ----
    if days > 120:
        return "Dormant"

    # ---- Cas 4 : tout ce qui reste -> Intermédiaire ----
    return "Intermédiaire"


# Application de la règle IA à chaque article
df["CLUSTER_NAME"] = df.apply(classify_article, axis=1)

# ============================================================
# 4) Export final -> articles_classified.csv
# ============================================================
out_cols = ["SKU", "STOCK", "NB_VENTES", "DAYS_SINCE_LAST_SALE", "CLUSTER_NAME"]
df[out_cols].to_csv("articles_classified.csv", index=False, encoding="utf-8")

print("articles_activity.csv and articles_classified.csv updated from ORACLE + rule-based AI.")
    