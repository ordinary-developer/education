#pragma once

#include <QWidget>

class QLabel;


class GrabWgt final : public QWidget {
    Q_OBJECT
    public:
        GrabWgt(QWidget* parentWgt = nullptr);

    public slots:
        void slotGrabScreen();

    private:
        QLabel* label_;
};
