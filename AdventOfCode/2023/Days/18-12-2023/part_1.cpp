/*
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main()
{
	std::fstream file("AdventOfCode//2023//File_txt//18-12-2023.txt");

	std::vector<std::string> input;

	std::string line;
	while (std::getline(file, line))
	{
		input.emplace_back(line);
		input.back().erase(input.back().find('(') - 1);
	}
	file.close();

	std::vector<std::vector<char>> digPlan(1);
	digPlan[0].emplace_back('#');

	int x = 0;
	int y = 0;

	for (int i = 0; i < input.size(); i++)
	{
		int steps = std::atoi(input[i].substr(2).c_str());
		for (int j = 0; j < steps; j++)
		{
			switch (input[i][0])
			{
			case 'R':
				x++;
				if (digPlan[y].size() <= x)
				{
					for (int k = 0; k < digPlan.size(); k++)
						digPlan[k].emplace_back('.');
				}
				break;

			case 'L':
				if (x - 1 < 0)
				{
					for (int k = 0; k < digPlan.size(); k++)
						digPlan[k].insert(digPlan[k].begin(), '.');
				}
				else
					x--;
				break;

			case 'D':
				y++;
				if (digPlan.size() <= y)
				{
					digPlan.emplace_back(std::vector<char>(digPlan[y-1].size(), '.'));
				}
				break;

			case 'U':
				if (y - 1 < 0)
				{
					digPlan.insert(digPlan.begin(), std::vector<char>(digPlan[y].size(), '.'));
				}
				else
					y--;
				break;
			}
			digPlan[y][x] = '#';
		}
	}

	bool inside;
	int counter = 0;
	for (int i = 0; i < digPlan.size(); i++)
	{
		inside = false;
		for (int j = 0; j < digPlan[i].size(); j++)
		{
			if (digPlan[i][j] == '#')
			{
				if (i + 1 < digPlan.size())
				{
					if(digPlan[i+1][j] == '#')
						inside = !inside;
				}
				counter++;
			}
			else if (digPlan[i][j] == '.')
			{
				if (inside)
				{
					counter++;
				}
			}
		}
	}
	std::cout << counter << '\n';

	std::cin.get();
	return 0;
}
*/