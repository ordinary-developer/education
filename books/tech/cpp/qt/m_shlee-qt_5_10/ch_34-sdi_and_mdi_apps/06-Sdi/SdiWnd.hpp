#pragma once

#include <QMainWindow>


class SdiWnd : public QMainWindow {
    Q_OBJECT
    public:
        SdiWnd(QWidget * parentWgt = nullptr);

    public slots:
        void slotAbout();
        void slotChangeWindowTitle(const QString& str);
};
