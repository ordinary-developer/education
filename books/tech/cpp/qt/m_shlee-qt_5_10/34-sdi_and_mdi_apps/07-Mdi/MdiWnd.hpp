#pragma once

#include <QMainWindow>

class QMdiArea;
class QMenu;
class QSignalMapper;
class DocWnd;

class MdiWnd : public QMainWindow {
    Q_OBJECT
    public:
        MdiWnd(QWidget* parentWgt = nullptr);

    private slots:
        void slotChangeWindowTitle(QString const& str);

    private slots:
        void slotNewDoc();
        void slotLoad();
        void slotSave();
        void slotSaveAs();
        void slotAbout();
        void slotWindows();
        void slotSetActiveSubWindow(QWidget*);

    private:
        DocWnd* createNewDoc();

        QMdiArea* mdiArea_;
        QMenu* menuWnd_;
        QSignalMapper* signalMapper_;
};
