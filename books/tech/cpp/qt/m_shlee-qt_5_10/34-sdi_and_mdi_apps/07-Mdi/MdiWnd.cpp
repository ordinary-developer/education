#include "MdiWnd.hpp"
#include "DocWnd.hpp"

#include <QMdiArea>
#include <QMenu>
#include <QSignalMapper>
#include <QToolBar>
#include <QMenuBar>
#include <QStatusBar>
#include <QApplication>
#include <QMdiSubWindow>
#include <QMessageBox>


// ctor
MdiWnd::MdiWnd(QWidget* parentWgt /* = nullptr */) 
    : QMainWindow{parentWgt}
{
    QAction* actNew = new QAction{ "New File", nullptr };
    actNew->setText("&New");
    actNew->setShortcut(QKeySequence{ "CTRL + N"} );
    actNew->setToolTip("New Document");
    actNew->setStatusTip("Create a new file");
    actNew->setWhatsThis("Create a new file");
    actNew->setIcon(QPixmap{ ":/filenew.png" });
    QObject::connect(actNew, &QAction::triggered, this, &MdiWnd::slotNewDoc);

    QAction* actOpen = new QAction{ "Open File", nullptr };
    actOpen->setText("&Open...");
    actOpen->setShortcut(QKeySequence{ "CTRL + O" });
    actOpen->setToolTip("Open Document");
    actOpen->setStatusTip("Open an existing file");
    actOpen->setWhatsThis("Open an existing file");
    actOpen->setIcon(QPixmap{ ":/fileopen.png" });
    QObject::connect(actOpen, &QAction::triggered, this, &MdiWnd::slotLoad);

    QAction* actSave = new QAction{ "Save File", nullptr };
    actSave->setText("&Save");
    actSave->setShortcut(QKeySequence{ "CTRL + S" });
    actSave->setToolTip("Save Document");
    actSave->setStatusTip("Save the file to a disk");
    actSave->setWhatsThis("Save the file to a disk");
    actSave->setIcon(QPixmap{ ":/filesave.png" });
    QObject::connect(actSave, &QAction::triggered, this, &MdiWnd::slotSave);

    QToolBar* toolbar = new QToolBar{ "File Operations" };
    toolbar->addAction(actNew);
    toolbar->addAction(actOpen);
    toolbar->addAction(actSave);
    addToolBar(Qt::TopToolBarArea, toolbar);

    QMenu* menuFile = new QMenu{ "&File" };
    menuFile->addAction(actNew);
    menuFile->addAction(actOpen);
    menuFile->addAction(actSave);
    menuFile->addAction("Save &As...", this, &MdiWnd::slotSaveAs);
    menuFile->addSeparator();
    menuFile->addAction("&Quit", qApp, 
        &QApplication::closeAllWindows, QKeySequence{ "CTRL + Q" });
    menuBar()->addMenu(menuFile);

    menuWnd_ = new QMenu{ "&Windows" };
    menuBar()->addMenu(menuWnd_);
    QObject::connect(menuWnd_, &QMenu::aboutToShow, this, &MdiWnd::slotWindows);
    menuBar()->addSeparator();

    QMenu* menuHelp = new QMenu{ "&Help" };
    menuHelp->addAction("&About", this, &MdiWnd::slotAbout, Qt::Key_F1);
    menuBar()->addMenu(menuHelp);

    mdiArea_ = new QMdiArea{};
    mdiArea_->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    mdiArea_->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    setCentralWidget(mdiArea_);

    signalMapper_ = new QSignalMapper{this};
    QObject::connect(
        signalMapper_,
        static_cast<void (QSignalMapper::*)(QWidget*)>(&QSignalMapper::mapped),
        this,
        &MdiWnd::slotSetActiveSubWindow);

    statusBar()->showMessage("ready", 3000);
}

// private slots
void MdiWnd::slotChangeWindowTitle(QString const& str) {
    qobject_cast<DocWnd*>(sender())->setWindowTitle(str);
}

void MdiWnd::slotNewDoc() {
    createNewDoc()->show();
}

void MdiWnd::slotLoad() {
    DocWnd* doc = createNewDoc();
    doc->slotLoad();
    doc->show();
}

void MdiWnd::slotSave() {
    if (DocWnd* doc = qobject_cast<DocWnd*>(mdiArea_->activeSubWindow())) {
        doc->slotSave();
    }
}

void MdiWnd::slotSaveAs() {
    if (DocWnd* doc = qobject_cast<DocWnd*>(mdiArea_->activeSubWindow()))
        doc->slotSaveAs();
}

void MdiWnd::slotAbout() {
    QMessageBox::about(this, "Application", "MDI Example");
}

void MdiWnd::slotWindows() {
    menuWnd_->clear();
    
    QAction* action = menuWnd_->addAction(
        "&Cascade", mdiArea_, &QMdiArea::cascadeSubWindows);
    action->setEnabled(not mdiArea_->subWindowList().isEmpty());
    action = menuWnd_->addAction(
        "&Title", mdiArea_, &QMdiArea::tileSubWindows);
    action->setEnabled(not mdiArea_->subWindowList().isEmpty());

    menuWnd_->addSeparator();

    QList<QMdiSubWindow*> listDoc = mdiArea_->subWindowList();
    for (int i{0}, in{listDoc.size()}; i < in; ++i) {
        action = menuWnd_->addAction(listDoc.at(i)->windowTitle());
        action->setCheckable(true);
        action->setChecked(mdiArea_->activeSubWindow() == listDoc.at(i));
        QObject::connect(action, &QAction::triggered, 
            signalMapper_, static_cast<void (QSignalMapper::*)()>(&QSignalMapper::map));
        signalMapper_->setMapping(action, listDoc.at(i));
    }

}
void MdiWnd::slotSetActiveSubWindow(QWidget* wgt) {
    if (wgt)
        mdiArea_->setActiveSubWindow(qobject_cast<QMdiSubWindow*>(wgt));
}

// private impl
DocWnd* MdiWnd::createNewDoc() {
    DocWnd* doc = new DocWnd{};

    mdiArea_->addSubWindow(doc);
    doc->setAttribute(Qt::WA_DeleteOnClose);
    doc->setWindowTitle("Unnamed Document");
    doc->setWindowIcon(QPixmap(":/filenew.png"));
    QObject::connect(doc, &DocWnd::changeWindowTitle,
        this, &MdiWnd::slotChangeWindowTitle);

    return doc;
}