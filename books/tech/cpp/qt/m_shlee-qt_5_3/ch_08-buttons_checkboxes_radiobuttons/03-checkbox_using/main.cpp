#include <QtWidgets>


int main(int argc, char** argv) {
    QApplication app{ argc, argv };

    QWidget widget{};
    QCheckBox* normalCheckbox{ new QCheckBox{"&Normal Check Box"} };
    normalCheckbox->setChecked(true);

    QCheckBox* tristateCheckbox{ new QCheckBox{"&Tristate Check Box"} };
    tristateCheckbox->setCheckState(Qt::PartiallyChecked);

    QVBoxLayout* layout{ new QVBoxLayout{} };
    layout->addWidget(normalCheckbox);
    layout->addWidget(tristateCheckbox);
    widget.setLayout(layout);

    widget.show();

    return app.exec();
}
