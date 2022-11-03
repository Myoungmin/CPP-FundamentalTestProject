#include "ConstTest.h"

void ConstTest::setName(const std::string strName)
{
	//strName = "changed";	// �޼��� �ȿ��� const�� ���� ���� ������ �� ����.
	m_strName = strName;
}

const std::string& ConstTest::getNameRef() const
{
	//m_strName = "changed";	// ����� ����� �� ����.
	return m_strName;
}

void ConstTest::printName() const
{
	//m_strName = "changed";	// ����� ����� �� ����.
	std::cout << m_strName << std::endl;
}

void ConstTest::setNameFromVect(std::vector<std::string>& inputVect)
{
	inputVect[0] = "changed";
	m_strName = inputVect[0];
}

void ConstTest::setNameFromConstVect(const std::vector<std::string>& inputVect)
{
	//inputVect[0] = "changed";		// inputVect�� �ٲ���  �ʴ´ٴ� ���� �����Ѵ�.
	m_strName = inputVect[0];
}

