#pragma once

#include <chrono>
#include <iostream>
#include <vector>

void ChronoVectorLoop()
{
	std::size_t n;
	std::cout << "vector element ���� �Է� :";
	std::cin >> n;

	std::vector<int> nums(n, 1);

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	/* vector �ε��� ������� ��ȸ�ϴ� �ð� ���� */

	auto start = std::chrono::high_resolution_clock::now();

	for (int i = 0; i < 1000; i++)
	{
		for (std::size_t idx = 0; idx < nums.size(); idx++)
		{
			nums[idx] *= 2;
		}
	}

	auto end = std::chrono::high_resolution_clock::now();

	std::chrono::duration<double> diff = end - start;

	std::cout << "Index Loop : " << diff.count() << "s" << std::endl;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	/* vector ���ͷ����� ������� ��ȸ�ϴ� �ð� ���� */

	start = std::chrono::high_resolution_clock::now();

	for (int i = 0; i < 1000; i++)
	{
		for (auto itr = nums.begin(); itr < nums.end(); itr++)
		{
			(*itr) *= 2;
		}
	}

	end = std::chrono::high_resolution_clock::now();

	diff = end - start;

	std::cout << "Iterator Loop : " << diff.count() << "s" << std::endl;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	/* vector ���� ������� ��ȸ�ϴ� �ð� ���� */

	start = std::chrono::high_resolution_clock::now();

	for (int i = 0; i < 1000; i++)
	{
		for (int& num : nums)
		{
			num *= 2;
		}
	}

	end = std::chrono::high_resolution_clock::now();

	diff = end - start;

	std::cout << "Range Loop : " << diff.count() << "s" << std::endl;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}