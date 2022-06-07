#include <QtWidgets>

int main(int argc, char** argv) {
    QApplication app{ argc, argv };

    QDateTimeEdit dateTimeEdit{ QDateTime::currentDateTime() };
    dateTimeEdit.show();

    return app.exec();
}
