#include <QPolygon>
#include <QString>
#include <iostream>


int main() {
    QPolygon polygon{};
    polygon << QPoint{ 10, 20 } << QPoint{ 20, 10 } << QPoint{ 30, 30 };

    std::cout << 
        QString{ "1 => x: %1, y: %2 2 => x: %3, y: %4 3 => x: %5, y: %6" }
            .arg(QString::number(polygon.point(0).x()), QString::number(polygon.point(0).y()),
                 QString::number(polygon.point(1).x()), QString::number(polygon.point(1).y()),
                 QString::number(polygon.point(2).x()), QString::number(polygon.point(3).y()))
            .toStdString();

    return 0;
}
