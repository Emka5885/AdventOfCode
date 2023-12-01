/*
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>

bool CheckIfDigitIsInLetters(std::map<std::string, int>& digits, const std::string& line, int i, int& returnValue)
{
	std::string letters = "";

	if (i + 2 >= line.size())
	{
		return false;
	}

	for (int j = 0; j < 2; j++)
	{
		if (i + j < line.size())
		{
			letters += line[i + j];
		}
	}

	for (int j = 2; j < 5; j++)
	{
		if (i + j < line.size())
		{
			letters += line[i + j];
		}

		std::map<std::string, int>::iterator it = digits.begin();
		while (it != digits.end())
		{
			if (letters == it->first)
			{
				returnValue = it->second;
				return true;
			}
			++it;
		}
	}

	return false;
}

int main()
{
	std::fstream file("AdventOfCode//2023//File_txt//01-12-2023.txt");

	std::vector<int> calibrationValues;

	std::map<std::string, int> digits;

	digits["zero"] = 0;
	digits["one"] = 1;
	digits["two"] = 2;
	digits["three"] = 3;
	digits["four"] = 4;
	digits["five"] = 5;
	digits["six"] = 6;
	digits["seven"] = 7;
	digits["eight"] = 8;
	digits["nine"] = 9;

	while (!file.eof())
	{
		std::string line;
		file >> line;

		std::string numbers;

		int value = -1;

		for (int i = 0; i < line.size(); i++)
		{
			if (line[i] >= '0' && line[i] <= '9')
			{
				numbers = line[i];
				break;
			}

			if (CheckIfDigitIsInLetters(digits, line, i, value))
			{
				numbers = std::to_string(value);
				break;
			}
		}

		value = -1;

		for (int i = line.size() - 1; i >= 0; i--)
		{
			if (line[i] >= '0' && line[i] <= '9')
			{
				numbers += line[i];
				break;
			}

			if (CheckIfDigitIsInLetters(digits, line, i, value))
			{
				numbers += std::to_string(value);
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