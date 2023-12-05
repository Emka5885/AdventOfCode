/*
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void ChangeStringToIntVector(std::string& str, std::vector<long long>& numbers)
{
	std::string num = "";
	bool space = true;
	for (int i = 0; i < str.size(); i++)
	{
		if (std::isdigit(str[i]))
		{
			num += str[i];
			space = false;
		}
		else if (!space)
		{
			numbers.emplace_back(std::stoll(num.c_str()));
			num = "";
			space = true;
		}
	}
	numbers.emplace_back(std::stoll(num.c_str()));
}

void SetNextNumbers(std::vector<long long>& numbers, std::vector<std::string>& conversionList)
{
	for (int i = 0; i < numbers.size(); i++)
	{
		for (int j = 0; j < conversionList.size(); j++)
		{
			std::vector<long long> conversionLine;
			ChangeStringToIntVector(conversionList[j], conversionLine);
			if (numbers[i] >= conversionLine[1] && numbers[i] < conversionLine[1] + conversionLine[2])
			{
				numbers[i] += conversionLine[0] - conversionLine[1];
				break;
			}
		}
	}
}

int main()
{
	std::fstream file("AdventOfCode//2023//File_txt//05-12-2023.txt");

	std::vector<std::string> input;
	std::string numbersStr;
	std::vector<std::string> conversionList;

	while (!file.eof())
	{
		std::string line;
		std::getline(file, line);
		if (line.size() > 0)
		{
			input.emplace_back(line);
		}
	}
	file.close();

	numbersStr = input[0].substr(input[0].find(':') + 2);
	std::vector<long long> numbers;
	ChangeStringToIntVector(numbersStr, numbers);

	input.erase(input.begin(), input.begin() + 1);

	for (int i = 0; i < 7; i++)
	{
		input.erase(input.begin(), input.begin() + 1);

		conversionList.clear();
		for (int j = 0; j < input.size(); j++)
		{
			if (std::isdigit(input[j][0]))
			{
				conversionList.emplace_back(input[j]);
			}
			else
			{
				input.erase(input.begin(), input.begin() + j);
				break;
			}
		}

		SetNextNumbers(numbers, conversionList);
	}

	int min = *std::min_element(numbers.begin(), numbers.end());
	std::cout << min << '\n';

	return 0;
}
*/