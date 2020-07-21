#include <QApplication>
#include <QSplashScreen>
#include <QLabel>
#include <QTime>
#include <QPixmap>
#include <QString>


void loadModules(QSplashScreen* pSplash) {
    QTime time{};
    time.start();

    for (int i{0}; i < 100; ) {
        if (time.elapsed() > 40) { 
            time.start();
            ++i;
        }

        pSplash->showMessage(
            "loading modules: " + QString::number(i) + "%", 
            Qt::AlignHCenter | Qt::AlignBottom,
            Qt::black);
        qApp->processEvents();
    }
}

int main(int argc, char** argv) {
    QApplication app{ argc, argv };
    QSplashScreen splash{ QPixmap{ ":/splash.png" } };

    splash.show();

    loadModules(&splash);
    QLabel lbl{ "<h1><center>my application<br>is ready</center></h1>" };
    splash.finish(&lbl);

    lbl.resize(250, 250);
    lbl.show();

    return app.exec();
}