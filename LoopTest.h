#pragma once
#include <iostream>
#include <string>

void LoopTest()
{
	int nOutVariable = 0;

	for (int i = 0; i < 5; i++)
	{
		// for ���� �߰�ȣ ���� ���� �����ϰ� �߰�ȣ�� Ż���� �� �ٽ� ���ǹ����� �������Ѵ�. 
		// �߰�ȣ�� Ż�� �Ѵٴ� ���� �Լ��� ������ �ٴ� �Ͱ� ����, 
		// �޸𸮿� ����� �ִ� ���������� �޸𸮻󿡼� ������� �ȴ�. 
		// �޸𸮻󿡼� ������� �ǹǷ� �� index���� int nInVariable �� �Ҹ��ϰ�, 
		// ���ο� int nInVariable�� �޸𸮻� ���� �ȴ�.
		int nInVariable = 0;
		nOutVariable++;
		nInVariable++;
		std::cout << "nOutVariable : " << nOutVariable << std::endl;
		std::cout << "nInVariable : " << nInVariable << std::endl;
	}
}