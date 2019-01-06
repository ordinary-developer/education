#include <QtWidgets>
#include <iostream>

class Wgt : public QWidget {
    public:
        Wgt(QWidget* pParentWgt = nullptr)
            : QWidget{ pParentWgt } {}


    protected:
        virtual void paintEvent(QPaintEvent*) {
            QPicture pic{};
            if (not pic.load("myline.dat")) {
                std::cout << "can not load the file" << std::endl;
                return;
            }

            QPainter painter{};
            painter.begin(this);
            painter.drawPicture(QPoint{ 0, 0 }, pic);
            painter.end();
        }
};


int main(int argc, char** argv) {
    QApplication app{ argc, argv };

    QPicture pic{};
    QPainter painter{};
    painter.begin(&pic);
    painter.drawLine(20, 20, 50, 50);
    painter.end();
    if (not pic.save("myline.dat")) {
        std::cout << "can not save the file" << std::endl;
    }

    Wgt wgt{};
    wgt.resize(150, 150);
    wgt.show();

    return app.exec();
}

