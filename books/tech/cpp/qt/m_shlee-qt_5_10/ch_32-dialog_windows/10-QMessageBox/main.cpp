#include <QtWidgets>
#include <QLabel>
#include <QMessageBox>
#include <QErrorMessage>


int main(int argc, char** argv) {
    QApplication app{ argc, argv };

    QLabel label{ "e.g." };
    label.show();

    // QMessageBox
    auto msgBox = new QMessageBox{ QMessageBox::Information, 
        "caption", "<b>a</b> <i>simple</i> <u>message</u>",
        QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel };

    int const n = msgBox->exec();
    delete msgBox;

    if (QMessageBox::Yes == n)
        QMessageBox::information(nullptr, "information", "ok was pressed");

    // info
    QMessageBox::information(nullptr, "caption", "text");

    // warn
    QMessageBox::warning(nullptr, "caption", "text\ntext\ntext",
        QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);

    // critical
    QMessageBox::critical(nullptr, 
        "caption", 
        "text text text "
        "text text text",
        QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);

    // about
    QMessageBox::about(nullptr, "caption", "<b>my program ver. 1.0</b>");

    // aboutQt
    QMessageBox::aboutQt(nullptr);

    // QErrorMessage
    auto errorMsg = new QErrorMessage(nullptr);
    errorMsg->showMessage("write error");
    delete errorMsg;

    return app.exec();
}
