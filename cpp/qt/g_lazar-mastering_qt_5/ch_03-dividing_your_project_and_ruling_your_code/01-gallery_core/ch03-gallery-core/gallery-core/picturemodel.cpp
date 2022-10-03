#include "picturemodel.h"

#include "databasemanager.h"
#include "albummodel.h"

PictureModel::PictureModel(AlbumModel const& albumModel, QObject* parent)
    : QAbstractListModel{ parent },
      mDb{ DatabaseManager::instance() },
      mAlbumId{-1},
      mPictures{ new std::vector<std::unique_ptr<Picture>>{} }
{
    connect(&albumModel, &AlbumModel::rowsRemoved,
            this, &PictureModel::deletePicturesForAlbum);
}

// override region
int PictureModel::rowCount(const QModelIndex& /*parent*/) const
{
    return mPictures->size();
}

QVariant PictureModel::data(const QModelIndex& index, int role) const
{
    if (!isIndexValid(index)) {
        return QVariant();
    }

    const Picture& picture = *mPictures->at(index.row());
    switch (role) {
        case Qt::DisplayRole:
            return picture.fileUrl().fileName();
            break;

        case Roles::UrlRole:
            return picture.fileUrl();
            break;

        case Roles::FilePathRole:
            return picture.fileUrl().toLocalFile();
            break;

        default:
            return QVariant();
    }
}

bool PictureModel::removeRows(int row, int count, const QModelIndex& parent)
{
    if (row < 0
            || row >= rowCount()
            || count < 0
            || (row + count) > rowCount()) {
        return false;
    }

    beginRemoveRows(parent, row, row + count - 1);
    int countLeft = count;
    while(countLeft--) {
        const Picture& picture = *mPictures->at(row + countLeft);
        mDb.pictureDao.removePicture(picture.id());
    }
    mPictures->erase(mPictures->begin() + row,
                    mPictures->begin() + row + count);
    endRemoveRows();

    return true;
}

QHash<int, QByteArray> PictureModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[Roles::FilePathRole] = "filepath";
    return roles;
}

// public interface region
QModelIndex PictureModel::addPicture(const Picture& picture)
{
    int rows = rowCount();
    beginInsertRows(QModelIndex(), rows, rows);
    std::unique_ptr<Picture>newPicture(new Picture(picture));
    mDb.pictureDao.addPictureInAlbum(mAlbumId, *newPicture);
    mPictures->push_back(move(newPicture));
    endInsertRows();
    return index(rows, 0);
}
void PictureModel::setAlbumId(int albumId)
{
    beginResetModel();
    mAlbumId = albumId;
    loadPictures(mAlbumId);
    endResetModel();
}

void PictureModel::clearAlbum()
{
    setAlbumId(-1);
}

void PictureModel::deletePicturesForAlbum()
{
    mDb.pictureDao.removePicturesForAlbum(mAlbumId);
    clearAlbum();
}

// private region
void PictureModel::loadPictures(int albumId)
{
    if (albumId <= 0) {
        mPictures.reset(new std::vector<std::unique_ptr<Picture>>());
        return;
    }
    mPictures = mDb.pictureDao.picturesForAlbum(albumId);
}

bool PictureModel::isIndexValid(const QModelIndex& index) const
{
    if (index.row() < 0 || index.row() >= rowCount() || !index.isValid())
        return false;

    return true;
}
