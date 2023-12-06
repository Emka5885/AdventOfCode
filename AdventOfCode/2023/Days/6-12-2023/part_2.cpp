/*
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

long long ChangeStringToInt(std::string& str)
{
	std::string num = "";
	for (int i = 0; i < str.size(); i++)
	{
		if (std::isdigit(str[i]))
		{
			num += str[i];
		}
	}
	return std::stoll(num.c_str());
}

int main()
{
	std::fstream file("AdventOfCode//2023//File_txt//06-12-2023.txt");

	long long distance, time;
	distance = time = long long(0);

	while (!file.eof())
	{
		std::string line;
		std::getline(file, line);

		if (time > 0)
		{
			distance = ChangeStringToInt(line);
		}
		else
		{
			time = ChangeStringToInt(line);
		}
	}
	file.close();

	int numberOfWaysToWin = 0;
	for (int j = 0; j < time; j++)
	{
		if (j * (time - j) > distance)
			numberOfWaysToWin++;
	}
	std::cout << numberOfWaysToWin << '\n';

	return 0;
}
*/