#include <QtWidgets>

class ResizeObserver : public QLabel {
    public:
        ResizeObserver(QWidget* parentWidget = nullptr)
            : QLabel(parentWidget)
        {
            setAlignment(Qt::AlignCenter);
        }

    protected:
        virtual void resizeEvent(QResizeEvent* pe) {
            setText(QString("resized")
                + "\n width() = " + QString::number(pe->size().width())
                + "\n height() = " + QString::number(pe->size().height()));
        }
};

int main(int argc, char** argv) {
    QApplication app{ argc, argv };

    ResizeObserver resizeObserverWidget;
    resizeObserverWidget.resize(250, 130);
    resizeObserverWidget.show();

    return app.exec();
}
