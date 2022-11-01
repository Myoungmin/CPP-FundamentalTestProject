#pragma once
#include <string>

class OptimallySetMemberString
{
public:
	void setName(std::string name)
	{
		m_strName = std::move(name);
	};
private:
	std::string m_strName;
};

void OptimallySet()
{
	OptimallySetMemberString optimal;
	std::string s = "optimal";
	
	// l-value ���ڿ� ������ ���Ե� ��
	// ����Լ� parameter�� value�� ������ ���ÿ� ����ȴ�.
	// move�� ���� ��������� �������� ����ȴ�.
	// ���ÿ� �����ϴ� �Ķ���ʹ� �������.
	// ���������� 1 copy�� ��� ���ڿ� ������ �̷������.
	optimal.setName(s); // 1 copy 
	
	// r-value ���ڿ��� ���Ե� ��
	// Copy Elision���� ������� �Ķ���ͷ� �����ȴ�.
	// move�� ���� ��������� �������� ����ȴ�.
	// ���������� 0 copy�� ��� ���ڿ� ������ �̷������.
	optimal.setName("Setting");//0 copy
}



