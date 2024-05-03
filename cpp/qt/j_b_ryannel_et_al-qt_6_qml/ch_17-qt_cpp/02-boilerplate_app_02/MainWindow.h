#pragma once

#include <QtWidgets>


class MainWindow : public QMainWindow
{
public:
	MainWindow(QWidget * parent = nullptr);
	~MainWindow();
	
public slots:
	void storeContent();
	
private:
	QPushButton * m_button;
};
