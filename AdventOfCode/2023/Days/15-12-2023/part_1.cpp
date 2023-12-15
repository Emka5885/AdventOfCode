/*
#include <iostream>
#include <fstream>
#include <string>

int CalculateValue(std::string& step)
{
	int value = 0;
	for (char& c : step)
	{
		value = (value + c) * 17 % 256;
	}

	return value;
}

int main()
{
	std::fstream file("AdventOfCode//2023//File_txt//15-12-2023.txt");

	std::string input = "";
	std::string line;
	while (std::getline(file, line))
	{
		input += line;
	}
	file.close();

	long long result = 0;

	int index;
	std::string step;
	while ((index = input.find(',')) != std::string::npos)
	{
		step = input.substr(0, index);
		input.erase(0, index + 1);
		result += CalculateValue(step);
	}
	step = input.substr(0, index);
	result += CalculateValue(step);

	std::cout << result << '\n';

	std::cin.get();
	return 0;
}
*/