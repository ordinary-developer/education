#pragma once

#include <QObject>

class Calculation : public QObject {
Q_OBJECT
private:
	Q_PROPERTY(qulonglong input WRITE  setInputValue
								READ   inputValue
								NOTIFY inputValueChanged)
								
	Q_PROPERTY(qulonglong result READ   resultValue
								 NOTIFY resultValueChanged)

	qulonglong m_nInput;
	qulonglong m_nResult;

public:
	Calculation(QObject * pObj = nullptr);
	
	Q_INVOKABLE qulonglong factorial(const qulonglong & n);
	
	qulonglong inputValue() const;
	void setInputValue(const qulonglong&);
	qulonglong resultValue() const;
	
signals:
	void inputValueChanged(qulonglong);
	void resultValueChanged(qulonglong);
};
