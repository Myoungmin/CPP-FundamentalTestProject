#pragma once
#include <iostream>
#include <string>
#include <vector>

class ConstTest
{
public:
    // �޼��� �ȿ��� const�� ���� ���� ������ �� ����.
    void setName(const std::string strName);
    // ��������� ��ȯ ���� ������ �� ���� �������� �ʴ´ٴ� ���� �����Ѵ�.
    const std::string& getNameRef() const;
    // Ŭ������ ��������� �ٲ��� �ʴ´ٴ� ���� �����Ѵ�.
    void printName() const;

    void setNameFromVect(std::vector<std::string>& inputVect);
    // inputVect�� �ٲ���  �ʴ´ٴ� ���� �����Ѵ�.
    void setNameFromConstVect(const std::vector<std::string>& inputVect);

private:
    std::string m_strName;
};

