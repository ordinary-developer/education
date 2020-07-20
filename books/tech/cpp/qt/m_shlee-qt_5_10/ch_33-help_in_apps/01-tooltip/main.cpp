#include <QApplication>
#include <QPushButton>

int main(int argc, char** argv) {
    QApplication app{ argc, argv };
    
    QPushButton btn{ "btn title" };
    btn.setToolTip("btn tooptip");
    btn.show();

    return app.exec();
}
