/*
#include <iostream>
#include <fstream>
#include <vector>

int main()
{
	std::fstream file("AdventOfCode//2023//File_txt//01-12-2023.txt");

	std::vector<int> calibrationValues;

	while (!file.eof())
	{
		std::string line;
		file >> line;

		std::string numbers;

		for (int i = 0; i < line.size(); i++)
		{
			if (line[i] >= '0' && line[i] <= '9')
			{
				numbers = line[i];
				break;
			}
		}

		for (int i = line.size() - 1; i >= 0; i--)
		{
			if (line[i] >= '0' && line[i] <= '9')
			{
				numbers += line[i];
				break;
			}
		}

		calibrationValues.emplace_back(std::atoi(numbers.c_str()));
	}

	file.close();

	int result = 0;

	for (int i = 0; i < calibrationValues.size(); i++)
	{
		result += calibrationValues[i];
	}

	std::cout << result << "\n";

	return 0;
}
*/