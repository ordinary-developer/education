#include <QtWidgets>

int main(int argc, char** argv) {
    QApplication app{argc, argv};
    QWidget widget{};

    QWidget* childWidget1{ new QWidget{&widget} };
    QPalette palette1{};
    palette1.setColor(childWidget1->backgroundRole(), Qt::blue);
    childWidget1->setPalette(palette1);
    childWidget1->resize(100, 100);
    childWidget1->move(25, 25);
    childWidget1->setAutoFillBackground(true);

    QWidget* childWidget2{new QWidget{&widget}};
    QPalette palette2{};
    palette2.setBrush(childWidget2->backgroundRole(), 
                      QBrush{QPixmap{":/image.jpg"}});
    childWidget2->setPalette(palette2);
    childWidget2->resize(100, 100);
    childWidget2->move(75, 75);
    childWidget2->setAutoFillBackground(true);

    widget.resize(200, 200);
    widget.show();

    return app.exec();
}
