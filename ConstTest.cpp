#include "ConstTest.h"

void ConstTest::setName(const std::string strName)
{
	//strName = "changed";	// 메서드 안에서 const로 받은 것을 변경할 수 없다.
	m_strName = strName;
}

const std::string& ConstTest::getNameRef() const
{
	//m_strName = "changed";	// 멤버가 변경될 수 없다.
	return m_strName;
}

void ConstTest::printName() const
{
	//m_strName = "changed";	// 멤버가 변경될 수 없다.
	std::cout << m_strName << std::endl;
}

void ConstTest::setNameFromVect(std::vector<std::string>& inputVect)
{
	inputVect[0] = "changed";
	m_strName = inputVect[0];
}

void ConstTest::setNameFromConstVect(const std::vector<std::string>& inputVect)
{
	//inputVect[0] = "changed";		// inputVect를 바꾸지  않는다는 것을 보장한다.
	m_strName = inputVect[0];
}

