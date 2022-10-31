#pragma once

#include <chrono>
#include <iostream>
#include <vector>

void ChronoVectorLoop()
{
	std::size_t n;
	std::cout << "vector element 개수 입력 :";
	std::cin >> n;

	std::vector<int> nums(n, 1);

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	/* vector 인덱스 기반으로 순회하는 시간 측정 */

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

	/* vector 이터레이터 기반으로 순회하는 시간 측정 */

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

	/* vector 범위 기반으로 순회하는 시간 측정 */

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