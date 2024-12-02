/*
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main()
{
	std::fstream file("AdventOfCode//2024//File_txt//02-12-2024.txt");

	int counter = 0;

	while (!file.eof())
	{
		std::string lineFromFile;
		std::getline(file, lineFromFile);

		std::string num = "";
		std::vector<int> levels;
		for (int i = 0; i < lineFromFile.size(); i++)
		{
			if (lineFromFile[i] != ' ')
			{
				num += lineFromFile[i];
			}
			else
			{
				levels.emplace_back(std::atoi(num.c_str()));
				num = "";
			}
		}
		levels.emplace_back(std::atoi(num.c_str()));

		bool bIsOkey = true;
		if (levels[1] - levels[0] < 0)
		{
			for (int i = 1; i < levels.size(); i++)
			{
				int between = levels[i - 1] - levels[i];

				if (between < 1 || between > 3)
				{
					bIsOkey = false;
					break;
				}
			}
		}
		else
		{
			for (int i = 1; i < levels.size(); i++)
			{
				int between = levels[i] - levels[i - 1];

				if (between < 1 || between > 3)
				{
					bIsOkey = false;
					break;
				}
			}
		}

		if (bIsOkey)
		{
			counter++;
		}
	}

	file.close();

	std::cout << counter << std::endl;

	return 0;
}
*/