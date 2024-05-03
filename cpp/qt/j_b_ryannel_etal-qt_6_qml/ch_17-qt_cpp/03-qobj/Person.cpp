#include "Person.h"


Person::Person(QObject * parent /* = nullptr */)
	: QObject{parent}, m_gender{ Person::Unknown }
{
}


QString Person::name() const
{
	return m_name;
}

Person::Gender Person::gender() const
{
	return m_gender;
}

void Person::setName(const QString & name)
{
	if (m_name != name) {
		m_name = name;
		emit nameChanged(m_name);
	}
}

void Person::setGender(Person::Gender gender)
{
	if (m_gender != gender) {
		m_gender = gender;
		emit genderChanged(m_gender);
	}
}
