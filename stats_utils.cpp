#include "stats_utils.h"
#include "client_dao.h"   // pour client_dao::fetchAll()

QMap<QString,int> StatsUtils::buildClientAgeStats()
{
    QMap<QString,int> stats;

    int age18_25  = 0;
    int age25_40  = 0;
    int age40_60  = 0;
    int age60plus = 0;

    const auto rows = client_dao::fetchAll();

    for (const auto &c : rows)
    {
        int age = c.AGE;   // ⚠️ ton champ dans la classe Client

        if (age >= 18 && age <= 25)
            age18_25++;
        else if (age > 25 && age <= 40)
            age25_40++;
        else if (age > 40 && age <= 60)
            age40_60++;
        else if (age > 60)
            age60plus++;
    }

    stats["18-25"] = age18_25;
    stats["25-40"] = age25_40;
    stats["40-60"] = age40_60;
    stats["+60"]   = age60plus;

    return stats;
}
