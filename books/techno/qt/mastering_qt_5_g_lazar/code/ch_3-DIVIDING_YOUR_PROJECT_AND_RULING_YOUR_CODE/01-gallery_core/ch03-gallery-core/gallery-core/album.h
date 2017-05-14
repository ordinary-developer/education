#ifndef ALBUM_H
#define ALBUM_H

#include "gallery-core_global.h"

#include <QString>

class GALLERYCORESHARED_EXPORT Album
{
public:
    explicit Album(QString const& name = "");

    int id() const { return mId; }
    void setId(int id) { mId = id; }
    QString name() const { return mName; }
    void setName(QString const& name) { mName = name; }

private:
    int mId;
    QString mName;
};

#endif // ALBUM_H
