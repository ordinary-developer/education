#pragma once

#include <QTextEdit>

class Viewer : public QTextEdit {
    Q_OBJECT
    public:
        Viewer(QWidget* parentWgt = nullptr);
        
    public slots:
        void slotDirChanged(const QString&);
        void slotFileChanged(const QString&);
};
