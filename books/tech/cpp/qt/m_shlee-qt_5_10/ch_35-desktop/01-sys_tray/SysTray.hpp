#pragma once

#include <QLabel>

class QSystemTrayIcon;
class QMenu;


class SysTray final : public QLabel {
    Q_OBJECT
    public:
        SysTray(QWidget* parentWgt = nullptr);

    public slots:
        void slotShowHide();
        void slotShowMessage();
        void slotChangeIcon();

    protected:
        virtual void closeEvent(QCloseEvent*) final override;

    private:
        QSystemTrayIcon* trayIcon_;
        QMenu* trayIconMenu_;
        bool iconSwitcher_;
};
