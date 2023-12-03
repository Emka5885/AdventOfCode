/*
#include <iostream>
#include <fstream>
#include <vector>

int main()
{
	std::fstream file("AdventOfCode//2023//File_txt//03-12-2023.txt");

	std::vector<std::vector<std::pair<char,bool>>> puzzleInput;

	while (!file.eof())
	{
		std::string line;
		file >> line;

		puzzleInput.emplace_back(std::vector<std::pair<char, bool>>());

		std::pair<char, bool> p;
		for (int i = 0; i < line.size(); i++)
		{
			p.first = line[i];
			p.second = std::isdigit(line[i]);
			puzzleInput.back().emplace_back(p);
		}
	}
	file.close();

	int result = 0;

	for (int i = 0; i < puzzleInput.size(); i++)
	{
		for (int j = 0; j < puzzleInput[i].size(); j++)
		{
			if (puzzleInput[i][j].second)
			{
				std::string acturalNumber = "";
				acturalNumber += puzzleInput[i][j].first;

				int k = 0;

				bool correctNumber = false;

				if (i - 1 >= 0)
				{
					std::pair<char, bool> toCheck = puzzleInput[i - 1][j];

					if (toCheck.first != '.')
					{
						correctNumber = true;
					}
				}

				if (!correctNumber && j - 1 >= 0)
				{
					std::pair<char, bool> toCheck = puzzleInput[i][j - 1];

					if (toCheck.first != '.')
					{
						correctNumber = true;
					}
				}

				if (!correctNumber && i - 1 >= 0 && j - 1 >= 0)
				{
					std::pair<char, bool> toCheck = puzzleInput[i - 1][j - 1];

					if (toCheck.first != '.')
					{
						correctNumber = true;
					}
				}

				if (!correctNumber && i - 1 >= 0 && j + 1 < puzzleInput[i].size())
				{
					std::pair<char, bool> toCheck = puzzleInput[i - 1][j + 1];

					if (toCheck.first != '.')
					{
						correctNumber = true;
					}
				}

				if (!correctNumber && i + 1 < puzzleInput.size())
				{
					std::pair<char, bool> toCheck = puzzleInput[i + 1][j];

					if (!toCheck.second && toCheck.first != '.')
					{
						correctNumber = true;
					}
				}

				if (!correctNumber && i + 1 < puzzleInput.size() && j + 1 < puzzleInput[i].size())
				{
					std::pair<char, bool> toCheck = puzzleInput[i + 1][j + 1];

					if (!toCheck.second && toCheck.first != '.')
					{
						correctNumber = true;
					}
				}

				if (!correctNumber && j - 1 >= 0 && i + 1 < puzzleInput.size())
				{
					std::pair<char, bool> toCheck = puzzleInput[i + 1][j - 1];

					if (!toCheck.second && toCheck.first != '.')
					{
						correctNumber = true;
					}
				}
				
				if (j + 1 < puzzleInput[i].size())
				{
					std::pair<char, bool> toCheck = puzzleInput[i][j + 1];

					puzzleInput[i][j].second = 0;

					if (toCheck.second)
					{
						k = 1;

						bool flag = true;

						do
						{
							acturalNumber += puzzleInput[i][j + k].first;

							k++;							

							if (!correctNumber && i - 1 < puzzleInput.size() && j + k < puzzleInput[i].size())
							{
								if (puzzleInput[i - 1][j + k].first != '.')
								{
									correctNumber = true;
								}
							}
							if (!correctNumber && i + 1 < puzzleInput.size() && j + k < puzzleInput[i].size())
							{
								if (puzzleInput[i + 1][j + k].first != '.')
								{
									correctNumber = true;
								}
							}
							if (!correctNumber && j + k < puzzleInput[i].size())
							{
								if (!std::isdigit(puzzleInput[i][j + k].first) && puzzleInput[i][j + k].first != '.')
								{
									correctNumber = true;
								}
							}

							puzzleInput[i][j + k - 1].second = 0;

							if (j + k >= puzzleInput[i].size())
							{
								flag = false;
							}
							else if (!puzzleInput[i][j + k].second)
							{
								flag = false;
							}
						}
						while (flag);

						k--;
					}
					else if (toCheck.first != '.')
					{
						correctNumber = true;
					}
				}

				if (correctNumber)
				{
					result += std::atoi(acturalNumber.c_str());

					j += k;
				}
			}
		}
	}

	std::cout << result << std::endl;

	return 0;
}
*/