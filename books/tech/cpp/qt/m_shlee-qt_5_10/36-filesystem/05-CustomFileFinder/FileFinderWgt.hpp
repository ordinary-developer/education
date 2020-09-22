#pragma once

#include <QWidget>

class QDir;
class QLineEdit;
class QTextEdit;


class FileFinderWgt final : public QWidget {
    Q_OBJECT

public:
    FileFinderWgt(QWidget *parentWgt = nullptr);

public slots:
    void slotBrowse();
    void slotFind();

private:
    void start(QDir const& dir);

    QLineEdit* dirField_;
    QLineEdit* maskField_;
    QTextEdit* resultField_;
};
