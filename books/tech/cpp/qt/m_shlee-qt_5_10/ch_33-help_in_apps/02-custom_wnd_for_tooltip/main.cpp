#include <QApplication>
#include <QLabel>
#include <QHelpEvent>
#include <QTimer>


class MyWidget final : public QWidget {
    public:
        MyWidget(QWidget* pWgt = nullptr) : QWidget{ pWgt }, toolTipLbl_{ new QLabel{} } {
            toolTipLbl_->setWindowFlags(Qt::ToolTip);
        }
        
    protected:
        virtual bool event(QEvent* pEvent) final override {
            if (QEvent::ToolTip != pEvent->type()) 
                return QWidget::event(pEvent);

            const QHelpEvent* const pHelpEvent = static_cast<QHelpEvent*>(pEvent);
            toolTipLbl_->move(pHelpEvent->globalPos());
            toolTipLbl_->setText(toolTip());
            toolTipLbl_->show();
            QTimer::singleShot(3000, toolTipLbl_, &QLabel::hide);

            return true;
        }

    private:
        QLabel* toolTipLbl_;
};

int main(int argc, char** argv) {
    QApplication app{ argc, argv };

    MyWidget wgt{};
    wgt.setFixedSize(70, 70);
    wgt.setToolTip("<h1>tooltip</h1>");
    wgt.show();

    return app.exec();
}
