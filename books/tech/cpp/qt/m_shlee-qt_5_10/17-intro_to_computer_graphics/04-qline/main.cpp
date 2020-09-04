#include <QLine>
#include <QString>
#include <iostream>


int main() {
    QLine line{ 10, 10, 30, 20 };

    std::cout <<
        QString{ "line => x1: %1, y1: %2, x2: %3, y2: %4\n" }
            .arg(QString::number(line.x1()), QString::number(line.y1()),
                 QString::number(line.x2()), QString::number(line.y2()))
            .toStdString();

    std::cout <<
        QString{ "line => x1: %1, y1: %2, x2: %3, y2: %4\n" }
            .arg(QString::number(line.p1().x()), QString::number(line.p1().y()),
                 QString::number(line.p2().x()), QString::number(line.p2().y()))
            .toStdString();

    std::cout <<
        QString{ "line => dx = %1, dy = %2" }
            .arg(QString::number(line.dx()), QString::number(line.dy()))
            .toStdString();

    return 0;
}
