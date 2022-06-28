#pragma once

#include <QQuickPaintedItem>

class QPainter;

class Ellipse : public QQuickPaintedItem {
Q_OBJECT
private:
	Q_PROPERTY(QColor color WRITE setColorValue
							READ  colorValue)
	QColor m_color;
	
public:
	Ellipse(QQuickItem * pqi = nullptr);
	
	void paint(QPainter * ppainter);
	
	QColor colorValue() const;
	void setColorValue(const QColor &);
};
