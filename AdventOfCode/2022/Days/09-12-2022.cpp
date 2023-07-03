/*
//#1
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct point
{
	int x;
	int y;
};

int main()
{
	ifstream o("AdventOfCode//2022//File_txt//09-12-2022.txt");

	string input, str;
	vector<vector<char>> positions;

	positions.push_back(vector<char>());
	positions[0].push_back('S');

	int uniquePoints = 0, num, n = 0, m = 0;
	point H, T;
	H.x = 0, H.y = 0, T.x = 0, T.y = 0;

	while (!o.eof())
	{
		while (getline(o, input))
		{
			for (int i = 0; i < input.size(); i++)
			{
				if (isdigit(input[i]))
					str.push_back(input[i]);
			}
			string number(str.begin(), str.end());
			num = stoi(number);

			switch (input[0])
			{
			case 'U':
				H.y += num;
				while (H.y + n >= positions.size())
				{
					positions.push_back(vector<char>());
					for (int i = 0; i < positions[0].size(); i++)
						positions[positions.size() - 1].push_back('.');
				}
				if (H.x != T.x)
				{
					bool start = true;
					while (H.y - T.y > 1)
					{
						if (start)
						{
							int pom;
							if (H.x > T.x)
								pom = 1;
							else
								pom = -1;
							T.x += pom;
							positions[T.y + 1 + n][T.x + m] = '#';
							start = false;
						}
						else
							positions[T.y + 1 + n][H.x + m] = '#';
						T.y++;
					}
				}
				else
				{
					while (H.y - T.y > 1)
					{
						T.y++;
						if (positions[T.y + n][H.x + m] != '#')
							positions[T.y + n][H.x + m] = '#';
					}
				}
				break;
			case 'D':
				H.y -= num;
				while (abs(H.y) > n)
				{
					vector<vector<char>> helper;
					for (int i = 0; i < positions.size(); i++)
					{
						helper.push_back(vector<char>());
						for (int j = 0; j < positions[0].size(); j++)
							helper[i].push_back(positions[i][j]);
					}
					positions.clear();
					n++;

					positions.push_back(vector<char>());
					for (int i = 0; i < helper.size(); i++)
					{
						positions.push_back(vector<char>());
						for (int j = 0; j < helper[0].size(); j++)
							positions[i + 1].push_back(helper[i][j]);
					}
					for (int i = 0; i < positions[positions.size() - 1].size(); i++)
						positions[0].push_back('.');

				}
				if (H.x != T.x)
				{
					bool start = true;
					while (abs(H.y - T.y) > 1)
					{
						if (start)
						{
							int pom;
							if (H.x > T.x)
								pom = 1;
							else
								pom = -1;
							T.x += pom;
							positions[T.y - 1 + n][T.x + m] = '#';
							start = false;
						}
						else
							positions[T.y - 1 + n][H.x + m] = '#';
						T.y--;
					}
				}
				else
				{
					while (abs(H.y - T.y) > 1)
					{
						T.y--;
						if (positions[T.y + n][H.x + m] != '#')
							positions[T.y + n][H.x + m] = '#';
					}
				}
				break;
			case 'L':
				H.x -= num;
				while (abs(H.x) > m)
				{
					vector<vector<char>> helper;
					for (int i = 0; i < positions.size(); i++)
					{
						helper.push_back(vector<char>());
						for (int j = 0; j < positions[0].size(); j++)
							helper[i].push_back(positions[i][j]);
					}
					positions.clear();
					m++;

					for (int i = 0; i < helper.size(); i++)
					{
						positions.push_back(vector<char>());
						positions[i].push_back('.');
						for (int j = 0; j < helper[0].size(); j++)
							positions[i].push_back(helper[i][j]);
					}
				}
				if (H.y != T.y)
				{
					bool start = true;
					while (abs(H.x - T.x) > 1)
					{
						if (start)
						{
							int pom;
							if (H.y > T.y)
								pom = 1;
							else
								pom = -1;
							T.y += pom;
							positions[T.y + n][T.x - 1 + m] = '#';
							start = false;
						}
						else
							positions[T.y + n][T.x - 1 + m] = '#';
						T.x--;
					}
				}
				else
				{
					while (abs(H.x - T.x) > 1)
					{
						if (positions[H.y + n][T.x - 1 + m] != '#')
							positions[H.y + n][T.x - 1 + m] = '#';
						T.x--;
					}
				}
				break;
			case 'R':
				H.x += num;
				while (H.x + m >= positions[0].size())
				{
					for (int i = 0; i < positions.size(); i++)
						positions[i].push_back('.');
				}
				if (H.y != T.y)
				{
					bool start = true;
					while (H.x - T.x > 1)
					{
						if (start)
						{
							int pom;
							if (H.y > T.y)
								pom = 1;
							else
								pom = -1;
							T.y += pom;
							positions[T.y + n][T.x + 1 + m] = '#';
							start = false;
						}
						else
							positions[T.y + n][T.x + 1 + m] = '#';
						T.x++;
					}
				}
				else
				{
					while (H.x - T.x > 1)
					{
						if (positions[H.y + n][T.x + 1 + m] != '#')
							positions[H.y + n][T.x + 1 + m] = '#';
						T.x++;
					}
				}
				break;
			}
			str.clear();
		}
	}

	for (int i = 0; i < positions.size(); i++)
	{
		for (int j = 0; j < positions[i].size(); j++)
			if (positions[i][j] == '#')
				uniquePoints++;
	}

	cout << uniquePoints << endl;
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

using namespace std;

struct point
{
	int x;
	int y;
};

point knots[9] = {};
vector<vector<char>> positions;
int uniquePoints = 0, n, m;

void moveTail(point* head, int curKnot) {
	int xDis = head->x - knots[curKnot].x;
	int yDis = head->y - knots[curKnot].y;
	if ((abs(xDis) + abs(yDis) > 2)) {
		knots[curKnot].x += (xDis > 0 ? 1 : -1);
		knots[curKnot].y += (yDis > 0 ? 1 : -1);
	}
	else if (abs(xDis) > 1) knots[curKnot].x += (xDis > 0 ? 1 : -1);
	else if (abs(yDis) > 1) knots[curKnot].y += (yDis > 0 ? 1 : -1);
	else return;
	if (curKnot == 9 - 1)
	{
		if (positions[knots[9 - 1].y + n][knots[9 - 1].x + m] != '#')
			positions[knots[9 - 1].y + n][knots[9 - 1].x + m] = '#';
	}
	if (curKnot + 1 < 9) moveTail(&knots[curKnot], curKnot + 1);
}

int main()
{
	ifstream o("AdventOfCode//2022//File_txt//09-12-2022.txt");

	int uniqueLocations = 0;

	string input, str;

	positions.push_back(vector<char>());
	positions[0].push_back('S');

	int num;
	n = 0, m = 0;
	point H, T;
	H.x = 0, H.y = 0, T.x = 0, T.y = 0;

	while (!o.eof())
	{
		while (getline(o, input))
		{
			for (int i = 0; i < input.size(); i++)
			{
				if (isdigit(input[i]))
					str.push_back(input[i]);
			}
			string number(str.begin(), str.end());
			num = stoi(number);

			switch (input[0])
			{
			case 'U':
				H.y += num;
				while (H.y + n >= positions.size())
				{
					positions.push_back(vector<char>());
					for (int i = 0; i < positions[0].size(); i++)
						positions[positions.size() - 1].push_back('.');
				}
				H.y -= num;
				for (int i = 0; i < num; i++) {
					H.y++;
					moveTail(&H, 0);
				}
				break;
			case 'D':
				H.y -= num;
				while (abs(H.y) > n)
				{
					vector<vector<char>> helper;
					for (int i = 0; i < positions.size(); i++)
					{
						helper.push_back(vector<char>());
						for (int j = 0; j < positions[0].size(); j++)
							helper[i].push_back(positions[i][j]);
					}
					positions.clear();
					n++;

					positions.push_back(vector<char>());
					for (int i = 0; i < helper.size(); i++)
					{
						positions.push_back(vector<char>());
						for (int j = 0; j < helper[0].size(); j++)
							positions[i + 1].push_back(helper[i][j]);
					}
					for (int i = 0; i < positions[positions.size() - 1].size(); i++)
						positions[0].push_back('.');

				}
				H.y += num;
				for (int i = 0; i < num; i++) {
					H.y--;
					moveTail(&H, 0);
				}
				break;
			case 'L':
				H.x -= num;
				while (abs(H.x) > m)
				{
					vector<vector<char>> helper;
					for (int i = 0; i < positions.size(); i++)
					{
						helper.push_back(vector<char>());
						for (int j = 0; j < positions[0].size(); j++)
							helper[i].push_back(positions[i][j]);
					}
					positions.clear();
					m++;

					for (int i = 0; i < helper.size(); i++)
					{
						positions.push_back(vector<char>());
						positions[i].push_back('.');
						for (int j = 0; j < helper[0].size(); j++)
							positions[i].push_back(helper[i][j]);
					}
				}
				H.x += num;
				for (int i = 0; i < num; i++) {
					H.x--;
					moveTail(&H, 0);
				}
				break;
			case 'R':
				H.x += num;
				while (H.x + m >= positions[0].size())
				{
					for (int i = 0; i < positions.size(); i++)
						positions[i].push_back('.');
				}
				H.x -= num;
				for (int i = 0; i < num; i++) {
					H.x++;
					moveTail(&H, 0);
				}
				break;
			}
			str.clear();
		}
	}

	for (int i = positions.size() - 1; i >= 0; i--)
	{
		for (int j = 0; j < positions[i].size(); j++)
			if (positions[i][j] == '#' || positions[i][j] == 'S')
				uniqueLocations++;
	}
	cout << uniqueLocations << endl;

	o.close();

	system("PAUSE");
	return 0;
}
*/