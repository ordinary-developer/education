#include "picture.h"

Picture::Picture(QString const& filePath)
    : Picture{QUrl::fromLocalFile(filePath)} { }

Picture::Picture(QUrl const& fileUrl)
    : mId{-1}, mAlbumId{-1}, mFileUrl{fileUrl} { }

