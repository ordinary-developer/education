#include "ImageProvider.h"

ImageProvider::ImageProvider()
	: QQuickImageProvider(QQuickImageProvider::Image)
{
}

QImage ImageProvider::brightness(const QImage & imgOrig, int n)
{
	QImage imgTmp = imgOrig.convertToFormat(QImage::Format_ARGB32);
	qint32 nHeight = imgTmp.height();
	qint32 nWidth = imgTmp.width();
	
	for (qint32 y = 0; y < nHeight; ++y) {
		QRgb * tmpLine = reinterpret_cast<QRgb*>(imgTmp.scanLine(y));
		
		for (qint32 x = 0; x < nWidth; ++x) {
			int r = qRed(*tmpLine) + n;
			int g = qGreen(*tmpLine) + n;
			int b = qBlue(*tmpLine) + n;
			int a = qAlpha(*tmpLine);
			
			*tmpLine++ = qRgba(r > 255 ? 255 : (r < 0 ? 0 : r),
							   g > 255 ? 255 : (g < 0 ? 0 : g),
							   b > 255 ? 255 : (b < 0 ? 0 : b),
							   a);
		}
	}
	
	return imgTmp;
}

QImage ImageProvider::requestImage(const QString & strId, QSize * ps, const QSize &)
{
	QStringList list = strId.split(";");
	bool ok = false;
	int brightnessVal = list.last().toInt(&ok);
	QImage img = brightness(QImage(":/" + list.first()), brightnessVal);
	
	if (ps) {
		*ps = img.size();
	}
	
	return img;
}