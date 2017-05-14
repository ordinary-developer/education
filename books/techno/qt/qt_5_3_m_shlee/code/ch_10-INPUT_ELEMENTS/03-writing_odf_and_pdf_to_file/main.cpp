#include <QtWidgets>
#include <QPrinter>

int main(int argc, char** argv) {
    QApplication app{ argc, argv };

    QTextEdit* textEdit1{ new QTextEdit{"This is a <b>TEST</b>"} };
    QTextDocumentWriter writer{};
    writer.setFormat("odf");
    writer.setFileName("output.odf");
    writer.write(textEdit1->document());

    QTextEdit* textEdit2{ new QTextEdit{"This is a <b>TEST</b>"} };
    QPrinter printer{QPrinter::HighResolution};
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName("output.pdf");
    textEdit2->document()->print(&printer);

    return app.exec();
}
