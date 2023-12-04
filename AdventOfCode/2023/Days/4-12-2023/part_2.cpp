/*
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void ChangeStringToIntVector(std::string& str, std::vector<int>& numbers)
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
			numbers.emplace_back(std::atoi(num.c_str()));
			num = "";
			space = true;
		}
	}
	numbers.emplace_back(std::atoi(num.c_str()));
}

int PointsReceived(std::vector<std::pair<std::string, int>>& input, int i)
{
	std::string winningNumbersStr = input[i].first.substr(input[i].first.find(':') + 2, input[i].first.find('|') - input[i].first.find(':') - 3);
	std::string numbersStr = input[i].first.substr(input[i].first.find('|') + 2);
	std::vector<int> winningNumbers;
	ChangeStringToIntVector(winningNumbersStr, winningNumbers);
	std::vector<int> numbers;
	ChangeStringToIntVector(numbersStr, numbers);
	
	int count = 0;
	for (int j = 0; j < winningNumbers.size(); j++)
	{
		if (std::find(numbers.begin(), numbers.end(), winningNumbers[j]) != numbers.end())
		{
			count++;
		}
	}

	for (int j = 1; j <= count; j++)
	{
		if (i + j >= input.size())
			break;
		input[i + j].second+=input[i].second;
	}

	return input[i].second;
}

int main()
{
	std::fstream file("AdventOfCode//2023//File_txt//04-12-2023.txt");

	std::vector<std::pair<std::string, int>> input;

	while (!file.eof())
	{
		std::string line;
		std::getline(file, line);
		input.emplace_back(line, 1);
	}
	file.close();
	
	int result = 0;
	for (int i = 0; i < input.size(); i++)
	{
		result += PointsReceived(input, i);
	}
	std::cout << result << '\n';

	return 0;
}
*/