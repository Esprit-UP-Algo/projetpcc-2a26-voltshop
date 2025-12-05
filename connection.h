#ifndef CONNECTION_H
#define CONNECTION_H

#include <QSqlDatabase>

class Connection {
public:
    static Connection& getInstance(); // retourne l'instance unique
    bool openConnection();
    void closeConnection();
    QSqlDatabase getDatabase();


private:
    Connection(); // constructeur privé
    ~Connection(); // destructeur privé
    Connection(const Connection&) = delete;
    Connection& operator=(const Connection&) = delete;

    QSqlDatabase db;
};

#endif // CONNECTION_H
