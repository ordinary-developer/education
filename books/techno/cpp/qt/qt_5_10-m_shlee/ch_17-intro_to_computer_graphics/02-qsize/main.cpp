#include <QSize>
#include <QString>
#include <iostream>
namespace example_00 {
void run() {
    QSize size{ 10, 20 };
    int const n = { size.rwidth()++ };

    std::cout <<
        QString("n = %1, size.width = %2, size.height = %3")
            .arg(QString::number(n), QString::number(size.width()), QString::number(size.height()))
            .toStdString();
}
}


#include <QSize>
#include <QString>
#include <iostream>
namespace example_01 {
void run() {
    QSize size1{ 320, 240 };
    size1.scale(400, 600, Qt::IgnoreAspectRatio);

    QSize size2{ 320, 240 };
    size2.scale(400, 600, Qt::KeepAspectRatio);

    QSize size3{ 320, 240 };
    size3.scale(400, 600, Qt::KeepAspectRatioByExpanding);

    std::cout <<
        QString("size1: %1, %2; size2: %3, %4, size3: %5, %6")
            .arg(QString::number(size1.width()), QString::number(size1.height()),
                 QString::number(size2.width()), QString::number(size2.height()),
                 QString::number(size3.width()), QString::number(size3.height()))
            .toStdString();
}
}


#include <array>
#include <functional>
#include <iostream>
int main() {
    unsigned int const N{2};
    std::array<std::function<void(void)>, N> funcs {
        example_00::run, example_01::run };

    for (std::size_t i{0}; i < funcs.size(); ++i) {
        std::cout << std::string{ "example " } + std::to_string(i) + std::string{ " =>\n" };
        funcs[i]();
        std::cout << "\n\n";
    }

    return 0;
}

