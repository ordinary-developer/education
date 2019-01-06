#include <QtWidgets>

class SaveTransformWgt : public QWidget {
    public:
        SaveTransformWgt(QWidget* pParentWgt = nullptr)
            : QWidget{ pParentWgt } {}

    protected:
        virtual void paintEvent(QPaintEvent*) final override {
            QPainter painter{ this };
            painter.drawRect(0, 0, width() - 1, height() - 1);

            painter.save();

            painter.translate(20, 40);
            painter.drawText(rect(), Qt::AlignCenter, "transformed txt");

            painter.restore();
            painter.drawText(rect(), Qt::AlignCenter, "untransformed txt");
        }
};

class MoveWgt : public QWidget {
    public:
        MoveWgt(QWidget* pParentWgt = nullptr) 
            : QWidget{ pParentWgt } {}

    protected:
        virtual void paintEvent(QPaintEvent*) final override {
            QPainter painter{ this };
            painter.drawRect(0, 0, width() - 1, height() - 1);

            painter.drawText(rect(), Qt::AlignCenter, "untransformed txt");

            painter.translate(20, 40);
            painter.drawText(rect(), Qt::AlignCenter, "transformed txt");
        }
};

class ScaleWgt : public QWidget {
    public:
        ScaleWgt(QWidget* pParentWgt = nullptr)
            : QWidget{ pParentWgt } {}

    protected:
        virtual void paintEvent(QPaintEvent*) final override {
            QPainter painter{ this };
            painter.drawRect(0, 0, width() - 1, height() - 1);

            painter.drawText(rect(), Qt::AlignCenter, "untransformed txt");

            painter.scale(1.5, 0.5);
            painter.drawText(rect(), Qt::AlignCenter, "transformed txt");
        }
};

class RotateWgt : public QWidget {
    public:
        RotateWgt(QWidget* pParentWgt = nullptr)
            : QWidget{ pParentWgt } {}

    protected:
        virtual void paintEvent(QPaintEvent*) final override {
            QPainter painter{ this };
            painter.drawRect(0, 0, width() - 1, height() - 1);

            painter.drawText(rect(), Qt::AlignCenter, "untransformed txt");

            painter.rotate(30.0);
            painter.drawText(rect(), Qt::AlignCenter, "transformed txt");
        }
};

class ShearWgt : public QWidget {
    public:
        ShearWgt(QWidget* pParentWgt = nullptr)
            : QWidget{ pParentWgt } {}


    protected:
        virtual void paintEvent(QPaintEvent*) final override {
            QPainter painter{ this };
            painter.drawRect(0, 0, width() - 1, height() - 1);

            painter.drawText(rect(), Qt::AlignCenter, "untransformed txt");

            painter.shear(0.3, 0.0);
            painter.drawText(rect(), Qt::AlignCenter, "transformed txt");
        }
};

class TransformMatrixWgt : public QWidget {
    public:
        TransformMatrixWgt(QWidget* pParentWgt = nullptr)
            : QWidget{ pParentWgt } {}

    protected:
        virtual void paintEvent(QPaintEvent*) final override {
            QPainter painter{ this };
            painter.drawRect(0, 0, width() - 1, height() - 1);

            painter.drawText(rect(), Qt::AlignCenter, "untransformed txt");

            QTransform matrix{};
            matrix.scale(0.7, 0.5);
            matrix.shear(0.2, 0.5);
            matrix.rotate(15);
            painter.setTransform(matrix);
            painter.drawText(rect(), Qt::AlignCenter, "transformed txt");
        }
};

class TransformMatrixFromScratchWgt : public QWidget {
    public:
        TransformMatrixFromScratchWgt(QWidget* pParentWgt = nullptr)
            : QWidget{ pParentWgt } {}

    protected:
        virtual void paintEvent(QPaintEvent*) final override {
            QPainter painter { this };
            painter.drawRect(0, 0, width() - 1, height() - 1);

            painter.drawText(rect(), Qt::AlignCenter, "untransformed txt");

            QTransform matrix{ 1, 0, 0, 1, 20, 10 };
            painter.setTransform(matrix);
            painter.drawText(rect(), Qt::AlignCenter, "transformed txt");
        }
};


int main(int argc, char** argv) {
    QApplication app{ argc, argv };

    SaveTransformWgt* pSaveTransformWgt{ new SaveTransformWgt{} };
    MoveWgt* pMoveWgt{ new MoveWgt{} };
    ScaleWgt* pScaleWgt{ new ScaleWgt{} };
    RotateWgt* pRotateWgt{ new RotateWgt{} };
    ShearWgt* pShearWgt{ new ShearWgt{} };
    TransformMatrixWgt* pTransformMatrixWgt{ new TransformMatrixWgt{} };
    TransformMatrixFromScratchWgt* pTransformMatrixFromScratchWgt{ new TransformMatrixFromScratchWgt{} };

    QVBoxLayout* pLayout{ new QVBoxLayout{} };
    pLayout->setMargin(5);
    pLayout->setSpacing(10);
    pLayout->addWidget(pSaveTransformWgt);
    pLayout->addWidget(pMoveWgt);
    pLayout->addWidget(pScaleWgt);
    pLayout->addWidget(pRotateWgt);
    pLayout->addWidget(pShearWgt);
    pLayout->addWidget(pTransformMatrixWgt);
    pLayout->addWidget(pTransformMatrixFromScratchWgt);

    QWidget mainWgt{};
    mainWgt.setLayout(pLayout);
    mainWgt.resize(150, 650);
    mainWgt.show();

    return app.exec();
}

