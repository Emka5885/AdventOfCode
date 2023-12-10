/*
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void CheckNextPipe(std::vector<std::vector<char>>& input, int i, int j, int& counter)
{
	bool flag = true;
	while (flag)
	{
		bool end = false;
		if (j + 1 < input[i].size())
		{
			if (input[i][j] == '-' || input[i][j] == 'L' || input[i][j] == 'F')
			{
				if (input[i][j + 1] == '-' || input[i][j + 1] == 'J' || input[i][j + 1] == 'Z')
				{
					input[i][j] = '0';
					counter++;
					j = j + 1;
					end = true;
				}
			}
		}
		if (j - 1 >= 0)
		{
			if (input[i][j] == '-' || input[i][j] == 'J' || input[i][j] == 'Z')
			{
				if (input[i][j - 1] == '-' || input[i][j - 1] == 'L' || input[i][j - 1] == 'F')
				{
					input[i][j] = '0';
					counter++;
					j = j - 1;
					end = true;
				}
			}
		}
		if (i - 1 >= 0)
		{
			if (input[i][j] == '|' || input[i][j] == 'L' || input[i][j] == 'J')
			{
				if (input[i - 1][j] == '|' || input[i - 1][j] == 'Z' || input[i - 1][j] == 'F')
				{
					input[i][j] = '0';
					counter++;
					i = i - 1;
					end = true;
				}
			}
		}
		if (i + 1 < input.size())
		{
			if (input[i][j] == '|' || input[i][j] == 'Z' || input[i][j] == 'F')
			{
				if (input[i + 1][j] == '|' || input[i + 1][j] == 'L' || input[i + 1][j] == 'J')
				{
					input[i][j] = '0';
					counter++;
					i = i + 1;
					end = true;
				}
			}
		}

		if(!end)
			flag = false;
	}
}

int main()
{
	std::fstream file("AdventOfCode//2023//File_txt//10-12-2023.txt");

	std::vector<std::vector<char>> input;

	while (!file.eof())
	{
		std::string line;
		std::getline(file, line);

		input.emplace_back(std::vector<char>());
		for (auto& c : line)
		{
			if (c == '7')
				c = 'Z';
			input.back().emplace_back(c);
		}
	}
	file.close();

	int counter = 1;
	for (int i = 0; i < input.size(); i++)
	{
		for (int j = 0; j < input[i].size(); j++)
		{
			if (input[i][j] == 'S')
			{
				counter++;
				if (input[i][j + 1] == '-' || input[i][j + 1] == 'J' || input[i][j + 1] == 'Z')
				{
					CheckNextPipe(input, i, j + 1, counter);
				}
				else if (input[i][j - 1] == '-' || input[i][j - 1] == 'L' || input[i][j - 1] == 'F')
				{
					CheckNextPipe(input, i, j - 1, counter);
				}
				else if (input[i - 1][j] == '|' || input[i - 1][j] == 'Z' || input[i - 1][j] == 'F')
				{
					CheckNextPipe(input, i - 1, j, counter);
				}
				else if (input[i + 1][j] == '|' || input[i + 1][j] == 'L' || input[i + 1][j] == 'J')
				{
					CheckNextPipe(input, i + 1, j, counter);
				}

				j = input[i].size();
				i = input.size();
				break;
			}
		}
	}

	std::cout << counter / 2 << '\n';

	system("Pause");
	return 0;
}
*/