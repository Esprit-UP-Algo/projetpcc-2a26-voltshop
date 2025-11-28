#ifndef STATS_UTILS_H
#define STATS_UTILS_H

#include <QMap>
#include <QString>

class StatsUtils
{
public:
    // Statistiques des clients par tranches d'âge
    // 18-25 / 25-40 / 40-60 / +60
    static QMap<QString,int> buildClientAgeStats();
};

#endif // STATS_UTILS_H
