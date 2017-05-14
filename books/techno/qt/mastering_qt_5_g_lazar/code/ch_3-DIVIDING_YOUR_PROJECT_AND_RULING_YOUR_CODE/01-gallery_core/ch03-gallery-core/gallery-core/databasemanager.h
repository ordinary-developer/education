#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include "albumdao.h"
#include "picturedao.h"

#include <QString>

class QSqlDatabase;
const QString DATABASE_FILENAME = "gallery.db";


class DatabaseManager
{
public:
    static DatabaseManager& instance();
    ~DatabaseManager();

protected:
    DatabaseManager(QString const& path = DATABASE_FILENAME);
    DatabaseManager& operator=(DatabaseManager const& rhs);

private:
    QSqlDatabase* mDatabase;

public:
    const AlbumDao albumDao;
    const PictureDao pictureDao;
};

#endif // DATABASEMANAGER_H
