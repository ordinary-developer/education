#include <QtWidgets>

int main(int argc, char** argv) {
    QApplication app(argc, argv);

    QFrame* frame{ new QFrame{} };
    frame->setFrameStyle(QFrame::Box | QFrame::Sunken);
    frame->setLineWidth(3);
    frame->resize(200, 200);
    frame->show();

    return app.exec();
}
