#include <QtWidgets>
#include <iostream>

class Wgt : public QWidget {
    public:
        Wgt(QWidget* pParentWgt = nullptr)
            : QWidget{ pParentWgt } {}


    protected:
        virtual void paintEvent(QPaintEvent*) final override {
            QPainterPath painterPath{};
            QPointF pt1{ (double)width() , (double)(height() / 2) };
            QPointF pt2{ (double)(width() / 2), (double)(-height()) };
            QPointF pt3{ (double)(width() / 2), (double)(2 * height()) };
            QPointF pt4{ 0, (double)(height() / 2) };
            painterPath.moveTo(pt1);
            painterPath.cubicTo(pt2, pt3, pt4);

            QRect rect(width() / 4, height() / 4, width() / 2, height() / 2);
            painterPath.addRect(rect);
            painterPath.addEllipse(rect);

            QPainter painter{ this };
            painter.drawRect(0, 0, width() - 1, height() - 1);
            painter.setRenderHint(QPainter::Antialiasing, true);
            painter.setPen(QPen{ Qt::blue, 6 });
            painter.drawPath(painterPath);
        }
};


int main(int argc, char** argv) {
    QApplication app{ argc, argv };

    Wgt wgt{};
    wgt.resize(150, 150);
    wgt.show();

    return app.exec();
}

