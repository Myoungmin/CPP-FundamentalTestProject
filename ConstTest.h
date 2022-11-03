#pragma once
#include <iostream>
#include <string>
#include <vector>

class ConstTest
{
public:
    // 메서드 안에서 const로 받은 것을 변경할 수 없다.
    void setName(const std::string strName);
    // 멤버변수를 반환 받은 곳에서 그 값을 수정하지 않는다는 것을 보장한다.
    const std::string& getNameRef() const;
    // 클래스의 멥버변수를 바꾸지 않는다는 것을 보장한다.
    void printName() const;

    void setNameFromVect(std::vector<std::string>& inputVect);
    // inputVect를 바꾸지  않는다는 것을 보장한다.
    void setNameFromConstVect(const std::vector<std::string>& inputVect);

private:
    std::string m_strName;
};

