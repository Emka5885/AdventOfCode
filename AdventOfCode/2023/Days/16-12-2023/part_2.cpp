/*
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

enum directions { north, east, south, west };

bool CheckIfNextStepIsPossible(std::vector<std::string>& contraption, const directions& dir, int i, int j, int& newI, int& newJ)
{
	switch (dir)
	{
	case north:
		if (i - 1 >= 0)
		{
			newI = i - 1; newJ = j;
			return true;
		}
		break;
	case east:
		if (j + 1 < contraption[i].size())
		{
			newI = i; newJ = j + 1;
			return true;
		}
		break;
	case south:
		if (i + 1 < contraption.size())
		{
			newI = i + 1; newJ = j;
			return true;
		}
		break;
	case west:
		if (j - 1 >= 0)
		{
			newI = i; newJ = j - 1;
			return true;
		}
		break;
	}
	return false;
}

void CheckNextStep(std::vector<std::string>& contraption, std::vector<std::vector<char>>& tiles, directions dir, int i, int j, int counter)
{
	bool flag = true;
	while (flag)
	{
		if (tiles[i][j] == '#')
			counter++;
		else
			counter = 0;

		if (counter >= 20)
			return;

		tiles[i][j] = '#';
		int nextI, nextJ;
		switch (contraption[i][j])
		{
		case '.':
			if (CheckIfNextStepIsPossible(contraption, dir, i, j, nextI, nextJ))
			{
				i = nextI; j = nextJ;
			}
			else
				flag = false;
			break;

		case '/':
			switch (dir)
			{
			case north:
				if (CheckIfNextStepIsPossible(contraption, east, i, j, nextI, nextJ))
				{
					i = nextI; j = nextJ; dir = east;
				}
				else
					flag = false;
				break;
			case east:
				if (CheckIfNextStepIsPossible(contraption, north, i, j, nextI, nextJ))
				{
					i = nextI; j = nextJ; dir = north;
				}
				else
					flag = false;
				break;
			case south:
				if (CheckIfNextStepIsPossible(contraption, west, i, j, nextI, nextJ))
				{
					i = nextI; j = nextJ; dir = west;
				}
				else
					flag = false;
				break;
			case west:
				if (CheckIfNextStepIsPossible(contraption, south, i, j, nextI, nextJ))
				{
					i = nextI; j = nextJ; dir = south;
				}
				else
					flag = false;
				break;
			}
			break;

		case '\\':
			switch (dir)
			{
			case north:
				if (CheckIfNextStepIsPossible(contraption, west, i, j, nextI, nextJ))
				{
					i = nextI; j = nextJ; dir = west;
				}
				else
					flag = false;
				break;
			case east:
				if (CheckIfNextStepIsPossible(contraption, south, i, j, nextI, nextJ))
				{
					i = nextI; j = nextJ; dir = south;
				}
				else
					flag = false;
				break;
			case south:
				if (CheckIfNextStepIsPossible(contraption, east, i, j, nextI, nextJ))
				{
					i = nextI; j = nextJ; dir = east;
				}
				else
					flag = false;
				break;
			case west:
				if (CheckIfNextStepIsPossible(contraption, north, i, j, nextI, nextJ))
				{
					i = nextI; j = nextJ; dir = north;
				}
				else
					flag = false;
				break;
			}
			break;

		case '|':
			if (dir == north || dir == south)
			{
				if (CheckIfNextStepIsPossible(contraption, dir, i, j, nextI, nextJ))
				{
					i = nextI; j = nextJ;
				}
				else
					flag = false;
			}
			else
			{
				if (CheckIfNextStepIsPossible(contraption, north, i, j, nextI, nextJ))
				{
					i = nextI; j = nextJ; dir = north;
				}
				else
					flag = false;
				if (CheckIfNextStepIsPossible(contraption, south, i, j, nextI, nextJ))
				{
					CheckNextStep(contraption, tiles, south, nextI, nextJ, counter);
				}
			}
			break;

		case '-':
			if (dir == east || dir == west)
			{
				if (CheckIfNextStepIsPossible(contraption, dir, i, j, nextI, nextJ))
				{
					i = nextI; j = nextJ;
				}
				else
					flag = false;
			}
			else
			{
				if (CheckIfNextStepIsPossible(contraption, east, i, j, nextI, nextJ))
				{
					i = nextI; j = nextJ; dir = east;
				}
				else
					flag = false;
				if (CheckIfNextStepIsPossible(contraption, west, i, j, nextI, nextJ))
				{
					CheckNextStep(contraption, tiles, west, nextI, nextJ, counter);
				}
			}
			break;
		}
	}
}

int GetNumberOfEnergizedTiles(std::vector<std::vector<char>>& tiles)
{
	int result = 0;
	for (int i = 0; i < tiles.size(); i++)
	{
		for (int j = 0; j < tiles[i].size(); j++)
		{
			if (tiles[i][j] == '#')
				result++;
		}
	}
	
	return result;
}

int main()
{
	std::fstream file("AdventOfCode//2023//File_txt//16-12-2023.txt");

	std::vector<std::string> input;
	std::vector<std::vector<char>> tiles;
	std::vector<std::vector<char>> helper;

	std::string line;
	while (std::getline(file, line))
	{
		input.emplace_back(line);
		tiles.emplace_back(std::vector<char>());
		for (auto& c : line)
		{
			tiles.back().emplace_back('.');
		}
	}
	file.close();
	helper = tiles;

	int max = 0;
	directions dir;
	for (int d = 0; d < 4; d++)
	{
		switch (d)
		{
		case 0:
			dir = east;
			for (int i = 0; i < tiles.size(); i++)
			{
				tiles = helper;
				CheckNextStep(input, tiles, dir, i, 0, 0);
				int number = GetNumberOfEnergizedTiles(tiles);
				if (number > max)
					max = number;
			}
			break;
		case 1:
			dir = west;
			for (int i = 0; i < tiles.size(); i++)
			{
				tiles = helper;
				CheckNextStep(input, tiles, dir, i, tiles[i].size() - 1, 0);
				int number = GetNumberOfEnergizedTiles(tiles);
				if (number > max)
					max = number;
			}
			break;
		case 2:
			dir = north;
			for (int i = 0; i < tiles[0].size(); i++)
			{

				tiles = helper;
				CheckNextStep(input, tiles, dir, tiles.size() - 1, i, 0);
				int number = GetNumberOfEnergizedTiles(tiles);
				if (number > max)
					max = number;
			}
			break;
		case 3:
			dir = south;
			for (int i = 0; i < tiles[0].size(); i++)
			{

				tiles = helper;
				CheckNextStep(input, tiles, dir, 0, i, 0);
				int number = GetNumberOfEnergizedTiles(tiles);
				if (number > max)
					max = number;
			}
			break;
		}
	}
	std::cout << max << '\n';

	std::cin.get();
	return 0;
}
*/