#include <QApplication>
#include <QLabel>

#include <QWizard>
#include <QVBoxLayout>


class Wizard : public QWizard {
private:
    QWizardPage* createPage(QWidget* pWgt, QString strTitle) {
        QWizardPage* pPage = new QWizardPage;
        pPage->setTitle(strTitle);
        
        QVBoxLayout* pLayout = new QVBoxLayout;
        pLayout->addWidget(pWgt);
        pPage->setLayout(pLayout);
        
        return pPage;
    }
    
public:
    Wizard(QWidget* pParentWgt = nullptr) : QWizard{ pParentWgt } {
        addPage(createPage(new QLabel("<h1>label 1</h1>"), "One"));
        addPage(createPage(new QLabel("<h1>label 2</h1>"), "Two"));
        addPage(createPage(new QLabel("<h1>label 3</h1>"), "Three"));
    }
};

int main(int argc, char** argv) {
    QApplication app{ argc, argv };

    QLabel label{ "e.g" };
    label.show();
    
    Wizard wizard{};
    wizard.show();

    return app.exec();
}