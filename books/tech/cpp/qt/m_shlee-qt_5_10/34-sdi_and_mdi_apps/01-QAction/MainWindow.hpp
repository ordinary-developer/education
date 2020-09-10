#pragma once

#include <QMainWindow>
#include <QMessageBox>
#include <QMenuBar>
#include <QToolBar>
#include <QAction>
#include <QKeySequence>


class MainWindow : public QMainWindow {
    Q_OBJECT
    public:
        MainWindow(QWidget* pWgt = nullptr) : QMainWindow{ pWgt } {
            QAction* pactSave = new QAction{ "file save action", 0 };
            pactSave->setText("&Save");
            pactSave->setShortcut(QKeySequence{"CTRL+S"});
            pactSave->setToolTip("Save Document");
            pactSave->setStatusTip("Save the file to disk");
            pactSave->setWhatsThis("Save the file to disk");
            pactSave->setIcon(QPixmap{ ":/img.png" });
            QObject::connect(pactSave, &QAction::triggered, this, &MainWindow::slotSave);
            
            menuBar()->addMenu("File")->addAction(pactSave);
            addToolBar("toolbar")->addAction(pactSave);
        }

    private slots:
        void slotSave() { QMessageBox::information(0, "caption", "text"); }
};
