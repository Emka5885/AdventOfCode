/*
//#1
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <queue>
#include <set>


struct Point
{
	int x;
	int y;
};

int main()
{
	std::ifstream o("AdventOfCode//2022//File_txt//12-12-2022.txt");

	std::string input;

	Point start, endE;
	start.x = 0; start.y = 0; endE.x = 0; endE.y = 0;

	std::vector<std::vector<char>> letters;

	while (!o.eof())
	{
		while (getline(o, input))
		{
			letters.push_back(std::vector<char>());

			for (int n : input)
			{
				letters[letters.size() - 1].push_back(n);
			}
		}
	}

	o.close();

	for (int i = 0; i < letters.size(); i++)
	{
		for (int j = 0; j < letters[i].size(); j++)
		{
			if (letters[i][j] == 'S')
			{
				start.x = i;
				start.y = j;
				letters[i][j] = 'a';
			}
			else if (letters[i][j] == 'E')
			{
				endE.x = i;
				endE.y = j;
				letters[i][j] = 'z';
			}
		}
	}

	int dist = 0;
	std::set<std::pair<int, int>> visited;

	std::vector<Point> shortPath;

	shortPath.push_back(start);

	Point dire[4];
	dire[0] = Point{ 0, 1 };
	dire[1] = Point{ 1, 0 };
	dire[2] = Point{ -1, 0 };
	dire[3] = Point{ 0, -1 };
	bool turn = false;
	std::queue<Point> explore;
	std::queue<Point> explore2;
	explore.push(start);
	std::pair<int, int> helper{ start.x,start.y };
	visited.insert(helper);
	dist++;

	bool found = false;

	while (!found && (!explore.empty() || !explore2.empty()))
	{
		if ((!turn && explore.empty()) || (turn && explore2.empty()))
		{
			dist++;
			turn = !turn;
		}

		Point current;
		if (!turn)
		{
			current = explore.front();
			explore.pop();
		}
		else
		{
			current = explore2.front();
			explore2.pop();
		}

		int x = current.x;
		int y = current.y;
		for (Point move : dire)
		{
			int x2 = x + move.x;
			int y2 = y + move.y;

			if (x2 >= 0 && x2 < letters.size() && y2 >= 0 && y2 < letters[0].size())
			{
				bool end;

				if (endE.x == x2 && endE.y == y2)
					end = true;
				else
					end = false;


				if (letters[x2][y2] <= letters[x][y] + 1)
				{
					if (end)
					{
						found = true;
						break;
					}

					helper = { x2, y2 };
					bool b = visited.insert(helper).second;
					if (b)
					{
						if (!turn)
							explore2.push({ helper.first, helper.second });
						else
							explore.push({ helper.first, helper.second });
					}
				}
			}
		}
	}

	std::cout << dist << "\n";

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
#include <queue>
#include <set>
#include <algorithm>


struct Point
{
	int x;
	int y;
};

int main()
{
	std::ifstream o("AdventOfCode//2022//File_txt//12-12-2022.txt");

	std::string input;

	Point endE;
	endE.x = 0; endE.y = 0;

	std::vector<std::vector<char>> letters;
	std::vector<Point> letters_a;

	while (!o.eof())
	{
		while (getline(o, input))
		{
			letters.push_back(std::vector<char>());

			for (int n : input)
			{
				letters[letters.size() - 1].push_back(n);
			}
		}
	}

	o.close();

	for (int i = 0; i < letters.size(); i++)
	{
		for (int j = 0; j < letters[i].size(); j++)
		{
			if (letters[i][j] == 'S')
			{
				letters[i][j] = 'a';
				letters_a.push_back({ i,j });
			}
			else if (letters[i][j] == 'E')
			{
				endE.x = i;
				endE.y = j;
				letters[i][j] = 'z';
			}
			else if (letters[i][j] == 'a')
			{
				letters_a.push_back({ i,j });
			}
		}
	}

	std::vector<int> distances;

	for (int k = 0; k < letters_a.size(); k++)
	{
		int dist = 0;
		std::set<std::pair<int, int>> visited;

		std::vector<Point> shortPath;

		shortPath.push_back(letters_a[k]);

		Point dire[4];
		dire[0] = Point{ 0, 1 };
		dire[1] = Point{ 1, 0 };
		dire[2] = Point{ -1, 0 };
		dire[3] = Point{ 0, -1 };
		bool turn = false;
		std::queue<Point> explore;
		std::queue<Point> explore2;
		explore.push(letters_a[k]);
		std::pair<int, int> helper{ letters_a[k].x,letters_a[k].y };
		visited.insert(helper);
		dist++;

		bool found = false;

		while (!found && (!explore.empty() || !explore2.empty()))
		{
			if ((!turn && explore.empty()) || (turn && explore2.empty()))
			{
				dist++;
				turn = !turn;
			}

			Point current;
			if (!turn)
			{
				current = explore.front();
				explore.pop();
			}
			else
			{
				current = explore2.front();
				explore2.pop();
			}

			int x = current.x;
			int y = current.y;
			for (Point move : dire)
			{
				int x2 = x + move.x;
				int y2 = y + move.y;

				if (x2 >= 0 && x2 < letters.size() && y2 >= 0 && y2 < letters[0].size())
				{
					bool end;

					if (endE.x == x2 && endE.y == y2)
						end = true;
					else
						end = false;


					if (letters[x2][y2] <= letters[x][y] + 1)
					{
						if (end)
						{
							found = true;
							break;
						}

						helper = { x2, y2 };
						bool b = visited.insert(helper).second;
						if (b)
						{
							if (!turn)
								explore2.push({ helper.first, helper.second });
							else
								explore.push({ helper.first, helper.second });
						}
					}
				}
			}
		}

		if(found)
			distances.push_back(dist);
	}

	std::sort(distances.begin(), distances.end());

	std::cout << distances[0] << "\n";

	system("PAUSE");
	return 0;
}
*/