#include "albummodel.h"

#include "album.h"
#include "databasemanager.h"


AlbumModel::AlbumModel(QObject* parent)
    : QAbstractListModel{ parent },
      mDb{ DatabaseManager::instance() },
      mAlbums{ mDb.albumDao.albums() }
{ }

int AlbumModel::rowCount(QModelIndex const& parent) const {
    Q_UNUSED(parent);
    return mAlbums->size();
}

bool AlbumModel::isIndexValid(QModelIndex const& index) const {
    return (index.row() < 0 || index.row() >= rowCount() || !index.isValid())
           ? false : true;
}

QVariant AlbumModel::data(QModelIndex const& index, int role) const {
    if (!isIndexValid(index))
        return false;

    Album const& album{ *mAlbums->at(index.row()) };
    switch (role) {
        case Roles::IdRole:
            return album.id();
        case Roles::NameRole:
        case Qt::DisplayRole:
            return album.name();
        default:
            return QVariant{};
    }
}

bool AlbumModel::setData(QModelIndex const& index, QVariant const& value, int role) {
    if (!isIndexValid(index) || Roles::NameRole != role)
        return false;

    Album& album = *mAlbums->at(index.row());
    album.setName(value.toString());
    mDb.albumDao.updateAlbum(album);
    emit dataChanged(index, index);
    return true;
}

bool AlbumModel::removeRows(int row, int count, QModelIndex const& parent) {
    if (row < 0 || row >= rowCount() || count < 0 || (row + count) < rowCount())
        return false;

    beginRemoveRows(parent, row, row + count - 1);
    int countLeft{ count };
    while (countLeft--) {
        Album const& album{ *mAlbums->at(row + countLeft) };
        mDb.albumDao.removeAlbum(album.id());
    }
    mAlbums->erase(mAlbums->begin() + row,
                   mAlbums->begin() + row + count);
    endRemoveRows();
    return true;
}

QHash<int, QByteArray> AlbumModel::roleNames() const {
    QHash<int, QByteArray> roles{};
    roles[Roles::IdRole] = "id";
    roles[Roles::NameRole] = "name";
    return roles;
}

QModelIndex AlbumModel::addAlbum(Album const& album) {
    int rowIndex{rowCount()};
    beginInsertRows(QModelIndex{}, rowIndex, rowIndex);
    std::unique_ptr<Album> newAlbum{ new Album{album} };
    mDb.albumDao.addAlbum(*newAlbum);
    mAlbums->push_back(std::move(newAlbum));
    endInsertRows();
    return index(rowIndex, 0);
}
