#include <QLabel>
#include <QString>
class BlinkLabel : public QLabel {
    public:
        BlinkLabel(const QString & txt, int interval = 200, QWidget * parentWgt = nullptr)
            : QLabel{ txt, parentWgt }, blink_{true}, txt_{txt}
        {
            startTimer(interval);
        }
        
        virtual void timerEvent(QTimerEvent*) {
            blink_ = !blink_;
            setText(blink_ ? txt_ : "");
        }
        
    private:
        bool blink_;
        QString txt_;
};


#include <QApplication>
int main(int argc, char** argv) {
    QApplication app{argc, argv};
    
    BlinkLabel lbl{ "<font color = red><center>blink</center></font>" };
    lbl.resize(80, 25);
    lbl.show();
    
    return app.exec();
}
