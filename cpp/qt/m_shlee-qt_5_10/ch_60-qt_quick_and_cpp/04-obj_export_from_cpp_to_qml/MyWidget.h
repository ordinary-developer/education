#pragma once

#include <QWidget>

class MyWidget : public QWidget {
	Q_OBJECT
public:
	MyWidget(QWidget * pWgt = nullptr);
	
public slots:
	void slotDisplayDialog();
};
