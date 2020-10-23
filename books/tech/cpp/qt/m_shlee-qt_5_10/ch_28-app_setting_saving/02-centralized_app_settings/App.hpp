#include <QApplication>
#include <QSettings>
#include <QString>

class App final : public QApplication {
    Q_OBJECT
    public:
        App(int& argc, 
            char **argv,
            const QString& strOrg,
            const QString& strAppName
            );
        
        static App* theApp(); 
        
        QSettings* settings();
        
    private:
        QSettings *pStgs_;
};
