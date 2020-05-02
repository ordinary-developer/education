#include <QtWidgets>

class FillRectWgt : public QWidget {
    public:
        FillRectWgt(QWidget* pParentWgt = nullptr)
            : QWidget{ pParentWgt } {}

    protected:
        virtual void paintEvent(QPaintEvent*) final override {
            QPainter painter{ this };
            QBrush brush{ Qt::red, Qt::Dense4Pattern };
            painter.fillRect(10, 10, 100, 100, brush);
            painter.eraseRect(20, 20, 80, 80);
        }
};


int main(int argc, char** argv) {
    QApplication app{ argc, argv };

    FillRectWgt wgt{};
    wgt.resize(300, 300);
    wgt.show();

    return app.exec();
}

