#include "MouseFilter.hpp"

#include <QApplication>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>


int main(int argc, char** argv) {
    QApplication app{ argc, argv };
    
    QLineEdit lineEdit{ "QLineEdit" };
    lineEdit.installEventFilter(new MouseFilter{ &lineEdit });
    lineEdit.show();
    
    QLabel label{ "QLabel" };
    label.installEventFilter(new MouseFilter{ &label });
    label.show();
    
    QPushButton cmd{ "QPushButton" };
    cmd.installEventFilter(new MouseFilter{ &cmd });
    cmd.show();
    
    return app.exec();
}
