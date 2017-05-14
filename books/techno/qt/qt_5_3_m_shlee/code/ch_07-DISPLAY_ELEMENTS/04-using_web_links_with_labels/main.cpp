#include <QtWidgets>

int main(int argc, char** argv) {
    QApplication app{ argc, argv };

    QLabel label 
        { "<a href=\"http://www.bhv.ru\">www.bhv.ru</a>" };
    label.setOpenExternalLinks(true);
    label.show();

    app.exec();
}

