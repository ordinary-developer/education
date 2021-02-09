#include <QApplication>
#include <QFileSystemWatcher>
#include "Viewer.h"


int main(int argc, char** argv) { 
    QApplication app{ argc, argv };
    
    QFileSystemWatcher watcher{};
    Viewer viewer{};
    
    QStringList args = app.arguments();
    args.removeFirst();
    
    watcher.addPaths(args);
    
    viewer.append("watching files: " + watcher.files().join(";"));
    viewer.append("watching dirs: " + watcher.directories().join(";"));
    viewer.show();
    
    QObject::connect(&watcher, &QFileSystemWatcher::directoryChanged,
        &viewer, &Viewer::slotDirChanged);
    QObject::connect(&watcher, &QFileSystemWatcher::fileChanged,
        &viewer, &Viewer::slotFileChanged);
    
    return app.exec();
}
