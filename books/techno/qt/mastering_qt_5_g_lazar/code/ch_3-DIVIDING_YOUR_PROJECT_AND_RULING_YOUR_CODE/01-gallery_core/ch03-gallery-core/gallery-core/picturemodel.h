#ifndef PICTUREMODEL_H
#define PICTUREMODEL_H

#include "gallery-core_global.h"
#include "picture.h"
class DatabaseManager;
class Album;
class AlbumModel;

#include <QAbstractListModel>
#include <QHash>
#include <memory>
#include <vector>


class GALLERYCORESHARED_EXPORT PictureModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum Roles {
        UrlRole = Qt::UserRole + 1,
        FilePathRole
    };

    explicit PictureModel(AlbumModel const& albumModel, QObject* parent = nullptr);

    // #region overrided methods
    int rowCount(QModelIndex const& parent = QModelIndex{}) const override;
    QVariant data(QModelIndex const& index, int role) const override;
    bool removeRows(int row, int count, QModelIndex const& parent) override;
    QHash<int, QByteArray> roleNames() const override;
    // #endregion overrided methods

    QModelIndex addPicture(const Picture& picture);
    void setAlbumId(int albumId);
    void clearAlbum();

public slots:
    void deletePicturesForAlbum();

private:
    void loadPictures(int albumId);
    bool isIndexValid(const QModelIndex& index) const;

    DatabaseManager& mDb;
    int mAlbumId;
    std::unique_ptr<std::vector<std::unique_ptr<Picture>>> mPictures;
};

#endif // PICTUREMODEL_H
