#include <QtWidgets>

class MyWgt : public QLabel {
    public:
        MyWgt(QWidget* pParentWgt = nullptr)
            : QLabel{ pParentWgt } {}

    protected:
        virtual void paintEvent(QPaintEvent*) final override {
            QPainter painter{ this };
            QPixmap pix{ ":/image.jpg" };
            painter.setBrush(QBrush{ Qt::black, pix });
            painter.drawEllipse(0, 0, 300, 150);
        }
};


int main(int argc, char** argv) {
    QApplication app{ argc, argv };

    MyWgt wgt;
    wgt.resize(300, 150);
    wgt.show();

    return app.exec();
}
