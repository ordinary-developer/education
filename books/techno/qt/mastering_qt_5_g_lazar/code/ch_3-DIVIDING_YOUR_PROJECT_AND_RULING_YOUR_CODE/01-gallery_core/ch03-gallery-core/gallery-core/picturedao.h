#ifndef PICTUREDAO_H
#define PICTUREDAO_H

class QSqlDatabase;
class Picture;

#include <memory>
#include <vector>


class PictureDao
{
public:
    explicit PictureDao(QSqlDatabase& database);

    void init() const;

    void addPictureInAlbum(int albumId, Picture& picture) const;
    void removePicture(int id) const;
    void removePicturesForAlbum(int albumId) const;
    std::unique_ptr<std::vector<std::unique_ptr<Picture>>> picturesForAlbum(int albumId) const;

private:
    QSqlDatabase& mDatabase;
};

#endif // PICTUREDAO_H
