#include <QtWidgets>

class LinearGradWgt : public QWidget {
    public:
        LinearGradWgt(QWidget* pParentWgt = nullptr)
            : QWidget{ pParentWgt } {}

    protected:
        virtual void paintEvent(QPaintEvent*) final override {
            QPainter painter{ this };
            QLinearGradient gradient{ .0, .0, (double)width(), (double)height() };
            gradient.setColorAt(0, Qt::red);
            gradient.setColorAt(0.5, Qt::green);
            gradient.setColorAt(1, Qt::blue);
            painter.setBrush(gradient);
            painter.drawRect(rect());
        }
};

class ConicalGradWgt : public QWidget {
    public:
        ConicalGradWgt(QWidget* pParentWgt = nullptr) 
            : QWidget{ pParentWgt } {}

    protected:
        virtual void paintEvent(QPaintEvent*) final override {
            QPainter painter{ this };
            QConicalGradient grad{ double(width() / 2), double(height() / 2), 0 };
            grad.setColorAt(0, Qt::red);
            grad.setColorAt(0.4, Qt::green);
            grad.setColorAt(0.8, Qt::blue);
            grad.setColorAt(1, Qt::red);
            painter.setBrush(grad);
            painter.drawRect(rect());
        }
};


class RadialGradWgt : public QWidget {
    public:
        RadialGradWgt(QWidget* pParentWgt = nullptr)
            : QWidget{ pParentWgt } {}

    protected:
        void paintEvent(QPaintEvent*) final override {
            QPainter painter{ this };
            QPointF ptCenter{ rect().center() };
            QRadialGradient grad{ ptCenter, double(width() / 2), ptCenter };
            grad.setColorAt(0, Qt::red);
            grad.setColorAt(0.5, Qt::green);
            grad.setColorAt(1, Qt::blue);
            painter.setBrush(grad);
            painter.drawRect(rect());
        }
};


int main(int argc, char** argv) {
    QApplication app{ argc, argv };

    LinearGradWgt* pLinearGradWgt{ new LinearGradWgt{} };
    ConicalGradWgt* pConicalGradWgt{ new ConicalGradWgt{} };
    RadialGradWgt* pRadialGradWgt{ new RadialGradWgt{} };

    QVBoxLayout* pVBoxLayout{ new QVBoxLayout{} };
    pVBoxLayout->setMargin(5);
    pVBoxLayout->setSpacing(10);
    pVBoxLayout->addWidget(pLinearGradWgt);
    pVBoxLayout->addWidget(pConicalGradWgt);
    pVBoxLayout->addWidget(pRadialGradWgt);

    QWidget containerWgt{};
    containerWgt.setLayout(pVBoxLayout);
    containerWgt.resize(450, 300);
    containerWgt.show();

    return app.exec();
}
