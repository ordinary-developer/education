#include <QApplication>
#include <QLabel>
#include <QProgressDialog>
#include <QMessageBox>


int main(int argc, char** argv) {
    QApplication app{ argc, argv };

    const int n{ 100'000 };

    auto progressDlg =
        new QProgressDialog{ "processing the data...", "&cancel", 0, n };
    progressDlg->setMinimumDuration(0);
    progressDlg->setWindowTitle("please wait");
    
    for (int i = 0; i < n; ++i) {
        progressDlg->setValue(i);
        qApp->processEvents();
        if (progressDlg->wasCanceled())
            break;
    }
    
    progressDlg->setValue(n);
    delete progressDlg;
    progressDlg = nullptr;
    
    QLabel label{ "e.g." };
    label.show();

    return app.exec();
}