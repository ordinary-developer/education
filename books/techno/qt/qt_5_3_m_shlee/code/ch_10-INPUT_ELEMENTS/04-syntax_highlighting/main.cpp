#include "SyntaxHighlighter.hpp"

#include <QtWidgets>

int main(int argc, char** argv) {
    QApplication app{ argc, argv };

    QTextEdit txt{};
    QFont fnt{ "Lucida Console", 9, QFont::Normal };
    txt.document()->setDefaultFont(fnt);

    new SyntaxHighlighter(txt.document());

    QPalette palette{ txt.palette() };
    palette.setColor(QPalette::Base, Qt::darkBlue);
    palette.setColor(QPalette::Text, Qt::yellow);
    txt.setPalette(palette);

    txt.show();
    txt.resize(640, 480);

    QFile file("SyntaxHighlighter.cpp");
    file.open(QFile::ReadOnly);
    txt.setPlainText(QLatin1String(file.readAll()));

    return app.exec();
}
