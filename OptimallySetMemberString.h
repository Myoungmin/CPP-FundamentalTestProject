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
	
	// l-value 문자열 변수가 대입될 때
	// 멤버함수 parameter를 value로 받으면 스택에 복사된다.
	// move를 통해 멤버변수로 소유권이 변경된다.
	// 스택에 존재하던 파라미터는 사라진다.
	// 최종적으로 1 copy로 멤버 문자열 설정이 이루어진다.
	optimal.setName(s); // 1 copy 
	
	// r-value 문자열이 대입될 때
	// Copy Elision으로 복사없이 파라미터로 설정된다.
	// move를 통해 멤버변수로 소유권이 변경된다.
	// 최종적으로 0 copy로 멤버 분자열 설정이 이루어진다.
	optimal.setName("Setting");//0 copy
}



