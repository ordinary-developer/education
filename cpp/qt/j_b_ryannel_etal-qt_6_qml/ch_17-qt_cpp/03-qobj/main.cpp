#include <QCoreApplication>
#include <QDebug>
#include "Person.h"

int main(int argc, char *argv[])
{	
	QCoreApplication app{argc, argv};
	
	Person * person = new Person();
	qDebug() << person->metaObject()->className();
	qDebug() << Person::staticMetaObject.className();
	
	return 0;
} 
