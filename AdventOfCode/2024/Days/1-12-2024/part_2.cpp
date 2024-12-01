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

	for(int i = 0; i < leftNumbers.size(); i++)
	{
		int counter = 0;
		for (int j = 0; j < rightNumbers.size(); j++)
		{
			if (leftNumbers[i] == rightNumbers[j])
			{
				counter++;
			}
		}

		result += leftNumbers[i] * counter;
	}

	std::cout << result << "\n";

	return 0;
}
*/