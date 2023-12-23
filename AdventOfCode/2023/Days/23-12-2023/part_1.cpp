/*
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

enum dir { north, east, south, west, nothing };

void CheckNextStep(std::vector<dir>& directions, int i , int j, std::vector<std::string>& input)
{
	if (i - 1 >= 0)
	{
		if (input[i - 1][j] != '#' && input[i - 1][j] != 'O' && input[i - 1][j] != 'v')
			directions.emplace_back(north);
	}
	if (j + 1 < input[i].size())
	{
		if (input[i][j+1] != '#' && input[i][j + 1] != 'O' && input[i][j + 1] != '<')
			directions.emplace_back(east);
	}
	if (i + 1 < input.size())
	{
		if (input[i + 1][j] != '#' && input[i + 1][j] != 'O' && input[i + 1][j] != '^')
			directions.emplace_back(south);
	}
	if (j - 1 >= 0)
	{
		if (input[i][j - 1] != '#' && input[i][j - 1] != 'O' && input[i][j - 1] != '>')
			directions.emplace_back(west);
	}
}

void CheckSlope(dir& slope, std::vector<std::string>& input, int i, int j)
{
	switch (input[i][j])
	{
	case '>':
		slope = east;
		break;

	case '<':
		slope = west;
		break;

	case 'v':
		slope = south;
		break;

	case '^':
		slope = north;
		break;
	}
}

void Path(std::vector<std::string> input, int i, int j, std::vector<int>& counter)
{
	bool flag = true;
	while (flag)
	{
		dir slope = nothing;
		CheckSlope(slope, input, i, j);

		std::vector<dir> nextStep;
		if (slope == nothing)
		{
			CheckNextStep(nextStep, i, j, input);
		}
		else
		{
			nextStep.emplace_back(slope);
		}

		input[i][j] = 'O';

		if (nextStep.size() == 0)
		{
			flag = false;
			break;
		}

		if (nextStep.size() != 1)
		{
			for (int d = 1; d < nextStep.size(); d++)
			{
				switch (nextStep[d])
				{
				case north:
					Path(input, i - 1, j, counter);
					break;
				case east:
					Path(input, i, j + 1, counter);
					break;
				case south:
					Path(input, i + 1, j, counter);
					break;
				case west:
					Path(input, i, j - 1, counter);
					break;
				}
			}
		}
		switch (nextStep[0])
		{
		case north:
			i--;
			break;
		case east:
			j++;
			break;
		case south:
			i++;
			break;
		case west:
			j--;
			break;
		}
	}

	bool exist = false;
	for (int k = 0; k < input.back().size(); k++)
	{
		if (input.back()[k] == 'O')
			exist = true;
	}

	if (exist)
	{
		int num = 0;
		for (int k = 0; k < input.size(); k++)
		{
			for (int l = 0; l < input[k].size(); l++)
			{
				if (input[k][l] == 'O')
					num++;
			}
		}
		counter.emplace_back(num - 1);
	}
}

int main()
{
	std::fstream file("AdventOfCode//2023//File_txt//23-12-2023.txt");

	std::vector<std::string> input;

	std::string line;
	while (std::getline(file, line))
	{
		input.emplace_back(line);
	}
	file.close();

	std::vector<int> counter;
	for (int j = 0; j < input[0].size(); j++)
	{
		if (input[0][j] == '.')
		{
			Path(input, 0, j, counter);
			break;
		}
	}

	int max = 0;
	for (int i = 0; i < counter.size(); i++)
	{
		if (counter[i] > max)
			max = counter[i];
	}
	std::cout << max << '\n';

	std::cin.get();
	return 0;
}
*/