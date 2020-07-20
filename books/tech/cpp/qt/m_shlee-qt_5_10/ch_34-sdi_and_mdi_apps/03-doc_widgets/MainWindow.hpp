#pragma once

#include <QMainWindow>
#include <QDockWidget>
#include <QLabel>


class MainWindow : public QMainWindow {
    Q_OBJECT
    public:
        MainWindow(QWidget* pWgt = nullptr) : QMainWindow{ pWgt } {
            QDockWidget* pDock = new QDockWidget{ "my dock", this };
            QLabel* pLbl = new QLabel{ "label in dock", pDock };
            pDock->setWidget(pLbl);
            addDockWidget(Qt::LeftDockWidgetArea, pDock);

            pDock->setAllowedAreas(Qt::BottomDockWidgetArea | Qt::TopDockWidgetArea);

            pDock->setFeatures(QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetFloatable);
        }
};
