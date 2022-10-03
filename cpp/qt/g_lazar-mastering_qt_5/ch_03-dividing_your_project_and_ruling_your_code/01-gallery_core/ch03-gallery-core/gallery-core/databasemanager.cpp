#include "databasemanager.h"

#include <QSqlDatabase>

DatabaseManager& DatabaseManager::instance()
{
    static DatabaseManager singleton{};
    return singleton;
}

DatabaseManager::DatabaseManager(QString const& path)
    : mDatabase{ new QSqlDatabase{QSqlDatabase::addDatabase("QSQLITE")} },
      albumDao{ *mDatabase },
      pictureDao{ *mDatabase }
{
    mDatabase->setDatabaseName(path);
    mDatabase->open();

    albumDao.init();
    pictureDao.init();
}

DatabaseManager::~DatabaseManager()
{
    mDatabase->close();
    delete mDatabase;
    mDatabase = nullptr;
}
