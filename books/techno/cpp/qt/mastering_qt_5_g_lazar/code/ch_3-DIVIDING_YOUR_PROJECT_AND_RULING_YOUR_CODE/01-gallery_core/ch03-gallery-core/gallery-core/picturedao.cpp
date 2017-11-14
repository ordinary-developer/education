#include "picturedao.h"

#include "picture.h"
#include "databasemanager.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>

PictureDao::PictureDao(QSqlDatabase& database)
    : mDatabase{ database } { }

void PictureDao::init() const {
    if (!mDatabase.tables().contains("pictures")) {
        QSqlQuery query{ mDatabase };
        query.exec(
            QString{"CREATE TABLE pictures"} +
                    " (id INTEGER PRIMARY KEY AUTOINCREMENT, " +
                    "album_id INTEGER, " +
                    "url TEXT)");
    }
}

void PictureDao::addPictureInAlbum(int albumId, Picture& picture) const {
    QSqlQuery query(mDatabase);
    query.prepare(
        QString("INSERT INTO pictures") +
                " (albumd_id, url)" +
                " VALUES (" +
                ":album_id, " +
                ":url)");
    query.bindValue(":album_id", albumId);
    query.bindValue(":url", picture.fileUrl());
    query.exec();

    picture.setId(query.lastInsertId().toInt());
    picture.setAlbumId(albumId);
}

void PictureDao::removePicture(int id) const {
    QSqlQuery query{ mDatabase };
    query.prepare("DELETE FROM pictures WHERE id = (:id)");
    query.bindValue(":id", id);
    query.exec();
}

void PictureDao::removePicturesForAlbum(int albumId) const {
    QSqlQuery query{ mDatabase };
    query.prepare("DELETE FROM pictures WHERE albumd_id = (:album_id)");
    query.bindValue(":albumId", albumId);
    query.exec();
}

std::unique_ptr<std::vector<std::unique_ptr<Picture>>> PictureDao::picturesForAlbum(int albumId) const
{
    QSqlQuery query(mDatabase);
    query.prepare("SELECT * FROM pictures WHERE album_id = (:album_id)");
    query.bindValue(":album_id", albumId);
    query.exec();
    std::unique_ptr<std::vector<std::unique_ptr<Picture>>> list(new std::vector<std::unique_ptr<Picture>>());
    while(query.next()) {
        std::unique_ptr<Picture> picture(new Picture());
        picture->setId(query.value("id").toInt());
        picture->setAlbumId(query.value("album_id").toInt());
        picture->setFileUrl(query.value("url").toString());
        list->push_back(move(picture));
    }
    return list;
}

