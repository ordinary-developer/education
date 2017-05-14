#include <QtWidgets>

int main(int argc, char** argv) {
    QApplication app{ argc, argv };

    QTextEdit text{};

    text.setHtml("<html>"
                 "<body bgcolor=magenta>"
                 "<center><img src=\":/image.jpg\"></center>"
                 "<h2><center>Gnome poem</center></h2>"
                 "<h3><center>(http://ynstyn.tripod.com)</center></h3>"
                 "</body>"
                 "<html>");

    text.resize(320, 250);
    text.show();

    return app.exec();
}
