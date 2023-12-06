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
			numbers.emplace_back(std::stoll(num.c_str()));
			num = "";
			space = true;
		}
	}
	numbers.emplace_back(std::stoll(num.c_str()));
}

int main()
{
	std::fstream file("AdventOfCode//2023//File_txt//06-12-2023.txt");

	std::vector<int> time, distance;

	while (!file.eof())
	{
		std::string line;
		std::getline(file, line);

		if (time.size() > 0)
		{
			ChangeStringToIntVector(line, distance);
		}
		else
		{
			ChangeStringToIntVector(line, time);
		}
	}
	file.close();

	int result = 1;
	for (int i = 0; i < time.size(); i++)
	{
		int numberOfWaysToWin = 0;
		for (int j = 0; j < time[i]; j++)
		{
			if (j * (time[i] - j) > distance[i])
				numberOfWaysToWin++;
		}
		result *= numberOfWaysToWin;
	}
	std::cout << result << '\n';

	return 0;
}
*/