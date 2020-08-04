#include "SysTray.hpp"

#include <QSystemTrayIcon>
#include <QMenu>
#include <QAction>
#include <QApplication>
#include <QPixmap>


// ctor
SysTray::SysTray(QWidget* parentWgt /* = nullptr */)
    : QLabel{ "<h1>Appliction Window</h1>", parentWgt },
    iconSwitcher_{false}
{
    setWindowTitle("System Tray");

    QAction* showHideAction = new QAction{ "&Show/Hide Application Window", this };
    QObject::connect(showHideAction, &QAction::triggered,
        this, &SysTray::slotShowHide);

    QAction* showMsgAction = new QAction{ "S&how Message", this };
    QObject::connect(showMsgAction, &QAction::triggered,
        this, &SysTray::slotShowMessage);

    QAction* changeIconAction = new QAction{ "&Change Icon", this };
    QObject::connect(changeIconAction, &QAction::triggered,
        this, &SysTray::slotChangeIcon);

    QAction* quitAction = new QAction{ "&Quit", this };
    QObject::connect(quitAction, &QAction::triggered, qApp, &QApplication::quit);

    trayIconMenu_ = new QMenu{this};
    trayIconMenu_->addAction(showHideAction);
    trayIconMenu_->addAction(showMsgAction);
    trayIconMenu_->addAction(changeIconAction);
    trayIconMenu_->addAction(quitAction);

    trayIcon_ = new QSystemTrayIcon{this};
    trayIcon_->setContextMenu(trayIconMenu_);
    trayIcon_->setToolTip("System Tray");

    slotChangeIcon();

    trayIcon_->show();
}

// public slots
void SysTray::slotShowHide() {
    setVisible(!isVisible());
}

void SysTray::slotShowMessage() {
    trayIcon_->showMessage(
        "For your information",
        "You have seleted the "
        "\"Show Message!\" option",
        QSystemTrayIcon::Information,
        3000);
}

void SysTray::slotChangeIcon() {
    iconSwitcher_ = not iconSwitcher_;
    QString const strPixmapName = (iconSwitcher_ ? ":/img/img1.bmp" : ":/img/img2.bmp");
    trayIcon_->setIcon(QPixmap{ strPixmapName });
}

// protected members
void SysTray::closeEvent(QCloseEvent*) {
    if (trayIcon_->isVisible())
        hide();
}
