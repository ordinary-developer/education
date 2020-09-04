#include <QtWidgets>

class OneLineWgt : public QWidget {
    public:
        OneLineWgt(QWidget* pParentWgt = nullptr)
            : QWidget{ pParentWgt } {}

    protected:
        virtual void paintEvent(QPaintEvent*) {
            QPainter painter{ this };
            painter.setRenderHint(QPainter::Antialiasing, true);
            painter.drawLine(QPointF{ 10, 10 }, QPointF{ 90, 90 });
        }
};


class PolyLineWgt : public QWidget {
    public:
        PolyLineWgt(QWidget* pParentWgt = nullptr)
            : QWidget{ pParentWgt } {}


    protected:
        virtual void paintEvent(QPaintEvent*) {
            QPainter painter{ this };
            painter.setRenderHint(QPainter::Antialiasing, true);

            int const n{ 8 };
            QPointF a[n];
            for (unsigned int i{0}; i < n; ++i) {
                qreal const fAngle = ::qDegreesToRadians(360.0 * i / n);
                qreal const x = 50 + cos(fAngle) * 40;
                qreal const y = 50 + sin(fAngle) * 40;
                a[i] = QPointF{ x, y };
            }
            painter.drawPolyline(a, n);
        }
};


int main(int argc, char** argv) {
    QApplication app{ argc, argv };

    OneLineWgt* oneLineWgt{ new OneLineWgt{} };
    PolyLineWgt* polyLineWgt{ new PolyLineWgt{} };

    QVBoxLayout* pLayout{ new QVBoxLayout{} };
    pLayout->setMargin(5);
    pLayout->setSpacing(10);
    pLayout->addWidget(oneLineWgt);
    pLayout->addWidget(polyLineWgt);

    QWidget mainWgt{};
    mainWgt.setLayout(pLayout);
    mainWgt.resize(450, 300);
    mainWgt.show();

    return app.exec();
}
