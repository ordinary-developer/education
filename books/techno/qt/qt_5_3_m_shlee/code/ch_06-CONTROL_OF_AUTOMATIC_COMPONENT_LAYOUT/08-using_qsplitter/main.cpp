#include <QtWidgets>

int main(int argc, char** argv) {
    QApplication app(argc, argv);

    QSplitter splitter{ Qt::Vertical };
    QTextEdit* pTextEdit1{ new QTextEdit{} };
    QTextEdit* pTextEdit2{ new QTextEdit{} };
    splitter.addWidget(pTextEdit1);
    splitter.addWidget(pTextEdit2);

    pTextEdit1->setPlainText("Line1\n"
                             "Line2\n"
                             "Line3\n"
                             "Line4\n"
                             "Line5\n"
                             "Line6\n"
                             "Line7\n");
    pTextEdit2->setPlainText(pTextEdit1->toPlainText());

    splitter.resize(200, 220);
    splitter.show();

    return app.exec();
}
