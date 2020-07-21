#pragma once

#include <QMainWindow>
#include <QLabel>
#include <QStatusBar>
#include <QMouseEvent>


class MainWindow final : public QMainWindow {
    Q_OBJECT
    public:
        MainWindow(QWidget* pWgt = nullptr) : QMainWindow{ pWgt } {
            setMouseTracking(true);
            
            xLbl_ = new QLabel{this};
            yLbl_ = new QLabel{this};
            statusBar()->addWidget(xLbl_);
            statusBar()->addWidget(yLbl_);
        }

    protected:
        virtual void mouseMoveEvent(QMouseEvent* pEvent) final override {
            xLbl_->setText("x = " + QString{}.setNum(pEvent->x()));
            yLbl_->setText("y = " + QString{}.setNum(pEvent->y()));
        }
    
    private:
        QLabel *xLbl_, *yLbl_;
};
