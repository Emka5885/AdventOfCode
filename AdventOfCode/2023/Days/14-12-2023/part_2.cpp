/*
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

void TiltPlatform(std::vector<std::vector<char>>& platform)
{
	//north
	for (int i = 0; i < platform[0].size(); i++)
	{
		bool flag = true;
		while (flag)
		{
			flag = false;
			for (int j = 1; j < platform.size(); j++)
			{
				if (platform[j][i] == 'O' && platform[j - 1][i] == '.')
				{
					platform[j - 1][i] = 'O';
					platform[j][i] = '.';
					flag = true;
				}
			}
		}
	}

	//west
	for (int i = 0; i < platform.size(); i++)
	{
		bool flag = true;
		while (flag)
		{
			flag = false;
			for (int j = 1; j < platform[i].size(); j++)
			{
				if (platform[i][j] == 'O' && platform[i][j - 1] == '.')
				{
					platform[i][j - 1] = 'O';
					platform[i][j] = '.';
					flag = true;
				}
			}
		}
	}

	//south
	for (int i = 0; i < platform[0].size(); i++)
	{
		bool flag = true;
		while (flag)
		{
			flag = false;
			for (int j = platform.size() - 1; j > 0; j--)
			{
				if (platform[j - 1][i] == 'O' && platform[j][i] == '.')
				{
					platform[j][i] = 'O';
					platform[j - 1][i] = '.';
					flag = true;
				}
			}
		}
	}


	//east
	for (int i = 0; i < platform.size(); i++)
	{
		bool flag = true;
		while (flag)
		{
			flag = false;
			for (int j = platform[i].size() - 1; j > 0; j--)
			{
				if (platform[i][j - 1] == 'O' && platform[i][j] == '.')
				{
					platform[i][j] = 'O';
					platform[i][j - 1] = '.';
					flag = true;
				}
			}
		}
	}
}

int main()
{
	std::fstream file("AdventOfCode//2023//File_txt//14-12-2023.txt");

	std::vector<std::vector<char>> platform;
	
	std::string line;
	while (std::getline(file, line))
	{
		platform.emplace_back(line.begin(), line.end());
	}
	file.close();

	int counter = 0;
	int help = 0;
	std::vector<std::vector<std::vector<char>>> helper;
	bool flag = true;
	do
	{
		TiltPlatform(platform);
		for (int i = 0; i < helper.size(); i++)
		{
			if (std::equal(helper[i].begin(), helper[i].end(), platform.begin()))
			{
				help = i;
				flag = false;
				break;
			}
		}
		helper.emplace_back(platform);
		counter++;
	}
	while(flag);

	int rest = (1000000000 - help - 1) % (counter - 1 - help) ;
	for (int i = 0; i < rest; i++)
	{
		TiltPlatform(platform);
	}

	long long result = 0;
	for (int i = 0; i < platform.size(); i++)
	{
		for (int j = 0; j < platform[i].size(); j++)
		{
			if (platform[i][j] == 'O')
			{
				result += platform.size() - i;
			}
		}
	}
	std::cout << result << '\n';

	std::cin.get();
	return 0;
}
*/