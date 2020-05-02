#include "App.hpp"

App::App(int& argc, 
    char **argv,
    const QString& strOrg,
    const QString& strAppName
    )
    : QApplication{ argc, argv }, pStgs_{ nullptr }
{
    setOrganizationName(strOrg);
    setApplicationName(strAppName);
       
    pStgs_ = new QSettings{ strOrg, strAppName, this };
}
        
App* App::theApp() { return static_cast<App*>(qApp); }

QSettings* App::settings() { return pStgs_; }
