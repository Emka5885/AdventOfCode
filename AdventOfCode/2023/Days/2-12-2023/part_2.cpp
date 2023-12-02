/*
#include <iostream>
#include <fstream>
#include <string>

bool IsDigit(char c)
{
	return c >= '0' && c <= '9';
}

void CheckNumberOfCubes(std::string& set, const std::string& searched, int& max)
{
	int id = set.find(searched);
	if (id != -1)
	{
		std::string number = "";

		int i = 0;
		while (true)
		{
			if (id - 2 - i < 0)
				break;

			if (!IsDigit(set[id - 2 - i]))
				break;

			number += set[id - 2 - i];
			++i;
		}
		std::reverse(number.begin(), number.end());

		int numOfCubes = std::stoi(number);

		if (max < numOfCubes)
			max = numOfCubes;
	}
}

int PowerOfGame(std::string& game)
{
	int maxRed, maxBlue, maxGreen;
	maxRed = maxBlue = maxGreen = 0;

	while (true)
	{
		std::string set = game.substr(0, game.find(";"));

		CheckNumberOfCubes(set, "red", maxRed);
		CheckNumberOfCubes(set, "blue", maxBlue);
		CheckNumberOfCubes(set, "green", maxGreen);

		if (game.find(";") == -1)
			break;

		game.erase(0, game.find(";") + 1);
	}

	return maxRed * maxGreen * maxBlue;
}

int main()
{
	std::fstream file("AdventOfCode//2023//File_txt//02-12-2023.txt");

	int result = 0;

	while (!file.eof())
	{
		std::string line;
		std::getline(file, line);
		
		result += PowerOfGame(line);
	}
	file.close();

	std::cout << result << "\n";

	return 0;
}
*/