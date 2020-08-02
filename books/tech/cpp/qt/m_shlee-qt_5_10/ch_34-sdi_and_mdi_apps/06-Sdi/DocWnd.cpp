#include "DocWnd.hpp"

#include <QFileDialog>
#include <QFile>
#include <QTextStream>


DocWnd::DocWnd(QWidget * pWgt /* = nulptr */) : QTextEdit{pWgt} {}

void DocWnd::slotLoad() {
    QString const& str = QFileDialog::getOpenFileName();
    if (str.isEmpty())
        return;

    QFile file{str};
    if (not file.open(QIODevice::ReadOnly))
        return;

    QTextStream stream(&file);
    setPlainText(stream.readAll());
    file.close();

    strFileName_ = str;
    emit changeWindowTitle(strFileName_);
}

void DocWnd::slotSave() {
    if (strFileName_.isEmpty()) {
        slotSaveAs();
        return;
    }

    QFile file(strFileName_);
    if (not file.open(QIODevice::WriteOnly))
        return;

    QTextStream(&file) << toPlainText();
    file.close();
    emit changeWindowTitle(strFileName_);
}

void DocWnd::slotSaveAs() {
    QString const& str = QFileDialog::getSaveFileName(nullptr, strFileName_);
    if (str.isEmpty())
        return;

    strFileName_ = str;
    slotSave();
}
