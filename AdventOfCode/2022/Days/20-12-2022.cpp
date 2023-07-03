/*
//#1
#include <iostream>
#include <fstream>
#include <vector>
#include <string>


int main()
{
	std::ifstream o("AdventOfCode//2022//File_txt//20-12-2022.txt");

	std::string input;

	std::vector<std::pair<int,int>> allNumbers;

	int counter = 0;

	while (!o.eof())
	{
		while (getline(o, input))
		{
			allNumbers.push_back({ std::stoi(input), counter });
			counter++;
		}
	}

	for (int i = 0; i < allNumbers.size(); i++)
	{
		if (allNumbers[i].first == 0)
		{
			continue;
		}
		if (allNumbers[i].first > 0)
		{
			for (int j = 1; j <= allNumbers[i].first; j++)
			{
				int helper = allNumbers[i].second;
				if (helper + 1 != allNumbers.size())
				{
					for (int k = 0; k < allNumbers.size(); k++)
					{
						if (helper + 1 == allNumbers[k].second)
						{
							std::swap(allNumbers[i].second, allNumbers[k].second);
						}
					}
				}
				else
				{
					for (int k = 0; k < allNumbers.size(); k++)
					{
						allNumbers[k].second++;
					}
					allNumbers[i].second = 0;
					for (int k = 0; k < allNumbers.size(); k++)
					{
						if (1 == allNumbers[k].second)
						{
							std::swap(allNumbers[i].second, allNumbers[k].second);
						}
					}
				}
			}
		}
		else
		{
			for (int j = allNumbers[i].first; j < 0; j++)
			{
				int helper = allNumbers[i].second;
				if (helper - 1 != -1)
				{
					for (int k = 0; k < allNumbers.size(); k++)
					{
						if (helper - 1 == allNumbers[k].second)
						{
							std::swap(allNumbers[i].second, allNumbers[k].second);
						}
					}
				}
				else
				{
					for (int k = 0; k < allNumbers.size(); k++)
					{
						allNumbers[k].second--;
					}
					allNumbers[i].second = allNumbers.size() - 1;

					for (int k = 0; k < allNumbers.size(); k++)
					{
						if (allNumbers.size()-2 == allNumbers[k].second)
						{
							std::swap(allNumbers[i].second, allNumbers[k].second);
						}
					}
				}
			}
			if (allNumbers[i].second == 0)
			{
				for (int k = 0; k < allNumbers.size(); k++)
				{
					allNumbers[k].second--;
				}
				allNumbers[i].second = allNumbers.size() - 1;
			}
		}
	}

	for (int i = 0; i < allNumbers.size(); i++)
	{
		std::cout << allNumbers[i].first << "|" << allNumbers[i].second << "\n";
	}

	int zeroIndex = 0, oneIndex, twoIndex, threeIndex;
	for (int i = 0; i < allNumbers.size(); i++)
	{
		if (0 == allNumbers[i].first)
		{
			zeroIndex = allNumbers[i].second;
		}
	}

	oneIndex = (zeroIndex + 1000) % allNumbers.size();
	twoIndex = (zeroIndex + 2000) % allNumbers.size();
	threeIndex = (zeroIndex + 3000) % allNumbers.size();

	int result = 0;


	for (int i = 0; i < allNumbers.size(); i++)
	{
		if (oneIndex == allNumbers[i].second)
		{
			result += allNumbers[i].first;
		}
		if (twoIndex == allNumbers[i].second)
		{
			result += allNumbers[i].first;
		}
		if (threeIndex == allNumbers[i].second)
		{
			result += allNumbers[i].first;
		}
	}

	std::cout << '\n' << result << '\n';

	system("PAUSE");
	return 0;
}
*/



//#2