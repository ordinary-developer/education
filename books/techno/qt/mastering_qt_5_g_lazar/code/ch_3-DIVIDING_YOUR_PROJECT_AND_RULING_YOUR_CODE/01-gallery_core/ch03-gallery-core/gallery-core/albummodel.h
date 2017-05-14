#ifndef ALBUMMODEL_H
#define ALBUMMODEL_H

#include "gallery-core_global.h"
#include "album.h"

class DatabaseManager;

#include <QAbstractListModel>
#include <QHash>
#include <memory>
#include <vector>

class GALLERYCORESHARED_EXPORT AlbumModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum Roles {
        IdRole = Qt::UserRole + 1,
        NameRole
    };

    AlbumModel(QObject* parent = nullptr);

    int rowCount(QModelIndex const& parent = QModelIndex{}) const override;
    QVariant data(QModelIndex const& index, int role) const override;
    bool setData(QModelIndex const& index, QVariant const& value, int rule) override;
    bool removeRows(int row, int count, QModelIndex const& parent) override;
    QHash<int, QByteArray> roleNames() const override;

    QModelIndex addAlbum(Album const& album);

private:
    bool isIndexValid(QModelIndex const& index) const;

    DatabaseManager& mDb;
    std::unique_ptr<std::vector<std::unique_ptr<Album>>> mAlbums;
};

#endif // ALBUMMODEL_H
