#include <iostream>
#include <QColor>
#include <QString>
namespace example_00 {
void run() {
    QColor color{ 100, 200, 0 };

    std::cout <<
        QString{ "red = %1, green = %2, blue = %3, alpha = %4\n" }
            .arg(QString::number(color.red()), 
                 QString::number(color.green()),
                 QString::number(color.blue()),
                 QString::number(color.alpha()))
            .toStdString();

    std::cout <<
        QString{ "redF = %1, greenF = %2, blueF = %3, alphaF = %4\n" }
            .arg(QString::number(color.redF()),
                 QString::number(color.greenF()),
                 QString::number(color.blueF()),
                 QString::number(color.alphaF()))
            .toStdString();

    int r{}, g{}, b{};
    color.getRgb(&r, &g, &b);
    std::cout << 
        QString{ "r = %0, g = %1, b = %2\n" }
            .arg(QString::number(r), QString::number(g), QString::number(b))
            .toStdString();

    QRgb rgbBlue1 = qRgba(0, 0, 255, 255);
    std::cout <<
        QString{ "qRed = %0, qGreen = %1, qBlue = %2, qAlpha = %3\n" }
            .arg(QString::number(qRed(rgbBlue1)),
                 QString::number(qGreen(rgbBlue1)),
                 QString::number(qBlue(rgbBlue1)),
                 QString::number(qAlpha(rgbBlue1)))
            .toStdString();

    QRgb rgbBlue2 = qRgb(0, 0, 255);
    std::cout <<
        QString{ "qRed = %0, qGreen = %1, qBlue = %2, qAlpha = %3\n" }
            .arg(QString::number(qRed(rgbBlue2)),
                 QString::number(qGreen(rgbBlue2)),
                 QString::number(qBlue(rgbBlue2)),
                 QString::number(qAlpha(rgbBlue2)))
            .toStdString();

    QRgb rgbBlue3 = 0x000000FF;
    std::cout <<
        QString{ "qRed = %0, qGreen = %1, qBlue = %2, qAlpha = %3\n" }
            .arg(QString::number(qRed(rgbBlue3)),
                 QString::number(qGreen(rgbBlue3)),
                 QString::number(qBlue(rgbBlue3)),
                 QString::number(qAlpha(rgbBlue3)))
            .toStdString();

    QRgb rgbBlue = 0x000000FF;
    QColor colorBlue1{ rgbBlue };
    QColor colorBlue2;
    colorBlue2.setRgb(rgbBlue);
    std::cout << QString::number(colorBlue1 == colorBlue2).toStdString() << std::endl;

    QColor colorBlue3{ "#0000FF" };
    QColor colorBlue4;
    colorBlue4.setNamedColor("#0000FF");
    std::cout << QString::number(colorBlue3 == colorBlue4).toStdString() << std::endl;
}
}

#include <QColor>
#include <QString>
#include <iostream>
namespace example_01 {
void run() {
    QColor color{};
    color.setHsv(255, 100, 50);
    int h{}, s{}, v{};
    color.getHsv(&h, &s, &v);

    std::cout <<
        QString{ "h = %0, s = %1, v = %2" }
            .arg(QString::number(h), QString::number(s), QString::number(v))
            .toStdString();
}
}

#include <QColor>
#include <QString>
#include <iostream>
namespace example_02 {
void run() {
    QColor color = QColor{ Qt::red }.darker(160);

    std::cout <<
        QString{ "red = %1, green = %2, blue = %3, alpha = %4\n" }
            .arg(QString::number(color.red()), 
                 QString::number(color.green()),
                 QString::number(color.blue()),
                 QString::number(color.alpha()))
            .toStdString();
}
}


#include <iostream>
#include <array>
#include <functional>
#include <string>
#include <QString>
int main() {
    unsigned int const N{ 3 };
    std::array<std::function<void(void)>, N> funcs {
        example_00::run, example_01::run, example_02::run };

    for (unsigned int i{0}; i < N; ++i) {
        std::cout << std::string{ "example " } + std::to_string(i) + std::string{ " =>" } << std::endl;
        funcs[i]();
        std::cout << std::endl << std::endl;
    }

    return 0;
}
