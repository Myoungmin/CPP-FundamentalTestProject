#pragma once
#include <iostream>
#include <string>

void LoopTest()
{
	int nOutVariable = 0;

	for (int i = 0; i < 5; i++)
	{
		// for 문은 중괄호 안을 전부 실행하고 중괄호를 탈출한 뒤 다시 조건문부터 실행하한다. 
		// 중괄호를 탈출 한다는 것은 함수가 끝났는 다는 것과 같고, 
		// 메모리에 저장되 있던 지역변수가 메모리상에서 사라지게 된다. 
		// 메모리상에서 사라지게 되므로 매 index마다 int nInVariable 는 소멸하고, 
		// 새로운 int nInVariable가 메모리상에 저장 된다.
		int nInVariable = 0;
		nOutVariable++;
		nInVariable++;
		std::cout << "nOutVariable : " << nOutVariable << std::endl;
		std::cout << "nInVariable : " << nInVariable << std::endl;
	}
}