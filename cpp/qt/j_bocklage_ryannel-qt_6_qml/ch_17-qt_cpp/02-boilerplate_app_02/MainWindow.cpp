#include "MainWindow.h"


MainWindow::MainWindow(QWidget * parent /* = nullptr */)
	: QMainWindow{parent}
{
	m_button = new QPushButton{"Store Content", this};
	
	setCentralWidget(m_button);
	QObject::connect(m_button, &QPushButton::clicked,
		this, &MainWindow::storeContent);
}

MainWindow::~MainWindow() {}


void MainWindow::storeContent()
{
	qDebug() << "... store content";
	QString msg{"Hello World!"};
	QFile file{QDir::home().absoluteFilePath("out.txt")};
	if (not file.open(QIODevice::WriteOnly)) {
		qWarning() << "Can not open file with write access";
		return;
	}
	
	QTextStream stream{&file};
	stream << msg;
}
