/*
#include <iostream>
#include <fstream>
#include <vector>

int main()
{
	std::fstream file("AdventOfCode//2024//File_txt//01-12-2024.txt");

	std::vector<int> leftNumbers;
	std::vector<int> rightNumbers;

	while (!file.eof())
	{
		std::string line;
		file >> line;
		leftNumbers.emplace_back(std::atoi(line.c_str()));

		file >> line;
		rightNumbers.emplace_back(std::atoi(line.c_str()));
	}

	file.close();

	long long int result = 0;

	while (leftNumbers.size() > 0)
	{
		int left = *std::min_element(leftNumbers.begin(), leftNumbers.end());
		int right = *std::min_element(rightNumbers.begin(), rightNumbers.end());

		result += std::abs(right - left);

		for (int i = 0; i < leftNumbers.size(); i++)
		{
			if (left == leftNumbers[i])
			{
				leftNumbers.erase(leftNumbers.begin() + i);
				break;
			}
		}
		for (int i = 0; i < rightNumbers.size(); i++)
		{
			if (right == rightNumbers[i])
			{
				rightNumbers.erase(rightNumbers.begin() + i);
				break;
			}
		}
	}

	std::cout << result << "\n";

	return 0;
}
*/