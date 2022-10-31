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
}