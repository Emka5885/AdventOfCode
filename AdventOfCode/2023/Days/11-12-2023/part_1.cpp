/*
#include <iostream>
#include <fstream>
#include <vector>

void CheckNoGalaxiesInRows(std::vector<int>& noGalaxiesX, std::vector<std::string>& space)
{
	for (int i = 0; i < space[0].size(); i++)
	{
		bool flag = true;
		for (int j = 0; j < space.size(); j++)
		{
			if (space[j][i] == '#')
			{
				flag = false;
				break;
			}
		}
		if (flag)
			noGalaxiesX.emplace_back(i);
	}
}

void CheckNoGalaxiesInColumns(std::vector<int>& noGalaxiesY, std::vector<std::string>& space)
{
	for (int i = 0; i < space.size(); i++)
	{
		bool flag = true;
		for (int j = 0; j < space[i].size(); j++)
		{
			if (space[i][j] == '#')
			{
				flag = false;
				break;
			}
		}
		if (flag)
			noGalaxiesY.emplace_back(i);
	}
}

int main()
{
	std::fstream file("AdventOfCode//2023//File_txt//11-12-2023.txt");

	std::vector<std::string> input;

	while (!file.eof())
	{
		std::string line;
		file >> line;
		input.emplace_back(line);
	}
	file.close();

	std::vector<std::pair<int, int>> galaxiesPos;
	for (int i = 0; i < input.size(); i++)
	{
		for (int j = 0; j < input[i].size(); j++)
		{
			if (input[i][j] == '#')
			{
				galaxiesPos.emplace_back(i, j);
			}
		}
	}

	std::vector<int> noGalaxiesX;
	std::vector<int> noGalaxiesY;
	CheckNoGalaxiesInRows(noGalaxiesX, input);
	CheckNoGalaxiesInColumns(noGalaxiesY, input);

	int result = 0;
	for (int i = 0; i < galaxiesPos.size(); i++)
	{
		for (int j = i+1; j < galaxiesPos.size(); j++)
		{
			int num = std::abs(galaxiesPos[j].first - galaxiesPos[i].first) + std::abs(galaxiesPos[j].second - galaxiesPos[i].second);
			
			for (int k = 0; k < noGalaxiesX.size(); k++)
			{
				if ((noGalaxiesX[k] > galaxiesPos[j].second && noGalaxiesX[k] < galaxiesPos[i].second) || (noGalaxiesX[k] < galaxiesPos[j].second && noGalaxiesX[k] > galaxiesPos[i].second))
					num++;
			}
			for (int k = 0; k < noGalaxiesY.size(); k++)
			{
				if ((noGalaxiesY[k] > galaxiesPos[j].first && noGalaxiesY[k] < galaxiesPos[i].first) || (noGalaxiesY[k] < galaxiesPos[j].first && noGalaxiesY[k] > galaxiesPos[i].first))
					num++;
			}
			result += num;
		}
	}
	std::cout << result << '\n';

	system("PAUSE");
	return 0;
}
*/