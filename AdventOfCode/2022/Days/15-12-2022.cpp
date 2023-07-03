/*
//#1
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

const int MAGIC_NUMBER = 48, Y = 2000000;

bool sortbysec(const std::pair<int, int>& a, const std::pair<int, int>& b)
{
	return (a.second < b.second);
}

int main()
{
	std::ifstream o("AdventOfCode//2022//File_txt//15-12-2022.txt");

	std::string input;

	std::vector<std::pair<int, int>> coordinates;

	while (!o.eof())
	{
		while (getline(o, input))
		{
			if (!input.empty())
			{
				coordinates.push_back(std::pair<int, int>());
				coordinates.push_back(std::pair<int, int>());
				bool sensor = true;
				bool x = true;
				std::string str;
				bool test = false;
				for (int i = 0; i < input.size(); i++)
				{					
					if (sensor)
					{
						if (x)
						{
							if (input[i] == '-')
							{
								str.push_back(input[i]);
							}
							else if (isdigit(input[i]))
							{
								str.push_back(input[i]);
								test = true;
							}
							else
							{
								if (test)
								{
									coordinates[coordinates.size() - 2].first = stoi(str);
									x = false;
									test = false;
									str.clear();
								}
							}
						}
						else
						{
							if (input[i] == '-')
							{
								str.push_back(input[i]);
							}
							else if (isdigit(input[i]))
							{
								str.push_back(input[i]);
								test = true;
							}
							else
							{
								if (test)
								{
									coordinates[coordinates.size() - 2].second = stoi(str);
									x = true;
									sensor = false;
									test = false;
									str.clear();
								}
							}
						}
					}
					else
					{
						if (x)
						{
							if (input[i] == '-')
							{
								str.push_back(input[i]);
							}
							else if (isdigit(input[i]))
							{
								str.push_back(input[i]);
								test = true;
							}
							else
							{
								if (test)
								{
									coordinates[coordinates.size() - 1].first = stoi(str);
									x = false;
									test = false;
									str.clear();
								}
							}
						}
						else
						{
							if (input[i] == '-')
							{
								str.push_back(input[i]);
							}
							else if (isdigit(input[i]))
							{
								str.push_back(input[i]);
								
								if (i + 1 == input.size())
								{
									coordinates[coordinates.size() - 1].second = stoi(str);
									x = true;
									sensor = true;
									str.clear();
								}
							}
						}
					}
				}
			}
		}
	}

	std::vector<std::pair<int,int>> xCanNotBeBeacon;
	std::vector<int> xIsBeacon;
	std::vector<bool> check;

	for (int i = 1; i < coordinates.size(); i += 2)
	{
		if (coordinates[i].second == Y)
		{
			if (std::count(xIsBeacon.begin(), xIsBeacon.end(), coordinates[i].first) == 0)
			{
				xIsBeacon.push_back(coordinates[i].first);
				check.push_back(false);
			}
		}
	}


	for (int i = 0; i < coordinates.size(); i+=2)
	{
		int number;
		number = abs(coordinates[i].first - coordinates[i + 1].first) + abs(coordinates[i].second - coordinates[i + 1].second);
		if (coordinates[i].second + number >= Y && coordinates[i].second <= Y)
		{
			int helper = Y - coordinates[i].second;

			xCanNotBeBeacon.push_back(std::pair<int, int>());
			xCanNotBeBeacon[xCanNotBeBeacon.size()-1].first = (coordinates[i].first - (number - helper));
			xCanNotBeBeacon[xCanNotBeBeacon.size() - 1].second = (coordinates[i].first + (number - helper));
		}
		if (coordinates[i].second - number <= Y && coordinates[i].second >= Y)
		{
			int helper = Y - coordinates[i].second;

			xCanNotBeBeacon.push_back(std::pair<int, int>());
			xCanNotBeBeacon[xCanNotBeBeacon.size() - 1].first = (coordinates[i].first - (number + helper));
			xCanNotBeBeacon[xCanNotBeBeacon.size() - 1].second = (coordinates[i].first + (number + helper));
		}
	}

	std::sort(xCanNotBeBeacon.begin(), xCanNotBeBeacon.end());

	int result = 0;

	result += xCanNotBeBeacon[0].second - xCanNotBeBeacon[0].first + 1;
	for (int j = 0; j < xIsBeacon.size(); j++)
	{
		if (xIsBeacon[j] >= xCanNotBeBeacon[0].first && xIsBeacon[j] <= xCanNotBeBeacon[0].second && !check[j])
		{
			result--;
			check[j] = true;
		}
	}

	int offset = 0;
	for (int i = 1; i < xCanNotBeBeacon.size(); i++)
	{
		std::cout << xCanNotBeBeacon[i].first << ":" << xCanNotBeBeacon[i].second << std::endl;
		if (xCanNotBeBeacon[i].first > xCanNotBeBeacon[i - 1 - offset].second)
		{
			result += xCanNotBeBeacon[i].second - xCanNotBeBeacon[i].first + 1;

			for (int j = 0; j < xIsBeacon.size(); j++)
			{
				if (xIsBeacon[j] >= xCanNotBeBeacon[i].first && xIsBeacon[j] <= xCanNotBeBeacon[i].second && !check[j])
				{
					result--;
					check[j] = true;
				}
			}

			offset = 0;
		}
		else if (xCanNotBeBeacon[i].first < xCanNotBeBeacon[i - 1 - offset].second && xCanNotBeBeacon[i].second > xCanNotBeBeacon[i - 1 - offset].second)
		{
			result += xCanNotBeBeacon[i].second - xCanNotBeBeacon[i - 1 - offset].second;

			for (int j = 0; j < xIsBeacon.size(); j++)
			{
				if (xIsBeacon[j] >= xCanNotBeBeacon[i - 1 - offset].second && xIsBeacon[j] <= xCanNotBeBeacon[i].second && !check[j])
				{
					result--;
					check[j] = true;
				}
			}

			offset = 0;
		}
		else if (xCanNotBeBeacon[i].first == xCanNotBeBeacon[i - 1 - offset].second && xCanNotBeBeacon[i].second > xCanNotBeBeacon[i - 1 - offset].second)
		{
			result += xCanNotBeBeacon[i].second - xCanNotBeBeacon[i].first;

			for (int j = 0; j < xIsBeacon.size(); j++)
			{
				if (xIsBeacon[j] >= xCanNotBeBeacon[i].first && xIsBeacon[j] <= xCanNotBeBeacon[i].second && !check[j])
				{
					result--;
					check[j] = true;
				}
			}

			offset = 0;
		}
		else
		{
			offset++;
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
#include <algorithm>

const int MAGIC_NUMBER = 48, MIN = 0, MAX = 4000000;

bool sortbysec(const std::pair<int, int>& a, const std::pair<int, int>& b)
{
	return (a.second < b.second);
}

int main()
{
	std::ifstream o("AdventOfCode//2022//File_txt//15-12-2022.txt");

	std::string input;

	std::vector<std::pair<int, int>> coordinates;

	while (!o.eof())
	{
		while (getline(o, input))
		{
			if (!input.empty())
			{
				coordinates.push_back(std::pair<int, int>());
				coordinates.push_back(std::pair<int, int>());
				bool sensor = true;
				bool x = true;
				std::string str;
				bool test = false;
				for (int i = 0; i < input.size(); i++)
				{
					if (sensor)
					{
						if (x)
						{
							if (input[i] == '-')
							{
								str.push_back(input[i]);
							}
							else if (isdigit(input[i]))
							{
								str.push_back(input[i]);
								test = true;
							}
							else
							{
								if (test)
								{
									coordinates[coordinates.size() - 2].first = stoi(str);
									x = false;
									test = false;
									str.clear();
								}
							}
						}
						else
						{
							if (input[i] == '-')
							{
								str.push_back(input[i]);
							}
							else if (isdigit(input[i]))
							{
								str.push_back(input[i]);
								test = true;
							}
							else
							{
								if (test)
								{
									coordinates[coordinates.size() - 2].second = stoi(str);
									x = true;
									sensor = false;
									test = false;
									str.clear();
								}
							}
						}
					}
					else
					{
						if (x)
						{
							if (input[i] == '-')
							{
								str.push_back(input[i]);
							}
							else if (isdigit(input[i]))
							{
								str.push_back(input[i]);
								test = true;
							}
							else
							{
								if (test)
								{
									coordinates[coordinates.size() - 1].first = stoi(str);
									x = false;
									test = false;
									str.clear();
								}
							}
						}
						else
						{
							if (input[i] == '-')
							{
								str.push_back(input[i]);
							}
							else if (isdigit(input[i]))
							{
								str.push_back(input[i]);

								if (i + 1 == input.size())
								{
									coordinates[coordinates.size() - 1].second = stoi(str);
									x = true;
									sensor = true;
									str.clear();
								}
							}
						}
					}
				}
			}
		}
	}


	uint64_t searchedForY = 0, searchedForX = 0;

	for (int k = 0; k <= MAX; k++)
	{
		int Y = k;
		//std::cout << Y << '\n';

		std::vector<int> xIsBeacon;
		std::vector<std::pair<int, int>> xCanNotBeBeacon;
		std::vector<bool> check;
		for (int i = 1; i < coordinates.size(); i += 2)
		{
			if (coordinates[i].second == Y && coordinates[i].first >= MIN && coordinates[i].first <= MAX)
			{
				if (std::count(xIsBeacon.begin(), xIsBeacon.end(), coordinates[i].first) == 0)
				{
					xIsBeacon.push_back(coordinates[i].first);
					check.push_back(false);
				}
			}
		}

		for (int i = 0; i < coordinates.size(); i += 2)
		{
			int number;
			number = abs(coordinates[i].first - coordinates[i + 1].first) + abs(coordinates[i].second - coordinates[i + 1].second);
			if (coordinates[i].second + number >= Y && coordinates[i].second <= Y)
			{
				int helper = Y - coordinates[i].second;

				xCanNotBeBeacon.push_back(std::pair<int, int>());
				xCanNotBeBeacon[xCanNotBeBeacon.size() - 1].first = (coordinates[i].first - (number - helper));
				xCanNotBeBeacon[xCanNotBeBeacon.size() - 1].second = (coordinates[i].first + (number - helper));
			}
			if (coordinates[i].second - number <= Y && coordinates[i].second >= Y)
			{
				int helper = Y - coordinates[i].second;

				xCanNotBeBeacon.push_back(std::pair<int, int>());
				xCanNotBeBeacon[xCanNotBeBeacon.size() - 1].first = (coordinates[i].first - (number + helper));
				xCanNotBeBeacon[xCanNotBeBeacon.size() - 1].second = (coordinates[i].first + (number + helper));
			}
		}

		std::sort(xCanNotBeBeacon.begin(), xCanNotBeBeacon.end());

		int result = 0;

		if (xCanNotBeBeacon[0].first <= MAX && xCanNotBeBeacon[0].second >= MIN)
		{
			if (xCanNotBeBeacon[0].second > MAX)
			{
				xCanNotBeBeacon[0].second = MAX;
			}
			if (xCanNotBeBeacon[0].first < MIN)
			{
				xCanNotBeBeacon[0].first = MIN;
			}
			result += xCanNotBeBeacon[0].second - xCanNotBeBeacon[0].first + 1;

			for (int j = 0; j < xIsBeacon.size(); j++)
			{
				if (xIsBeacon[j] >= xCanNotBeBeacon[0].first && xIsBeacon[j] <= xCanNotBeBeacon[0].second && !check[j])
				{
					//result--;
					check[j] = true;
				}
			}
		}

		int offset = 0;
		for (int i = 1; i < xCanNotBeBeacon.size(); i++)
		{
			if (xCanNotBeBeacon[0].first <= MAX && xCanNotBeBeacon[0].second >= MIN)
			{
				if (xCanNotBeBeacon[i].second > MAX)
				{
					xCanNotBeBeacon[i].second = MAX;
				}
				if (xCanNotBeBeacon[i].first < MIN)
				{
					xCanNotBeBeacon[i].first = MIN;
				}
				if (xCanNotBeBeacon[i].first > xCanNotBeBeacon[i - 1 - offset].second)
				{
					result += xCanNotBeBeacon[i].second - xCanNotBeBeacon[i].first + 1;

					for (int j = 0; j < xIsBeacon.size(); j++)
					{
						if (xIsBeacon[j] >= xCanNotBeBeacon[i].first && xIsBeacon[j] <= xCanNotBeBeacon[i].second && !check[j])
						{
							//result--;
							check[j] = true;
						}
					}

					offset = 0;
				}
				else if (xCanNotBeBeacon[i].first < xCanNotBeBeacon[i - 1 - offset].second && xCanNotBeBeacon[i].second > xCanNotBeBeacon[i - 1 - offset].second)
				{
					result += xCanNotBeBeacon[i].second - xCanNotBeBeacon[i - 1 - offset].second;

					for (int j = 0; j < xIsBeacon.size(); j++)
					{
						if (xIsBeacon[j] >= xCanNotBeBeacon[i - 1 - offset].second && xIsBeacon[j] <= xCanNotBeBeacon[i].second && !check[j])
						{
							//result--;
							check[j] = true;
						}
					}

					offset = 0;
				}
				else if (xCanNotBeBeacon[i].first == xCanNotBeBeacon[i - 1 - offset].second && xCanNotBeBeacon[i].second > xCanNotBeBeacon[i - 1 - offset].second)
				{
					result += xCanNotBeBeacon[i].second - xCanNotBeBeacon[i].first;

					for (int j = 0; j < xIsBeacon.size(); j++)
					{
						if (xIsBeacon[j] >= xCanNotBeBeacon[i].first && xIsBeacon[j] <= xCanNotBeBeacon[i].second && !check[j])
						{
							//result--;
							check[j] = true;
						}
					}

					offset = 0;
				}
				else
				{
					offset++;
				}
			}
			else
			{
				offset++;
			}
		}
		if (result != MAX + 1)
		{
			std::cout << "Y:" << Y << std::endl;
			searchedForY = Y;
			break;
		}
	}

	for (int k = 0; k <= MAX; k++)
	{
		int X = k;
		//std::cout << X << '\n';

		std::vector<int> yIsBeacon;
		std::vector<std::pair<int, int>> yCanNotBeBeacon;
		std::vector<bool> check;
		bool find = false;
		for (int i = 1; i < coordinates.size(); i += 2)
		{
			if (coordinates[i].first == X && coordinates[i].second == searchedForY)
			{
				find = true;
			}
		}

		if (find)
		{
			continue;
		}
		for (int i = 0; i < coordinates.size(); i += 2)
		{
			int number;
			number = abs(coordinates[i].second - coordinates[i + 1].second) + abs(coordinates[i].first - coordinates[i + 1].first);
			if (coordinates[i].first + number >= X && coordinates[i].first <= X)
			{
				int helper = X - coordinates[i].first;

				yCanNotBeBeacon.push_back(std::pair<int, int>());
				yCanNotBeBeacon[yCanNotBeBeacon.size() - 1].second = (coordinates[i].second - (number - helper));
				yCanNotBeBeacon[yCanNotBeBeacon.size() - 1].first = (coordinates[i].second + (number - helper));
				if (yCanNotBeBeacon[yCanNotBeBeacon.size() - 1].first >= searchedForY && yCanNotBeBeacon[yCanNotBeBeacon.size() - 1].second <= searchedForY)
				{
					find = true;
				}
			}
			if (coordinates[i].first - number <= X && coordinates[i].first >= X)
			{
				int helper = X - coordinates[i].first;

				yCanNotBeBeacon.push_back(std::pair<int, int>());
				yCanNotBeBeacon[yCanNotBeBeacon.size() - 1].second = (coordinates[i].second - (number + helper));
				yCanNotBeBeacon[yCanNotBeBeacon.size() - 1].first = (coordinates[i].second + (number + helper));
				if (yCanNotBeBeacon[yCanNotBeBeacon.size() - 1].first >= searchedForY && yCanNotBeBeacon[yCanNotBeBeacon.size() - 1].second <= searchedForY)
				{
					find = true;
				}
			}
		}

		if (find)
		{
			continue;
		}
		else
		{
			std::cout << "X:" << X << std::endl;
			searchedForX = X;
			break;
		}
	}

	uint64_t result = searchedForX * 4000000 + searchedForY;
	std::cout << result << '\n';

	o.close();

	system("PAUSE");
	return 0;
}
*/