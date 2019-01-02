#include <QPoint>
#include <QString>
#include <iostream>
#include <array>
namespace example_00 {
void run() {
    QPoint pt1{ 10, 20 };
    QPoint pt2{ 20, 10 };
    QPoint pt3{ pt1 + pt2 };

    std::array<QPoint, 3> pts = { pt1, pt2, pt3 };
    for (unsigned int i{0}; i < pts.size(); ++i) 
        std::cout <<
            QString("pt%1 -> x: %2, y: %3\n")
                .arg(QString::number(i), QString::number(pts[i].x()), QString::number(pts[i].y()))
                .toStdString();
}
}

#include <QPoint>
#include <QString>
#include <iostream>
namespace example_01 {
void run() {
    QPoint pt{ 10, 20 };
    pt *= 2;

    std::cout <<
        QString("pt -> x: %1, y: %2\n")
            .arg(QString::number(pt.x()), QString::number(pt.y()))
            .toStdString();
}
}

#include <QPoint>
#include <QString>
#include <iostream>
namespace example_02 {
void run() {
    QPoint pt{ 10, 20 };
    pt.rx() += 10;

    std::cout <<
        QString("pt -> x: %1, y: %2\n")
            .arg(QString::number(pt.x()), QString::number(pt.y()))
            .toStdString();
}
}

#include <QPoint>
#include <QString>
#include <iostream>
namespace example_03 {
void run() {
    QPoint pt1{ 10, 20 };
    QPoint pt2{ 10, 20 };
    bool const b = (pt1 == pt2);

    std::cout << QString("b value = %1\n").arg(QString::number(b)).toStdString();
}
}

#include <QPoint>
#include <QString>
#include <array>
#include <iostream>
namespace example_04 {
void run() {
    for (auto const& pt : std::array<QPoint, 4>{ QPoint{ 0, 0 }, QPoint{ 1, 0 },
                                                 QPoint{ 0, 1 }, QPoint{ 1, 1 } })
        std::cout << 
            QString("pt with coords (%1, %2) is null : %3\n")
                .arg(QString::number(pt.x()), QString::number(pt.y()), QString::number(pt.isNull()))
                .toStdString();
}
}

#include <QPoint>
#include <QString>
#include <iostream>
namespace example_05 {
void run() {
    QPoint pt{ 10, 20 };
    int const n = pt.manhattanLength();

    std::cout << QString("manhattan len = %1\n").arg(QString::number(n)).toStdString();
}
}


#include <functional>
#include <array>
#include <iostream>
int main() {
    unsigned int const size = 6;
    std::array<std::function<void(void)>, size> funcs =
        { example_00::run, example_01::run, example_02::run, example_03::run,
          example_04::run, example_05::run };

    for (unsigned int i{0}; i < size; ++i) {
        std::cout << std::string{ "example " } + std::to_string(i) + std::string{ " =>\n" };
        funcs[i]();
        std::cout << "\n\n";
    }
    
    return 0;
}
