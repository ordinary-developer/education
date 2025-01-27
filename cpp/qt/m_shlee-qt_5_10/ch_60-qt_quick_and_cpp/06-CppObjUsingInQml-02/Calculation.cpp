#include "Calculation.h"

Calculation::Calculation(QObject * pObj /* = nullptr */)
	: QObject{pObj}, m_nInput{0}, m_nResult{1}
{}

qulonglong Calculation::factorial(const qulonglong & n)
{
	return n ? (n * factorial(n - 1)) : 1;
}

qulonglong Calculation::inputValue() const
{
	return m_nInput;
}

qulonglong Calculation::resultValue() const
{
	return m_nResult;
}

void Calculation::setInputValue(const qulonglong & n)
{
	m_nInput = n;
	m_nResult = factorial(m_nInput);
	
	emit inputValueChanged(m_nInput);
	emit resultValueChanged(m_nResult);
}