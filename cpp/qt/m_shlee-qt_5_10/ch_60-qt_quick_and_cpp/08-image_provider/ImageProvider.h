#pragma once

#include <QObject>
#include <QImage>
#include <QQuickImageProvider>


class ImageProvider : public QQuickImageProvider {
private:
	QImage brightness(const QImage & imgOrig, int n);
	
public:
	ImageProvider();
	
	QImage requestImage(const QString &, QSize *, const QSize &);
};
