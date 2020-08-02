#include "SdiWnd.hpp"
#include "DocWnd.hpp"

#include <QMessageBox>
#include <QMenu>
#include <QApplication>
#include <QMenuBar>
#include <QStatusBar>


SdiWnd::SdiWnd(QWidget* parentWgt /* = nullptr */) 
    : QMainWindow{ parentWgt }
{
    DocWnd * doc = new DocWnd{};

    QMenu* menuFile = new QMenu{ "&File" };
    menuFile->addAction("&Open...", doc, &DocWnd::slotLoad, QKeySequence{"CTRL+O"});
    menuFile->addAction("&Save...", doc, &DocWnd::slotSave, QKeySequence{"CTRL+S"});
    menuFile->addSeparator();
    menuFile->addAction("&Quit", qApp, &QApplication::quit, QKeySequence{"CTRL+Q"});

    QMenu* menuHelp = new QMenu{ "&Help" };
    menuHelp->addAction("&About", this, &SdiWnd::slotAbout, Qt::Key_F1);

    menuBar()->addMenu(menuFile);
    menuBar()->addMenu(menuHelp);

    setCentralWidget(doc);
    QObject::connect(doc, &DocWnd::changeWindowTitle,
        this, &SdiWnd::slotChangeWindowTitle);

    statusBar()->showMessage("ready", 2000);
}

void SdiWnd::slotAbout() {
    QMessageBox::about(this, "application", "sdi example");
}

void SdiWnd::slotChangeWindowTitle(const QString& str) {
    setWindowTitle(str);
}
