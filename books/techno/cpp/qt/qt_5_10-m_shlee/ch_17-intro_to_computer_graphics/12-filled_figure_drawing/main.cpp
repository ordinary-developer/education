#include <QtWidgets>

class FilledRectWgt : public QWidget {
    public:
        FilledRectWgt(QWidget* pParentWgt = nullptr) 
            : QWidget{ pParentWgt } {}


    protected:
        virtual void paintEvent(QPaintEvent*) final override {
            QPainter painter{ this };
            painter.setRenderHint(QPainter::Antialiasing, true);
            painter.setBrush(QBrush{ Qt::red, Qt::DiagCrossPattern });
            painter.setPen(QPen{ Qt::blue, 3, Qt::DashLine });
            painter.drawRect(QRect{ 10, 10, 110, 70 });
        }
};

class RoundedCornerRectWgt : public QWidget {
    public:
        RoundedCornerRectWgt(QWidget* pParentWgt = nullptr)
            : QWidget{ pParentWgt } {}

    protected:
        virtual void paintEvent(QPaintEvent*) final override {
            QPainter painter{ this };
            painter.setRenderHint(QPainter::Antialiasing, true);
            painter.setBrush(QBrush{ Qt::green });
            painter.setPen(QPen{ Qt::black });
            painter.drawRoundRect(QRect{ 10, 10, 110, 70 }, 30, 30);
        }
};

class FilledEllipseWgt : public QWidget {
    public:
        FilledEllipseWgt(QWidget* pParentWgt = nullptr)
            : QWidget{ pParentWgt } {}

    protected:
        virtual void paintEvent(QPaintEvent*) final override {
            QPainter painter{ this };
            painter.setRenderHint(QPainter::Antialiasing, true);
            painter.setBrush(QBrush{ Qt::green, Qt::CrossPattern });
            painter.setPen(QPen{ Qt::red, 3, Qt::DotLine });
            painter.drawEllipse(QRect{ 10, 10, 110, 70 });
        }
};

class ChordWgt : public QWidget {
    public:
        ChordWgt(QWidget* pParentWgt = nullptr) 
            : QWidget{ pParentWgt } {}

    protected:
        virtual void paintEvent(QPaintEvent*) final override {
            QPainter painter{ this };
            painter.setRenderHint(QPainter::Antialiasing, true);
            painter.setBrush(QBrush{ Qt::yellow });
            painter.setPen(QPen{ Qt::blue });
            painter.drawChord(QRect{ 10, 10, 110, 70 }, 45 * 16, 180 * 16);
        }
};

class PieChartImitateWgt : public QWidget {
    public:
        PieChartImitateWgt(QWidget* pParentWgt = nullptr)
            : QWidget{ pParentWgt } {}

    protected:
        virtual void paintEvent(QPaintEvent*) final override {
            QPainter painter{ this };
            painter.setRenderHint(QPainter::Antialiasing, true);
            painter.setBrush(QBrush{ Qt::black, Qt::BDiagPattern });
            painter.setPen(QPen{ Qt::blue, 4 });
            painter.drawPie(QRect{ 10, 10, 110, 70 }, 90 * 16, 270 * 16);
        }
};

class FilledPolygonWgt : public QWidget {
    public:
        FilledPolygonWgt(QWidget* pParentWgt = nullptr)
            : QWidget{ pParentWgt } {}

    protected:
        virtual void paintEvent(QPaintEvent*) final override {
            QPainter painter{ this };
            painter.setRenderHint(QPainter::Antialiasing, true);
            painter.setBrush(QBrush{ Qt::lightGray });
            painter.setPen(QPen{ Qt::black });

            int const n{8};
            QPolygonF polygon{};
            for (unsigned int i{0}; i < n; ++i) {
                qreal const fAngle = ::qDegreesToRadians(360.0 * i / n);
                qreal const x = 50 + cos(fAngle) * 40;
                qreal const y = 50 + sin(fAngle) * 40;
                polygon << QPointF{ x, y };
            }
            painter.drawPolygon(polygon);
        }
};

int main(int argc, char** argv) {
    QApplication app{ argc, argv };

    FilledRectWgt* pFilledRectWgt{ new FilledRectWgt{} };
    RoundedCornerRectWgt* pRoundedCornerRectWgt{ new RoundedCornerRectWgt{} };
    FilledEllipseWgt* pFilledEllipseWgt{ new FilledEllipseWgt{} };
    ChordWgt* pChordWgt{ new ChordWgt{} };
    PieChartImitateWgt* pPieChartImitateWgt{ new PieChartImitateWgt{} };
    FilledPolygonWgt* pFilledPolygonWgt{ new FilledPolygonWgt{} };

    QVBoxLayout* pLayout{ new QVBoxLayout{} };
    pLayout->setMargin(5);
    pLayout->setSpacing(10);
    pLayout->addWidget(pFilledRectWgt);
    pLayout->addWidget(pRoundedCornerRectWgt);
    pLayout->addWidget(pFilledEllipseWgt);
    pLayout->addWidget(pChordWgt);
    pLayout->addWidget(pPieChartImitateWgt);
    pLayout->addWidget(pFilledPolygonWgt);

    QWidget mainWgt{};
    mainWgt.setLayout(pLayout);
    mainWgt.resize(150, 650);
    mainWgt.show();

    return app.exec();
}

