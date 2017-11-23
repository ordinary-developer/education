#include <QtWidgets>


int main(int argc, char** argv) {
    QApplication app{ argc, argv };

    QWidget widget{};

    QPushButton* normalButton{ new QPushButton{"&NormalButton"} };

    QPushButton* toggleButton{ new QPushButton{"&ToggleButton"} };
    toggleButton->setCheckable(true);
    toggleButton->setChecked(true);

    QPushButton* flatButton{ new QPushButton{"&FlatButton"} };
    flatButton->setFlat(true);

    QPixmap pixmap{":/image.jpg"};
    QPushButton* pixmapButton{ new QPushButton{"&Pixmap Button"} };
    pixmapButton->setIcon(pixmap);
    pixmapButton->setIconSize(pixmap.size());

    QVBoxLayout* layout{ new QVBoxLayout{} };
    layout->addWidget(normalButton);
    layout->addWidget(toggleButton);
    layout->addWidget(flatButton);
    layout->addWidget(pixmapButton);
    widget.setLayout(layout);

    widget.show();

    return app.exec();
}
