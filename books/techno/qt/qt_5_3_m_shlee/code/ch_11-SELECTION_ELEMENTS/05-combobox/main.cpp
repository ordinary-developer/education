#include <QtWidgets>

int main(int argc, char** argv) {
    QApplication app{ argc, argv };

    QComboBox comboBox{};
    QStringList elements{};
    elements << "John" << "Paul" << "George" << "Ringo";
    comboBox.addItems(elements);
    comboBox.setEditable(true);
    comboBox.show();

    return app.exec();
}
