#include "Ellipse.h"

#include <QPainter>
#include "Ellipse.h"


Ellipse::Ellipse(QQuickItem * pqi /* = nullptr */)
	: QQuickPaintedItem{pqi}, m_color{Qt::black}
{
}

void Ellipse::paint(QPainter * ppainter)
{
	ppainter->setRenderHint(QPainter::Antialiasing, true);
	ppainter->setBrush(QBrush(colorValue()));
	ppainter->setPen(Qt::NoPen);
	ppainter->drawEllipse(boundingRect());
}

QColor Ellipse::colorValue() const
{
	return m_color;
}

void Ellipse::setColorValue(const QColor & col)
{
	m_color = col;
}