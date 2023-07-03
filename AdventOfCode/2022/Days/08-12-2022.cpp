/*
//#1
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct tree
{
	int num;
	bool visible;
};

int main()
{
	ifstream o("AdventOfCode//2022//File_txt//08-12-2022.txt");
	;
	string row;
	vector<vector<tree>> grid;
	int count = 0, r = 0, pom = 0;
	bool start = true;

	while (!o.eof())
	{
		while (getline(o, row))
		{
			grid.push_back(vector<tree>());

			tree t;

			for (int i = 0; i < row.size(); i++)
			{
				t.num = row[i] - 48;
				t.visible = false;
				grid[r].push_back(t);
			}
			r++;
		}
	}
	o.close();

	for (int i = 0; i < r; i++)
	{
		pom = grid[0][i].num;
		if (!grid[0][i].visible)
		{
			grid[0][i].visible = true;
			count++;
		}
		for (int j = 1; j < grid[i].size(); j++)
		{
			if (grid[j][i].num > pom)
			{
				if (!grid[j][i].visible)
				{
					count++;
					grid[j][i].visible = true;
				}
				pom = grid[j][i].num;
			}
		}
	}

	for (int i = 0; i < r; i++)
	{
		pom = grid[grid[i].size() - 1][i].num;
		if (!grid[grid[i].size() - 1][i].visible)
		{
			grid[grid[i].size() - 1][i].visible = true;
			count++;
		}
		for (int j = grid[i].size() - 1 - 1; j >= 0; j--)
		{
			if (grid[j][i].num > pom)
			{
				if (!grid[j][i].visible)
				{
					count++;
					grid[j][i].visible = true;
				}
				pom = grid[j][i].num;
			}
		}
	}

	for (int i = 0; i < r; i++)
	{
		pom = grid[i][0].num;
		if (!grid[i][0].visible)
		{
			grid[i][0].visible = true;
			count++;
		}
		for (int j = 1; j < grid[i].size(); j++)
		{
			if (grid[i][j].num > pom)
			{
				if (!grid[i][j].visible)
				{
					count++;
					grid[i][j].visible = true;
				}
				pom = grid[i][j].num;
			}
		}
	}

	for (int i = 0; i < r; i++)
	{
		pom = grid[i][grid[i].size() - 1].num;
		if (!grid[i][grid[i].size() - 1].visible)
		{
			grid[i][grid[i].size() - 1].visible = true;
			count++;
		}
		for (int j = grid[i].size() - 1 - 1; j >= 0; j--)
		{
			if (grid[i][j].num > pom)
			{
				if (!grid[i][j].visible)
				{
					count++;
					grid[i][j].visible = true;
				}
				pom = grid[i][j].num;
			}
		}
	}

	cout << count << endl;
	cout << endl;

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
#include <array>

using namespace std;


int main()
{
	ifstream o("AdventOfCode//2022//File_txt//08-12-2022.txt");

	string row;
	vector<vector<int>> grid;
	int r = 0;

	while (!o.eof())
	{
		while (getline(o, row))
		{
			grid.push_back(vector<int>());

			for (int i = 0; i < row.size(); i++)
				grid[r].push_back(row[i] - 48);
			r++;
		}
	}
	o.close();

	int tree_height = 0, result = 0, up = 0, down = 0, left = 0, right = 0, max = 0;
	for (int i = 1; i < grid.size(); i++)
	{
		for (int j = 1; j < grid[i].size(); j++)
		{
			up = 0, down = 0, left = 0, right = 0;
			tree_height = grid[i][j];
			for (int k = i - 1; k >= 0; k--)
			{
				up++;
				if (tree_height <= grid[k][j])
					break;
			}
			for (int k = i + 1; k < grid.size(); k++)
			{
				down++;
				if (tree_height <= grid[k][j])
					break;
			}
			for (int k = j - 1; k >= 0; k--)
			{
				left++;
				if (tree_height <= grid[i][k])
					break;
			}
			for (int k = j + 1; k < grid[i].size(); k++)
			{
				right++;
				if (tree_height <= grid[i][k])
					break;
			}
			int scenicScore = up * down * left * right;
			if (max < scenicScore)
				max = scenicScore;
		}
	}

	cout << max << endl;
	cout << endl;

	system("PAUSE");
	return 0;
}
*/