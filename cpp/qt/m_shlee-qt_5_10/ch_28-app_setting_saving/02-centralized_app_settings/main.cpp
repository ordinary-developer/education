#include "App.hpp"

#include <QSettings>
#include <QString>
#include <QDebug>

int main(int argc, char **argv) {
    App app{ argc, argv, "company", "app" };
    
    QSettings *pStgs = App::theApp()->settings();
    pStgs->setValue("Language", "en");
    
    QString const& val = pStgs->value("Language").toString();
    qDebug() << val;
    
    return app.exec();
}