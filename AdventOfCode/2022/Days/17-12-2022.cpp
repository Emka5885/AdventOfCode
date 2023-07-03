/*
//#1
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

std::vector<std::vector<char>> rock1;
std::vector<std::vector<char>> rock2;
std::vector<std::vector<char>> rock3;
std::vector<std::vector<char>> rock4;
std::vector<std::vector<char>> rock5;

std::vector<std::vector<std::vector<char>>> allRockTypes;

int main()
{
	std::ifstream o("AdventOfCode//2022//File_txt//17-12-2022.txt");

	std::string input, jetPattern;

	rock1.push_back(std::vector<char>());
	for (int i = 0; i < 4; i++)
	{
		rock1[0].push_back('#');
	}

	for (int i = 0; i < 3; i++)
	{
		rock2.push_back(std::vector<char>());
		if (i == 1)
		{
			rock2[i].push_back('#');
			rock2[i].push_back('#');
			rock2[i].push_back('#');
		}
		else
		{
			rock2[i].push_back('.');
			rock2[i].push_back('#');
			rock2[i].push_back('.');
		}
	}

	for (int i = 0; i < 3; i++)
	{
		rock3.push_back(std::vector<char>());
		if (i == 2)
		{
			rock3[i].push_back('#');
			rock3[i].push_back('#');
			rock3[i].push_back('#');
		}
		else
		{
			rock3[i].push_back('.');
			rock3[i].push_back('.');
			rock3[i].push_back('#');
		}
	}

	for (int i = 0; i < 4; i++)
	{
		rock4.push_back(std::vector<char>());
		rock4[i].push_back('#');
	}

	for (int i = 0; i < 2; i++)
	{
		rock5.push_back(std::vector<char>());
		rock5[i].push_back('#');
		rock5[i].push_back('#');
	}

	allRockTypes.push_back(rock1);
	allRockTypes.push_back(rock2);
	allRockTypes.push_back(rock3);
	allRockTypes.push_back(rock4);
	allRockTypes.push_back(rock5);

	while (!o.eof())
	{
		while (getline(o, input))
		{
			if (!input.empty())
			{
				jetPattern += input;
			}
		}
	}

	std::vector<std::vector<char>> cave;

	bool newRock = true;
	int counter = 0;
	int shiftCounter = 0;
	bool falls = false;
	int offsetY = 0;
	int height = 0;
	bool checkSize = true;
	int helperSize = 0;
	bool stopFalls = false;
	bool betweenRocks = false;
	int rockCounter = 0;
	for (int i = 0; i < 3; i++)
	{
		cave.push_back(std::vector<char>());
		for (int j = 0; j < 7; j++)
		{
			cave[cave.size() - 1].push_back('.');
		}
	}
	while (rockCounter!=2023)
	{
		if (newRock)
		{
			rockCounter++;
			while (cave.size() > height + 3)
			{
				cave.erase(cave.begin() + cave.size()-1);
			}
			for (int i = cave.size() - 1; i >= height; i--)
			{
				cave[i].clear();
			}
			for (int i = allRockTypes[counter].size() - 1; i >= 0; i--)
			{
				if (cave.size() < height + 3 + allRockTypes[counter].size())
				{
					cave.push_back(std::vector<char>());
				}
			}
			int counter2 = 0;
			for (int i = cave.size() - 1; i >= height; i--)
			{
				if (counter2 < allRockTypes[counter].size())
				{
					for (int j = 0; j < 7; j++)
					{
						if (j < 2)
						{
							cave[i].push_back('.');
						}
						else if (j < allRockTypes[counter][0].size() + 2)
						{
							if (allRockTypes[counter][cave.size()-1-i][j - 2] == '#')
							{
								cave[i].push_back('@');
							}
							else
							{
								cave[i].push_back('.');
							}
						}
						else
						{
							cave[i].push_back('.');
						}
					}
					counter2++;
				}
				else
				{
					for (int j = 0; j < 7; j++)
					{
						cave[i].push_back('.');
					}
				}
				
			}
			newRock = false;
			falls = false;
		}
		else
		{
			if (!falls)
			{
				if (jetPattern[shiftCounter] == '>')
				{
					bool isMoving = true;
					for (int k = cave.size() - 1; k >= 0; k--)
					{
						if (cave[k][cave[0].size() - 1] == '@')
						{
							isMoving = false;
							continue;
						}
						for (int j = 0; j < cave[0].size() - 1; j++)
						{
							if (cave[k][j] == '@')
							{
								if (cave[k][j + 1] == '#' && cave[k][j] == '@')
								{
									isMoving = false;
									continue;
								}

							}
						}
					}
					if (isMoving)
					{
						int helper_x = -1;
						int helper_y = -1;
						for (int k = 1; k < cave.size(); k++)
						{
							for (int j = 0; j < cave[0].size(); j++)
							{
								if (cave[k][j] == '@')
								{
									if (helper_x > j || helper_x == -1)
									{
										helper_x = j;
										j = cave[0].size();
									}
									if (helper_y > k || helper_y == -1)
									{
										helper_y = k;
									}
								}
							}
						}
						std::vector< std::vector<char>> helperCurrent;
						for (int k = helper_y; k < helper_y + allRockTypes[counter].size(); k++)
						{
							helperCurrent.push_back(std::vector<char>());
							for (int j = helper_x; j < helper_x + allRockTypes[counter][0].size(); j++)
							{
								helperCurrent[k - helper_y].push_back(cave[k][j]);
								if(cave[k][j]!='#')
									cave[k][j] = '.';
							}
						}
						for (int k = helper_y; k < helper_y + allRockTypes[counter].size(); k++)
						{
							for (int j = helper_x; j < helper_x + allRockTypes[counter][0].size(); j++)
							{
								if (cave[k][j] == '#')
								{
									if (cave[k][j + 1] == '@')
									{
										cave[k][j + 1] = '.';
									}
								}
								else if (cave[k][j + 1] != '#')
								{
									cave[k][j + 1] = helperCurrent[k - helper_y][j - helper_x];
								}
							}
						}
					}
				}
				else
				{
					bool isMoving = true;
					for (int k = cave.size()-1; k >= 0; k--)
					{
						if (cave[k][0] == '@')
						{
							isMoving = false;
							continue;
						}
						for (int j = 1; j < cave[0].size(); j++)
						{
							if (cave[k][j - 1] == '#' && cave[k][j] == '@')
							{
								isMoving = false;
								continue;
							}		
						}
					}
					if (isMoving)
					{
						int helper_x = -1;
						int helper_y = -1;
						for (int k = 1; k < cave.size(); k++)
						{
							for (int j = 0; j < cave[0].size(); j++)
							{
								if (cave[k][j] == '@')
								{
									if (helper_x > j || helper_x == -1)
									{
										helper_x = j;
										j = cave[0].size();
									}
									if (helper_y > k || helper_y == -1)
									{
										helper_y = k;
									}
								}
							}
						}
						std::vector< std::vector<char>> helperCurrent;
						for (int k = helper_y; k < helper_y + allRockTypes[counter].size(); k++)
						{
							helperCurrent.push_back(std::vector<char>());
							for (int j = helper_x; j < helper_x + allRockTypes[counter][0].size(); j++)
							{
								helperCurrent[k - helper_y].push_back(cave[k][j]);
								cave[k][j] = '.';
							}
						}
						for (int k = helper_y; k < helper_y + allRockTypes[counter].size(); k++)
						{
							for (int j = helper_x + allRockTypes[counter][0].size()-1; j >= helper_x; j--)
							{
								if (cave[k][j] == '#')
								{
									if (cave[k][j - 1] == '@')
									{
										cave[k][j - 1] = '.';
									}
								}
								else if (cave[k][j - 1] != '#')
								{
									cave[k][j - 1] = helperCurrent[k - helper_y][j - helper_x];
								}
							}
						}
					}
				}
				shiftCounter++;
				if (shiftCounter == jetPattern.size())
				{
					shiftCounter = 0;
				}
				falls = true;
			}
			else
			{
				if (allRockTypes[counter].size() > 1 && checkSize)
				{
					helperSize = 0;
					for (int i = 1; i < allRockTypes[counter].size(); i++)
					{
						helperSize++;
					}
					checkSize = false;
				}
				bool isAir = true;
				int helper_x = -1;
				int helper_y = -1;
				for (int k = 1; k < cave.size(); k++)
				{
					for (int j = 0; j < cave[0].size(); j++)
					{
						if (cave[k][j] == '@')
						{
							if (helper_x > j || helper_x == -1)
							{
								helper_x = j;
								j = cave[0].size();
							}
							if (helper_y > k || helper_y == -1)
							{
								helper_y = k;
							}
						}
					}
				}
				if (helper_y >= cave.size() - height - helperSize|| stopFalls)
				{
					for (int i = 0; i < cave[0].size(); i++)
					{
						if (height == 0)
						{
							isAir = false;
						}
						else if (isAir)
						{
							int helper_x = -1;
							int helper_y = -1;
							for (int k = 1; k < cave.size(); k++)
							{
								for (int j = 0; j < cave[0].size(); j++)
								{
									if (cave[k][j] == '@' && cave[k - 1][j] == '#')
									{
										if (helper_x > j || helper_x == -1)
										{
											helper_x = j;
											j = cave[0].size();
										}
										if (helper_y > k || helper_y == -1)
										{
											helper_y = k;
										}
									}
								}
							}
							if (helper_x != -1 && helper_y != -1)
							{
								for (int i = helper_x; i < helper_x + allRockTypes[counter][0].size(); i++)
								{
									isAir = false;
								}
							}
						}
					}
					if (isAir)
					{
						betweenRocks = true;
					}
					else
					{
						int helper_x = -1;
						int helper_y = -1;
						for (int k = 0; k < cave.size(); k++)
						{
							for (int j = 0; j < cave[0].size(); j++)
							{
								if (cave[k][j] == '@')
								{
									cave[k][j] = '#';
								}
							}
						}
						checkSize = true;
						newRock = true;
						stopFalls = false;
						betweenRocks = false;
						counter++;
						if (counter == 5)
						{
							counter = 0;
						}
						height = 0;
						for (int i = 0; i < cave.size() - 1; i++)
						{
							bool checkHeight = true;
							for (int j = 0; j < cave[i].size(); j++)
							{
								if (checkHeight)
								{
									if (cave[i][j] == '#')
									{
										height++;
										checkHeight = false;
									}
								}
							}
						}
						falls = false;
					}
				}
				if (isAir)
				{
					int helper_x = -1;
					int helper_y = -1;
					for (int k = 1; k < cave.size(); k++)
					{
						for (int j = 0; j < cave[0].size(); j++)
						{
							if (cave[k][j] == '@' && cave[k-1][j]!='#')
							{
								if (helper_x > j || helper_x == -1)
								{
									helper_x = j;
									j = cave[0].size();
								}
								if (helper_y > k || helper_y == -1)
								{
									helper_y = k;
								}
							}
						}
					}
					std::vector< std::vector<char>> helperCurrent;
					for (int k = helper_y; k < helper_y + allRockTypes[counter].size(); k++)
					{
						helperCurrent.push_back(std::vector<char>());
						for (int j = helper_x; j < helper_x + allRockTypes[counter][0].size(); j++)
						{
							helperCurrent[k-helper_y].push_back(cave[k][j]);
							cave[k][j] = '.';
						}
					}
					for (int k = helper_y; k < helper_y + allRockTypes[counter].size(); k++)
					{
						for (int j = helper_x; j < helper_x + allRockTypes[counter][0].size(); j++)
						{
							if (cave[k][j] == '#')
							{
								if (cave[k - 1][j] == '@')
								{
									cave[k - 1][j] = '.';
								}
							}
							else if (cave[k - 1][j] != '#')
							{
								cave[k-1][j] = helperCurrent[k - helper_y][j - helper_x];
							}
						}
					}
					falls = false;
				}
				
			}
			for (int j = 0; j < cave[0].size(); j++)
			{
				if (!stopFalls)
				{
					int helper_x = -1;
					int helper_y = -1;
					for (int k = 1; k < cave.size(); k++)
					{
						for (int j = 0; j < cave[0].size(); j++)
						{
							if (cave[k][j] == '@')
							{
								if (helper_x > j || helper_x == -1)
								{
									helper_x = j;
									j = cave[0].size();
								}
								if (helper_y > k || helper_y == -1)
								{
									helper_y = k;
								}
							}
						}
					}
					if (helper_x != -1 && helper_y != -1)
					{
						for (int i = helper_x; i < helper_x + allRockTypes[counter][0].size(); i++)
						{
							if (cave[helper_y - 1][i] == '#')
							{
								stopFalls = true;
							}
						}
					}
				}
			}
		}
	}
	
	for (int i = cave.size()-1; i >= 0; i--)
	{
		for (int j = 0; j < cave[i].size(); j++)
		{
			std::cout << cave[i][j];
		}
		std::cout << "\n";
	}

	std::cout << height << std::endl;

	o.close();

	system("PAUSE");
	return 0;
}
*/



//#2