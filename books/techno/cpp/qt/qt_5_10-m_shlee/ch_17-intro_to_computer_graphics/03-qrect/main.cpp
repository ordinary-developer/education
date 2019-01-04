#include <QRect>
#include <QString>
#include <iostream>

int main() {
    QPoint pt{ 10, 10 };
    QSize size{ 20, 10 };
    QRect r{ pt, size };

    std::cout << 
        QString("pt => x: %1, y: %2, width: %3, height: %4")
            .arg(QString::number(r.x()), QString::number(r.y()),
                 QString::number(r.width()), QString::number(r.height()))
            .toStdString();

    return 0;
}
