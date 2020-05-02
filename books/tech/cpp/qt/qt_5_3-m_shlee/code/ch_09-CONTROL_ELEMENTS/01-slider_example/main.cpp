#include <QtWidgets>

int main(int argc, char** argv) {
    QApplication app{ argc, argv };

    QWidget widget{};
    QSlider* slider{ new QSlider{Qt::Horizontal} };
    QLabel* label{ new QLabel{"3"} };

    slider->setRange(0, 9);
    slider->setPageStep(2);
    slider->setValue(3);
    slider->setTickInterval(2);
    slider->setTickPosition(QSlider::TicksBelow);

    QObject::connect(
        slider, static_cast<void (QSlider::*)(int)>(&QSlider::valueChanged),
        label, static_cast<void (QLabel::*)(int)>(&QLabel::setNum));

    QHBoxLayout* layout{ new QHBoxLayout{} };
    layout->addWidget(slider);
    layout->addWidget(label);
    widget.setLayout(layout);

    widget.show();

    return app.exec();
}

