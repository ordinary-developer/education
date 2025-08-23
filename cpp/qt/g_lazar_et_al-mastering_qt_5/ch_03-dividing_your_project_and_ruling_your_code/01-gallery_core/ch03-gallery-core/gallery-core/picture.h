#ifndef PICTURE_H
#define PICTURE_H

#include "gallery-core_global.h"

#include <QUrl>
#include <QString>

class GALLERYCORESHARED_EXPORT Picture
{
public:
    explicit Picture(QString const& filePath = "");
    explicit Picture(QUrl const& fileUrl);

    int id() const { return mId; }
    void setId(int id) { mId = id; }

    int albumId() const { return mAlbumId; }
    void setAlbumId(int albumId) { mAlbumId = albumId; }

    QUrl fileUrl() const { return mFileUrl; }
    void setFileUrl(QUrl const& fileUrl) { mFileUrl = fileUrl; }

private:
    int mId;
    int mAlbumId;
    QUrl mFileUrl;
};

#endif // PICTURE_H
