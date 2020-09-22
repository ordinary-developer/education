#include "FileFinderWgt.hpp"

#include <QString>
#include <QDir>
#include <QLineEdit>
#include <QTextEdit>
#include <QLabel>
#include <QPushButton>
#include <QPixmap>
#include <QGridLayout>
#include <QFileDialog>
#include <QApplication>


// ctor
FileFinderWgt::FileFinderWgt(QWidget *parentWgt /* = nullptr */) 
    : QWidget{ parentWgt },
    dirField_{ new QLineEdit{ QCoreApplication::applicationDirPath() } },
    maskField_{ new QLineEdit{"*"} }, resultField_{ new QTextEdit{} }
{
    QLabel* dirBuddyLbl{ new QLabel{ "&directory" } };
    QLabel* maskBuddyLbl{ new QLabel{ "&Mask" } };
    QPushButton *openBtn{ new QPushButton{ QPixmap{ ":/fileopen.png" }, "" } };
    QPushButton *findBtn{ new QPushButton{"&Find"} };

    QObject::connect(openBtn, &QPushButton::clicked, this, &FileFinderWgt::slotBrowse);
    QObject::connect(findBtn, &QPushButton::clicked, this, &FileFinderWgt::slotFind);

    dirBuddyLbl->setBuddy(dirField_);
    maskBuddyLbl->setBuddy(maskField_);

    QGridLayout* gridLayout{ new QGridLayout{} };
    gridLayout->setContentsMargins(5, 5, 5, 5);
    gridLayout->setSpacing(15);
    gridLayout->addWidget(dirBuddyLbl, 0, 0);
    gridLayout->addWidget(maskBuddyLbl, 1, 0);
    gridLayout->addWidget(dirField_, 0, 1);
    gridLayout->addWidget(maskField_, 1, 1);
    gridLayout->addWidget(openBtn, 0, 2);
    gridLayout->addWidget(findBtn, 1, 2);
    gridLayout->addWidget(resultField_, 2, 0, 1, 3);
    setLayout(gridLayout);
}

// slots
void FileFinderWgt::slotBrowse() {
    QString const& str = QFileDialog::getExistingDirectory(
        0, "Select a directory", dirField_->text());

    if (not str.isEmpty())
        dirField_->setText(str);
}

void FileFinderWgt::slotFind() {
    start(QDir{ dirField_->text() });
}

// logic
void FileFinderWgt::start(QDir const& dir) {
    QApplication::processEvents();

    QStringList files = 
        dir.entryList(maskField_->text().split(" "), QDir::Files);

    foreach (QString file, files)
        resultField_->append(dir.absoluteFilePath(file));

    QStringList subdirs = dir.entryList(QDir::Dirs);
    foreach (QString subdir, subdirs)
        if ("." != subdir and ".." != subdir)
            start(QDir{ dir.absoluteFilePath(subdir) });
}
