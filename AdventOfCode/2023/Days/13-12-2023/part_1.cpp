/*
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void RotateVector(std::vector<std::vector<std::string>>& v)
{
	std::vector<std::vector<std::string>> helper;

	for (int i = 0; i < v.size(); i++)
	{
		helper.emplace_back(std::vector<std::string>());
		for (int j = 0; j < v[i][0].size(); j++)
		{
			std::string newLine = "";
			for (int k = 0; k < v[i].size(); k++)
			{
				newLine += v[i][k][j];
			}
			std::reverse(newLine.begin(), newLine.end());
			helper.back().emplace_back(newLine);
		}
	}
	v = helper;
}

int LineOfReflection(std::vector<std::vector<std::string>>& patterns, int i)
{
	int line = -1;
	for (int j = 1; j < patterns[i].size(); j++)
	{
		int k = j - 1;
		int l = j;

		bool mirrors = true;
		while (k >= 0 && l < patterns[i].size())
		{
			if (patterns[i][k] != patterns[i][l])
			{
				mirrors = false;
				break;
			}
			k--; l++;
		}
		if (mirrors)
			line += j + 1;
	}
	return line;
}

int main()
{
	std::fstream file("AdventOfCode//2023//File_txt//13-12-2023.txt");

	std::vector<std::vector<std::string>> input;

	bool newPatterns = true;
	while (!file.eof())
	{
		std::string line;
		std::getline(file, line);

		if (newPatterns)
		{
			input.emplace_back(std::vector<std::string>());
			newPatterns = false;
		}

		if (line == "")
			newPatterns = true;
		else
			input.back().emplace_back(line);
		
	}

	int result = 0;

	//rows
	for (int i = 0; i < input.size(); i++)
	{
		int line = LineOfReflection(input, i);
		if (line != -1)
			result += line * 100;
	}

	RotateVector(input);
	//columns
	for (int i = 0; i < input.size(); i++)
	{
		int line = LineOfReflection(input, i);
		if (line != -1)
			result += line;
	}

	std::cout << result << '\n';

	system("PAUSE");
	return 0;
}
*/