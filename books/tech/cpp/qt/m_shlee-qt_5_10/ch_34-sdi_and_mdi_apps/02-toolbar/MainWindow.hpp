#pragma once

#include <QMainWindow>
#include <QMessageBox>
#include <QToolBar>
#include <QPixmap>


class MainWindow : public QMainWindow {
    Q_OBJECT
    public:
        MainWindow(QWidget* pWgt = nullptr) : QMainWindow{pWgt} {
            addToolBar(Qt::TopToolBarArea, createToolbar());
            addToolBar(Qt::BottomToolBarArea, createToolbar());
            addToolBar(Qt::LeftToolBarArea, createToolbar());
            addToolBar(Qt::RightToolBarArea, createToolbar());
        }
        
    private:
        QToolBar* createToolbar() {
            QToolBar* pToolbar = new QToolBar("Linker Toolbar");
            
            pToolbar->addAction(QPixmap{ ":/img1.png" }, "1", this, &MainWindow::slotNotImpl);
            pToolbar->addAction(QPixmap{ ":/img2.png" }, "2", this, &MainWindow::slotNotImpl);
            pToolbar->addSeparator();
            pToolbar->addAction(QPixmap{ ":/img3.png" }, "3", this, &MainWindow::slotNotImpl);
            pToolbar->addAction(QPixmap{ ":/img4.png" }, "4", this, &MainWindow::slotNotImpl);
            
            return pToolbar;
        }
        
    public slots:
        void slotNotImpl() { QMessageBox::information(0, "Message", "Not implemented"); }
};