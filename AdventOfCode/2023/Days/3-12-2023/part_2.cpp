/*
#include <iostream>
#include <fstream>
#include <vector>

int main()
{
	std::fstream file("AdventOfCode//2023//File_txt//03-12-2023.txt");

	std::vector<std::vector<std::pair<char, bool>>> puzzleInput;
	std::vector<std::vector<std::pair<int, int>>> stars;

	while (!file.eof())
	{
		std::string line;
		file >> line;

		puzzleInput.emplace_back(std::vector<std::pair<char, bool>>());
		stars.emplace_back(std::vector<std::pair<int, int>>());

		std::pair<char, bool> p;
		for (int i = 0; i < line.size(); i++)
		{
			p.first = line[i];
			p.second = std::isdigit(line[i]);
			puzzleInput.back().emplace_back(p);

			stars.back().emplace_back(-1, -1);
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

				int sI, sJ;

				int k = 0;

				bool correctNumber = false;

				if (i - 1 >= 0)
				{
					std::pair<char, bool> toCheck = puzzleInput[i - 1][j];

					if (toCheck.first == '*')
					{
						correctNumber = true;
						sI = i-1;
						sJ = j;
					}
				}

				if (!correctNumber && j - 1 >= 0)
				{
					std::pair<char, bool> toCheck = puzzleInput[i][j - 1];

					if (toCheck.first == '*')
					{
						correctNumber = true;
						sI = i;
						sJ = j - 1;
					}
				}

				if (!correctNumber && i - 1 >= 0 && j - 1 >= 0)
				{
					std::pair<char, bool> toCheck = puzzleInput[i - 1][j - 1];

					if (toCheck.first == '*')
					{
						correctNumber = true;
						sI = i - 1;
						sJ = j - 1;
					}
				}

				if (!correctNumber && i - 1 >= 0 && j + 1 < puzzleInput[i].size())
				{
					std::pair<char, bool> toCheck = puzzleInput[i - 1][j + 1];

					if (toCheck.first == '*')
					{
						correctNumber = true;
						sI = i - 1;
						sJ = j + 1;
					}
				}

				if (!correctNumber && i + 1 < puzzleInput.size())
				{
					std::pair<char, bool> toCheck = puzzleInput[i + 1][j];

					if (!toCheck.second && toCheck.first == '*')
					{
						correctNumber = true;
						sI = i + 1;
						sJ = j;
					}
				}

				if (!correctNumber && i + 1 < puzzleInput.size() && j + 1 < puzzleInput[i].size())
				{
					std::pair<char, bool> toCheck = puzzleInput[i + 1][j + 1];

					if (!toCheck.second && toCheck.first == '*')
					{
						correctNumber = true;
						sI = i + 1;
						sJ = j + 1;
					}
				}

				if (!correctNumber && j - 1 >= 0 && i + 1 < puzzleInput.size())
				{
					std::pair<char, bool> toCheck = puzzleInput[i + 1][j - 1];

					if (!toCheck.second && toCheck.first == '*')
					{
						correctNumber = true;
						sI = i + 1;
						sJ = j - 1;
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
								if (puzzleInput[i - 1][j + k].first == '*')
								{
									correctNumber = true;
									sI = i - 1;
									sJ = j + k;
								}
							}
							if (!correctNumber && i + 1 < puzzleInput.size() && j + k < puzzleInput[i].size())
							{
								if (puzzleInput[i + 1][j + k].first == '*')
								{
									correctNumber = true;
									sI = i + 1;
									sJ = j + k;
								}
							}
							if (!correctNumber && j + k < puzzleInput[i].size())
							{
								if (!std::isdigit(puzzleInput[i][j + k].first) && puzzleInput[i][j + k].first == '*')
								{
									correctNumber = true;
									sI = i;
									sJ = j + k;
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
						} while (flag);

						k--;
					}
					else if (toCheck.first == '*')
					{
						correctNumber = true;
						sI = i;
						sJ = j + 1;
					}
				}

				if (correctNumber)
				{
					if (stars[sI][sJ].first == -1)
					{
						stars[sI][sJ].first = std::atoi(acturalNumber.c_str());
					}
					else
					{
						stars[sI][sJ].second = std::atoi(acturalNumber.c_str());
					}

					j += k;
				}
			}
		}
	}

	for (int i = 0; i < stars.size(); i++)
	{
		for (int j = 0; j < stars.size(); j++)
		{
			if (stars[i][j].second != -1)
			{
				result += (stars[i][j].first * stars[i][j].second);
			}
		}
	}
	std::cout << result << '\n';

	return 0;
}
*/