#include <QtWidgets>

class MyWgt : public QWidget {
    public:
        MyWgt(QWidget* pParentWgt = nullptr)
            : QWidget{ pParentWgt } {}

    protected:
        virtual void paintEvent(QPaintEvent*) {
            QPainter painter{ this };
            painter.setPen(QPen{ Qt::black, 3 });

            int const n{ 8 };
            for (unsigned i{0}; i < n; ++i) {
                qreal const fAngle = ::qDegreesToRadians(360.0 * i / n);
                qreal const x = 50 + cos(fAngle) * 40;
                qreal const y = 50 + sin(fAngle) * 40;
                painter.drawPoint(QPointF{ x, y });
            }
        }
};


int main(int argc, char** argv) {
    QApplication app{ argc, argv };

    MyWgt wgt;
    wgt.resize(300, 150);
    wgt.show();

    return app.exec();
}
