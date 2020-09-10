#pragma once

#include <QTextEdit>


class DocWnd : public QTextEdit {
    Q_OBJECT
    public:
        DocWnd(QWidget* pWgt = nullptr);

    signals:
        void changeWindowTitle(const QString&);

    public slots:
        void slotLoad();
        void slotSave();
        void slotSaveAs();

    private:
        QString strFileName_;
};
