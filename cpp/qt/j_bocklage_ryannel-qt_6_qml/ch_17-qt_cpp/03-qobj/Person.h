#pragma once			

#include <QObject>
#include <QString>

			
class Person : public QObject
{
public:
		enum Gender { Unknown, Male, Female, Other };
		
private:
	Q_OBJECT
	
	Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
	Q_PROPERTY(Gender gender READ gender WRITE setGender NOTIFY genderChanged)
	
	Q_ENUM(Gender)
	
public:
	Person(QObject * parent = nullptr);
	
	
	QString name() const;
	Gender gender() const;
	
public slots:
	void setName(const QString &);
	void setGender(Gender);
	
signals:
	void nameChanged(const QString & name);
	void genderChanged(Gender gender);
	
private:
	QString m_name;
	Gender m_gender;
};
