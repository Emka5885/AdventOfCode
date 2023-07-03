/*
//#1
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

const int ROW = 160, COLUMN = 100;
const int OFFSETX = 440;

int main()
{
	std::ifstream o("AdventOfCode//2022//File_txt//14-12-2022.txt");

	std::string input;

	std::vector<std::vector<char>> cave;
	std::vector<std::vector<char>> paths;

	paths.push_back(std::vector<char>());
	paths.push_back(std::vector<char>());

	for (int i = 0; i < ROW; i++)
	{
		cave.push_back(std::vector<char>());
		for(int j = 0; j < COLUMN; j++)
			cave[i].push_back('.');
	}

	cave[0][500 - OFFSETX] = '+';

	while (!o.eof())
	{
		while (getline(o, input))
		{
			bool x = true;
			paths[0].push_back(' ');
			for (int i = 0; i < input.size(); i++)
			{
				if (input[i] == ',')
				{
					x = false;
					paths[1].push_back(' ');
				}
				else if (input[i] == '-')
				{
					x = true;
					paths[0].push_back(' ');
				}
				if (x)
				{
					if (isdigit(input[i]))
						paths[0].push_back(input[i]);
				}
				else
				{
					if (isdigit(input[i]))
						paths[1].push_back(input[i]);
				}
				
			}

			paths[0].push_back(' ');
			paths[1].push_back(' ');

			std::string p;
			std::vector<int> row, column;
			for (int i = 0; i < paths[0].size(); i++)
			{
				if (isdigit(paths[0][i]))
				{
					p += paths[0][i];
				}
				else
				{
					if (!p.empty())
					{
						int num = stoi(p);
						column.push_back(num);
					}
					p.clear();
				}
			}
			for (int i = 0; i < paths[1].size(); i++)
			{
				if (isdigit(paths[1][i]))
				{
					p += paths[1][i];
				}
				else
				{
					if (!p.empty())
					{
						int num = stoi(p);
						row.push_back(num);
					}
					p.clear();
				}
			}

			for (int i = 0; i < column.size()-1; i++)
			{
				std::pair<int, int> coordinates1, coordinates2;
				coordinates1.first = column[i] - OFFSETX;
				coordinates1.second = row[i];
				coordinates2.first = column[i+1] - OFFSETX;
				coordinates2.second = row[i+1];

				if (coordinates1.first > coordinates2.first)
				{
					for (int j = coordinates2.first; j <= coordinates1.first; j++)
					{
						cave[coordinates1.second][j] = '#';
					}
				}
				else if (coordinates1.first < coordinates2.first)
				{
					for (int j = coordinates1.first; j <= coordinates2.first; j++)
					{
						cave[coordinates1.second][j] = '#';
					}
				}
				else if (coordinates1.second > coordinates2.second)
				{
					for (int j = coordinates2.second; j <= coordinates1.second; j++)
					{
						cave[j][coordinates1.first] = '#';
					}
				}
				else if (coordinates1.second < coordinates2.second)
				{
					for (int j = coordinates1.second; j <= coordinates2.second; j++)
					{
						cave[j][coordinates1.first] = '#';
					}
				}
			}

			paths[0].clear(); paths[1].clear();
		}
	}

	bool test = true;
	while (test)
	{
		std::pair<int, int> sand;
		sand.first = 500 - OFFSETX;
		sand.second = 1;
		int count = 1;
		bool check = true;
		while (check)
		{
			if (count == 3 && (sand.second + 1 == ROW || sand.first + 1 == COLUMN || sand.first - 1 == 0))
				check = false;

			switch (count)
			{
			case 1:
				if (cave[sand.second + 1][sand.first] == '#')
				{
					if (cave[sand.second + 1][sand.first - 1] == '.')
					{
						sand.first--;
						sand.second++;
					}
					else if (cave[sand.second + 1][sand.first + 1] == '.')
					{
						sand.first++;
						sand.second++;
					}
					else
					{
						check = false;
						cave[sand.second][sand.first] = 'O';
					}
				}
				else if (sand.second + 1 == ROW -1)
				{
					test = false;
					check = false;
				}
				else if (cave[sand.second + 1][sand.first] == 'O')
					count++;
				else
					sand.second++;

				break;
			case 2:
				if (cave[sand.second + 1][sand.first - 1] == 'O' || cave[sand.second + 1][sand.first - 1] == '#')
					count++;
				else
				{
					sand.second++;
					sand.first--;
					if (cave[sand.second + 1][sand.first - 1] == '.')
					{
						count--;
						sand.second++;
						sand.first--;
					}
					else if (cave[sand.second + 1][sand.first] == '#')
					{
						check = false;
						cave[sand.second][sand.first] = 'O';
					}
					else if (sand.second + 1 == ROW -1 || sand.first - 1 == 0)
						count++;
					else if (cave[sand.second + 1][sand.first] == 'O')
					{
						if (cave[sand.second + 1][sand.first - 1] == 'O' || cave[sand.second + 1][sand.first - 1] == '#')
							cave[sand.second][sand.first] = 'O';
					}
				}

				break;
			case 3:
				if (cave[sand.second + 1][sand.first + 1] == 'O' || cave[sand.second + 1][sand.first + 1] == '#')
				{
					check = false;
					cave[sand.second][sand.first] = 'O';
				}
				else
				{
					sand.second++;
					sand.first++;
					if (cave[sand.second + 1][sand.first + 1] == '.')
					{
						count = 1;
						sand.second++;
						sand.first++;
					}
					else if (cave[sand.second + 1][sand.first] == '#')
					{
						check = false;
						cave[sand.second][sand.first] = 'O';
					}
					else if (sand.second + 1 == ROW -1 || sand.first + 1 == COLUMN -1)
					{
						test = false;
						check = false;
					}
					else if (cave[sand.second + 1][sand.first] == 'O')
					{
						if (cave[sand.second + 1][sand.first + 1] == 'O' || cave[sand.second + 1][sand.first + 1] == '#')
							cave[sand.second][sand.first] = 'O';
					}
				}


				break;
			}
		}

		if (cave[1][500 - OFFSETX] == 'O')
			test = false;
	}

	int result = 0;
	for (int i = 0; i < cave.size(); i++)
	{
		for (int j = 0; j < cave[i].size(); j++)
		{
			if (cave[i][j] == 'O')
				result++;
		}
	}

	std::cout << result << std::endl;

	o.close();

	system("PAUSE");
	return 0;
}
*/



