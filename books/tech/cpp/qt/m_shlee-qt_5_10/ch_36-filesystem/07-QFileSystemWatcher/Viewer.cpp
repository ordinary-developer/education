#include "Viewer.h"

// CTOR/DTOR
Viewer::Viewer(QWidget* parentWgt /* = nullptr */) : QTextEdit(parentWgt) {
    setWindowTitle("file system watcher");
}


// SLOTS
void Viewer::slotDirChanged(const QString& str) {
    append("directory changed: " + str);
}

void Viewer::slotFileChanged(const QString& str) {
    append("file changed: " + str);
}
