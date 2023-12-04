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
		else if(!space)
		{
			numbers.emplace_back(std::atoi(num.c_str()));
			num = "";
			space = true;
		}
	}
	numbers.emplace_back(std::atoi(num.c_str()));
}

int PointsReceived(std::string& scratchcard)
{
	std::string winningNumbersStr = scratchcard.substr(scratchcard.find(':') + 2, scratchcard.find('|') - scratchcard.find(':') - 3);
	std::string numbersStr = scratchcard.substr(scratchcard.find('|') + 2);

	std::vector<int> winningNumbers;
	ChangeStringToIntVector(winningNumbersStr, winningNumbers);
	std::vector<int> numbers;
	ChangeStringToIntVector(numbersStr, numbers);

	int points = 0;

	for (int i = 0; i < winningNumbers.size(); i++)
	{
		if (std::find(numbers.begin(), numbers.end(), winningNumbers[i]) != numbers.end())
		{
			if (points == 0)
				points = 1;
			else
				points *= 2;
		}
	}

	return points;
}

int main()
{
	std::fstream file("AdventOfCode//2023//File_txt//04-12-2023.txt");

	std::vector<std::string> input;

	while (!file.eof())
	{
		std::string line;
		std::getline(file, line);
		input.emplace_back(line);
	}
	file.close();

	int result = 0;
	for (int i = 0; i < input.size(); i++)
	{
		result += PointsReceived(input[i]);
	}
	std::cout << result << '\n';

	return 0;
}
*/