/*
//#2
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

const int ROW = 160, COLUMN = 600;
const int OFFSETX = 200;

int main()
{
	std::ifstream o("AdventOfCode//2022//File_txt//14-12-2022.txt");

	std::string input;

	std::vector<std::vector<char>> cave;
	std::vector<std::vector<char>> paths;

	paths.push_back(std::vector<char>());
	paths.push_back(std::vector<char>());

	for (int i = 0; i < ROW; i++)
	{
		cave.push_back(std::vector<char>());
		for (int j = 0; j < COLUMN; j++)
			cave[i].push_back('.');
	}

	cave[0][500 - OFFSETX] = '+';

	int y = 0;

	while (!o.eof())
	{
		while (getline(o, input))
		{
			bool x = true;
			paths[0].push_back(' ');
			for (int i = 0; i < input.size(); i++)
			{
				if (input[i] == ',')
				{
					x = false;
					paths[1].push_back(' ');
				}
				else if (input[i] == '-')
				{
					x = true;
					paths[0].push_back(' ');
				}
				if (x)
				{
					if (isdigit(input[i]))
						paths[0].push_back(input[i]);
				}
				else
				{
					if (isdigit(input[i]))
						paths[1].push_back(input[i]);
				}

			}

			paths[0].push_back(' ');
			paths[1].push_back(' ');

			std::string p;
			std::vector<int> row, column;
			for (int i = 0; i < paths[0].size(); i++)
			{
				if (isdigit(paths[0][i]))
				{
					p += paths[0][i];
				}
				else
				{
					if (!p.empty())
					{
						int num = stoi(p);
						column.push_back(num);
					}
					p.clear();
				}
			}
			for (int i = 0; i < paths[1].size(); i++)
			{
				if (isdigit(paths[1][i]))
				{
					p += paths[1][i];
				}
				else
				{
					if (!p.empty())
					{
						int num = stoi(p);
						if (num > y)
							y = num;
						row.push_back(num);
					}
					p.clear();
				}
			}

			for (int i = 0; i < column.size() - 1; i++)
			{
				std::pair<int, int> coordinates1, coordinates2;
				coordinates1.first = column[i] - OFFSETX;
				coordinates1.second = row[i];
				coordinates2.first = column[i + 1] - OFFSETX;
				coordinates2.second = row[i + 1];

				if (coordinates1.first > coordinates2.first)
				{
					for (int j = coordinates2.first; j <= coordinates1.first; j++)
					{
						cave[coordinates1.second][j] = '#';
					}
				}
				else if (coordinates1.first < coordinates2.first)
				{
					for (int j = coordinates1.first; j <= coordinates2.first; j++)
					{
						cave[coordinates1.second][j] = '#';
					}
				}
				else if (coordinates1.second > coordinates2.second)
				{
					for (int j = coordinates2.second; j <= coordinates1.second; j++)
					{
						cave[j][coordinates1.first] = '#';
					}
				}
				else if (coordinates1.second < coordinates2.second)
				{
					for (int j = coordinates1.second; j <= coordinates2.second; j++)
					{
						cave[j][coordinates1.first] = '#';
					}
				}
			}

			paths[0].clear(); paths[1].clear();
		}
	}

	y += 2;

	for (int i = 0; i < COLUMN; i++)
	{
		cave[y][i] = '#';
	}

	bool test = true;
	while (test)
	{
		std::pair<int, int> sand;
		sand.first = 500 - OFFSETX;
		sand.second = 0;
		int count = 1;
		bool check = true;
		while (check)
		{
			if (count == 3 && (sand.second + 1 == ROW || sand.first + 1 == COLUMN || sand.first - 1 == 0))
				check = false;

			switch (count)
			{
			case 1:
				if (cave[sand.second + 1][sand.first] == '#')
				{
					if (cave[sand.second + 1][sand.first - 1] == '.')
					{
						sand.first--;
						sand.second++;
					}
					else if (cave[sand.second + 1][sand.first + 1] == '.')
					{
						sand.first++;
						sand.second++;
					}
					else
					{
						check = false;
						cave[sand.second][sand.first] = 'O';
					}
				}
				else if (sand.second + 1 == ROW - 1)
				{
					test = false;
					check = false;
				}
				else if (cave[sand.second + 1][sand.first] == 'O')
					count++;
				else
					sand.second++;

				break;
			case 2:
				if (cave[sand.second + 1][sand.first - 1] == 'O' || cave[sand.second + 1][sand.first - 1] == '#')
					count++;
				else
				{
					sand.second++;
					sand.first--;
					if (cave[sand.second + 1][sand.first - 1] == '.')
					{
						count--;
						sand.second++;
						sand.first--;
					}
					else if (cave[sand.second + 1][sand.first] == '#')
					{
						check = false;
						cave[sand.second][sand.first] = 'O';
					}
					else if (sand.second + 1 == ROW - 1 || sand.first - 1 == 0)
						count++;
					else if (cave[sand.second + 1][sand.first] == 'O')
					{
						if (cave[sand.second + 1][sand.first - 1] == 'O' || cave[sand.second + 1][sand.first - 1] == '#')
							cave[sand.second][sand.first] = 'O';
					}
				}

				break;
			case 3:
				if (cave[sand.second + 1][sand.first + 1] == 'O' || cave[sand.second + 1][sand.first + 1] == '#')
				{
					check = false;
					cave[sand.second][sand.first] = 'O';
				}
				else
				{
					sand.second++;
					sand.first++;
					if (cave[sand.second + 1][sand.first + 1] == '.')
					{
						count = 1;
						sand.second++;
						sand.first++;
					}
					else if (cave[sand.second + 1][sand.first] == '#')
					{
						check = false;
						cave[sand.second][sand.first] = 'O';
					}
					else if (sand.second + 1 == ROW - 1 || sand.first + 1 == COLUMN - 1)
					{
						test = false;
						check = false;
					}
					else if (cave[sand.second + 1][sand.first] == 'O')
					{
						if (cave[sand.second + 1][sand.first + 1] == 'O' || cave[sand.second + 1][sand.first + 1] == '#')
							cave[sand.second][sand.first] = 'O';
					}
				}


				break;
			}
		}

		if (cave[0][500 - OFFSETX] == 'O')
			test = false;
	}

	int result = 0;
	for (int i = 0; i < cave.size(); i++)
	{
		for (int j = 0; j < cave[i].size(); j++)
		{
			if (cave[i][j] == 'O')
				result++;
		}
	}

	std::cout << result << std::endl;

	o.close();

	system("PAUSE");
	return 0;
}
*/