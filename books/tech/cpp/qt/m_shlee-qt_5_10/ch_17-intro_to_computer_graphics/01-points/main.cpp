#include <QPoint>
#include <QString>
#include <iostream>
#include <array>
namespace example_01 {
void run() {
    QPoint pt1{ 10, 20 };
    QPoint pt2{ 20, 10 };
    QPoint pt3{ pt1 + pt2 };
    
    for (auto const& pt : std::array<QPoint, 3>{ pt1, pt2, pt3 })
        std::cout <<
            QString{ "pt -> x: %0, y: %1\n" }
                .arg(QString::number(pt.x()),
                    QString::number(pt.y()))
                .toStdString();
}    
} // example 01


#include <QPoint>
#include <QString>
#include <iostream>
namespace example_02 {
void run() {
    QPoint pt{ 10, 20 };
    pt *= 2;
    
    std::cout << 
        QString{ "x: %0, y: %1\n" }
            .arg(QString::number(pt.x()), QString::number(pt.y()))
            .toStdString();
}    
} // example_02


#include <QPoint>
#include <QString>
#include <iostream>
namespace example_03 {
void run() {
    QPoint pt{ 10, 20 };
    pt.rx() += 10;
    
    std::cout << 
        QString{ "x: %0, y: %1\n" }
            .arg(QString::number(pt.x()), QString::number(pt.y()))
            .toStdString();
}    
} // example_03


#include <QPoint>
#include <QString>
#include <iostream>
namespace example_04 {
void run() {
    QPoint pt1{ 10, 20 };
    QPoint pt2{ 10, 20 };
    bool const b = (pt1 == pt2);
    std::cout << 
        QString{ "points are equal: %0\n" }
            .arg(QString::number(b)).toStdString();
}    
} // example_04


#include <QPoint>
#include <QString>
#include <iostream>
namespace example_05 {
void run() {
    QPoint pt{};
    bool const b{ pt.isNull() };
    std::cout << 
        QString{ "the point is null: %0\n" }
            .arg(QString::number(b)).toStdString();
}    
} // example_05


#include <QPoint>
#include <QString>
#include <iostream>
namespace example_06 {
void run() {
    QPoint pt{ 10, 20 };
    int const n = pt.manhattanLength();
    
    std::cout << 
        QString{ "n = %0" }
            .arg(QString::number(n)).toStdString();
}    
} // example_06


int main() {
    std::cout << "example 01 =>\r\n";
    example_01::run();
    std::cout << "\n\n";
    
    std::cout << "example 02 =>\r\n";
    example_02::run();
    std::cout << "\n\n";
    
    std::cout << "example_03 =>\r\n";
    example_03::run();
    std::cout << "\n\n";
    
    std::cout << "example_04 =>\r\n";
    example_04::run();
    std::cout << "\n\n";
    
    std::cout << "example_05 =>\r\n";
    example_05::run();
    std::cout << "\n\n";
    
    std::cout << "example_06 =>\r\n";
    example_06::run();
    std::cout << "\n\n";
    
    return 0;
}