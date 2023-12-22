/*
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

void NextStep(std::vector<std::string>& steps)
{
	std::vector<std::string> newSteps = steps;
	for (int i = 0; i < steps.size(); i++)
	{
		for (int j = 0; j < steps[i].size(); j++)
		{
			if (steps[i][j] == '0')
			{
				// north
				if (i - 1 >= 0)
					if (steps[i - 1][j] != '#')
						newSteps[i - 1][j] = '0';
				// south
				if (i + 1 < steps.size())
					if (steps[i + 1][j] != '#')
						newSteps[i + 1][j] = '0';
				// east
				if (j - 1 >= 0)
					if (steps[i][j - 1] != '#')
						newSteps[i][j - 1] = '0';
				// west
				if (j + 1 < steps[i].size())
					if (steps[i][j + 1] != '#')
						newSteps[i][j + 1] = '0';

				newSteps[i][j] = '.';
			}
		}
	}
	steps = newSteps;
}

int main()
{
	std::fstream file("AdventOfCode//2023//File_txt//21-12-2023.txt");

	std::vector<std::string> input;

	std::string line;
	while (std::getline(file, line))
	{
		input.emplace_back(line);
	}
	file.close();

	for (int i = 0; i < input.size(); i++)
	{
		for (int j = 0; j < input[i].size(); j++)
		{
			if (input[i][j] == 'S')
				input[i][j] = '0';
		}
	}

	int steps = 64;
	for (int i = 0; i < steps; i++)
	{
		NextStep(input);
	}

	long long result = 0;
	for (int i = 0; i < input.size(); i++)
	{
		for (int j = 0; j < input[i].size(); j++)
		{
			if (input[i][j] == '0')
				result++;
		}
	}
	std::cout << result << '\n';

	std::cin.get();
	return 0;
}
*/