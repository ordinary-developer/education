#include <QtWidgets>

int main(int argc, char** argv) {
    QApplication app{ argc, argv };

    QWidget widget{};
    QDial* dial{ new QDial{} };
    QProgressBar* progressBar{ new QProgressBar{} };

    dial->setRange(0, 100);
    dial->setNotchTarget(5);
    dial->setNotchesVisible(true);

    QObject::connect(
        dial,
        static_cast<void (QDial::*)(int)>(&QDial::valueChanged),
        progressBar, 
        static_cast<void (QProgressBar::*)(int)>(&QProgressBar::setValue));
                     
    QVBoxLayout* layout{ new QVBoxLayout{} };
    layout->addWidget(dial);
    layout->addWidget(progressBar);
    widget.setLayout(layout);

    widget.resize(180, 200);
    widget.show();

    return app.exec();
}
