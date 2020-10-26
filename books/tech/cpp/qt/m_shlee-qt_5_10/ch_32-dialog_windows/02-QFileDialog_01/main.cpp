#include <QObject>
#include <QApplication>
#include <QPixmap>
#include <QString>
#include <QFileDialog>
#include <QLabel>


int main(int argc, char** argv) {
    QApplication app{ argc, argv };

    QPixmap pix{ 320, 200 };
    QString strFilter{};

    QString const& str = QFileDialog::getSaveFileName(
        nullptr, QObject::tr("save pixmap"), "pixmap", "*.png ;; *.jpg ;; *.bmp", &strFilter);
        
    if (not str.isEmpty())
        pix.save(str,
            (strFilter.contains("jpg") ? "JPG" : (strFilter.contains("bmp") ? "BMP" : "PNG")));

    QLabel label{"Hello world"};
    label.show();

    return app.exec();
}