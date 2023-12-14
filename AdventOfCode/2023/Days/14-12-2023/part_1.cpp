/*
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

void TiltPlatform(std::vector<std::vector<char>>& platform)
{
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
}

int main()
{
	std::fstream file("AdventOfCode//2023//File_txt//14-12-2023.txt");

	std::vector<std::vector<char>> platform;

	while (!file.eof())
	{
		std::string line;
		std::getline(file, line);
		platform.emplace_back(std::vector<char>());
		for (char& c : line)
		{
			platform.back().emplace_back(c);
		}
	}
	file.close();

	TiltPlatform(platform);

	int result = 0;
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

	system("PAUSE");
	return 0;
}
*/