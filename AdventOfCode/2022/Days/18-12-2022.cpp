/*
//#1
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>

struct Cube
{
	int x = 0, y = 0, z = 0;
	std::vector<std::pair<Cube, bool>> neighbors = {
		{ { 0,0,0 }, false},
		{{ 0,0,0 }, false},
		{{ 0,0,0 }, false},
		{{ 0,0,0 }, false},
		{{ 0,0,0 }, false},
		{{ 0,0,0 }, false}
	};
	void updateNeighbors()
	{
		neighbors = {
		{ { x - 1, y, z }, false},
		{{ x + 1, y, z }, false},
		{{ x, y - 1, z }, false},
		{{ x, y + 1, z }, false},
		{{ x, y, z - 1 }, false},
		{{ x, y, z + 1 }, false}
		};
	}
};

bool is_digit_or_minus(char chr)
{
	return '0' <= chr && chr <= '9' || chr == '-';
}

int parse_number(const char* line, int& outNumber)
{
	char number_string[32];
	int number_string_length = 0;
	while (is_digit_or_minus(*line))
	{
		number_string[number_string_length] = *line;
		number_string_length++;
		line++;
	}
	number_string[number_string_length] = '\0';

	outNumber = std::stoi(number_string);

	return number_string_length;
}

bool read_input(FILE* file, Cube& outCube)
{
	char line[128];

	if (!fgets(line, 128, file))
	{
		return false;
	}
	
	const char* ptr = line;

	ptr += parse_number(ptr, outCube.x);

	ptr++;
	ptr += parse_number(ptr, outCube.y);

	ptr++;
	ptr += parse_number(ptr, outCube.z);

	

	return true;
}


int main()
{
	FILE* file;
	fopen_s(&file, "AdventOfCode//2022//File_txt//18-12-2022.txt", "r");

	std::vector<Cube> allCubes;
	Cube helperCube;

	//read input
	while (read_input(file, helperCube))
	{
		allCubes.push_back(helperCube);
	}

	//for all cubes update neighbors
	for (int i = 0; i < allCubes.size(); i++)
	{
		allCubes[i].updateNeighbors();
	}

	int result = 0;

	//check what is the total sum of all the sides of the cubes
	for (int i = 0; i < allCubes.size(); i++)
	{
		result += 6;
	}

	//for all cubes
	for (int i = 0; i < allCubes.size(); i++)
	{
		//for all i's neighbors (all 6 sides of the cube)
		for (int j = 0; j < allCubes[i].neighbors.size(); j++)
		{
			//if this side is not yet in contact with anything
			if (!allCubes[i].neighbors[j].second)
			{
				//again we have to analyze all the cubes
				for (int k = 0; k < allCubes.size(); k++)
				{
					//we have to check two different cubes
					if (i != k)
					{
						//if i's neighbor coordinates and k's coordinates are the same
						if (allCubes[i].neighbors[j].first.x == allCubes[k].x && allCubes[i].neighbors[j].first.y == allCubes[k].y && allCubes[i].neighbors[j].first.z == allCubes[k].z)
						{
							result-=2;

							//set that this side is in contact with something
							allCubes[i].neighbors[j].second = true;

							//we need to set the information for the right k neighbor
							for (int l = 0; l < allCubes[k].neighbors.size(); l++)
							{
								if (allCubes[i].x == allCubes[k].neighbors[l].first.x && allCubes[i].y == allCubes[k].neighbors[l].first.y && allCubes[i].z == allCubes[k].neighbors[l].first.z)
								{
									allCubes[k].neighbors[l].second = true;
								}
							}
							k = allCubes.size();
						}
					}
				}
			}
		}
	}

	std::cout << result << '\n';

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
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

const int GRID_SIZE = 22;

bool sortthreenumbers(int& a, int& b, int& c, int& a1, int& b1, int& c1)
{
	return (a < a1)?true:(b<b1)?true:(c<c1);
}

struct Cube
{
	int x = 0, y = 0, z = 0;
	std::vector<std::pair<Cube, bool>> neighbors =
	{
		{ { 0,0,0 }, false},
		{{ 0,0,0 }, false},
		{{ 0,0,0 }, false},
		{{ 0,0,0 }, false},
		{{ 0,0,0 }, false},
		{{ 0,0,0 }, false}
	};
	void updateNeighbors()
	{
		neighbors = {
		{ { x - 1, y, z }, false},
		{{ x + 1, y, z }, false},
		{{ x, y - 1, z }, false},
		{{ x, y + 1, z }, false},
		{{ x, y, z - 1 }, false},
		{{ x, y, z + 1 }, false}
		};
	}
};

std::vector<Cube> allCubes;
std::pair<std::vector<Cube>, std::vector<bool>> grid;
int minX = -1, minY = -1, minZ = -1, maxX = -1, maxY = -1, maxZ = -1;

bool is_digit_or_minus(char chr)
{
	return '0' <= chr && chr <= '9' || chr == '-';
}

int parse_number(const char* line, int& outNumber)
{
	char number_string[32];
	int number_string_length = 0;
	while (is_digit_or_minus(*line))
	{
		number_string[number_string_length] = *line;
		number_string_length++;
		line++;
	}
	number_string[number_string_length] = '\0';

	outNumber = std::stoi(number_string);

	return number_string_length;
}

bool read_input(FILE* file, Cube& outCube)
{
	char line[128];

	if (!fgets(line, 128, file))
	{
		return false;
	}

	const char* ptr = line;

	ptr += parse_number(ptr, outCube.x);

	ptr++;
	ptr += parse_number(ptr, outCube.y);

	ptr++;
	ptr += parse_number(ptr, outCube.z);



	return true;
}

bool isAir(int i)
{
	if (!grid.second[i] && grid.first[i].x > minX && grid.first[i].x < maxX && grid.first[i].y > minY && grid.first[i].y < maxY && grid.first[i].z > minZ && grid.first[i].z < maxZ)
	{
		int counter = 0;
		for (int j = 0; j < grid.first.size(); j++)
		{
			if (grid.first[j].x <= maxX && grid.first[j].x > grid.first[i].x && grid.first[j].y == grid.first[i].y && grid.first[j].z == grid.first[i].z)
			{
				if (grid.second[j])
				{
					counter++;
				}
			}
		}
		if (counter == 0)
		{
			return true;
		}
		counter = 0;
		for (int j = 0; j < grid.first.size(); j++)
		{
			if (grid.first[j].x >= minX && grid.first[j].x < grid.first[i].x && grid.first[j].y == grid.first[i].y && grid.first[j].z == grid.first[i].z)
			{
				if (grid.second[j])
				{
					counter++;
				}
			}
		}
		if (counter == 0)
		{
			return true;
		}
		counter = 0;
		for (int j = 0; j < grid.first.size(); j++)
		{
			if (grid.first[j].y <= maxY && grid.first[j].y > grid.first[i].y && grid.first[j].x == grid.first[i].x && grid.first[j].z == grid.first[i].z)
			{
				if (grid.second[j])
				{
					counter++;
				}
			}
		}
		if (counter == 0)
		{
			return true;
		}
		counter = 0;
		for (int j = 0; j < grid.first.size(); j++)
		{
			if (grid.first[j].y >= minY && grid.first[j].y < grid.first[i].y && grid.first[j].x == grid.first[i].x && grid.first[j].z == grid.first[i].z)
			{
				if (grid.second[j])
				{
					counter++;
				}
			}
		}
		if (counter == 0)
		{
			return true;
		}
		counter = 0;
		for (int j = 0; j < grid.first.size(); j++)
		{
			if (grid.first[j].z <= maxZ && grid.first[j].z > grid.first[i].z && grid.first[j].y == grid.first[i].y && grid.first[j].x == grid.first[i].x)
			{
				if (grid.second[j])
				{
					counter++;
				}
			}
		}
		if (counter == 0)
		{
			return true;
		}
		counter = 0;
		for (int j = 0; j < grid.first.size(); j++)
		{
			if (grid.first[j].z >= minZ && grid.first[j].z < grid.first[i].z && grid.first[j].y == grid.first[i].y && grid.first[j].x == grid.first[i].x)
			{
				if (grid.second[j])
				{
					counter++;
				}
			}
		}
		if (counter == 0)
		{
			return true;
		}
		
		return false;
	}
	return true;
}

bool isAir2(int i)
{
	if (!isAir(i))
	{
		for (int j = 0; j < grid.first[i].neighbors.size(); j++)
		{
			for (int k = 0; k < grid.first.size(); k++)
			{
				if (grid.first[i].neighbors[j].first.x == grid.first[k].x && grid.first[i].neighbors[j].first.y == grid.first[k].y && grid.first[i].neighbors[j].first.z == grid.first[k].z)
				{
					if (!grid.second[k])
					{
						if (isAir(k))
						{
							return true;
						}
					}
				}
			}
		}
		return false;
	}
	return true;
}

int main()
{
	FILE* file;
	fopen_s(&file, "AdventOfCode//2022//File_txt//18-12-2022.txt", "r");

	Cube helperCube;

	while (read_input(file, helperCube))
	{
		bool isContained = false;
		for (int i = 0; i < allCubes.size(); i++)
		{
			if (helperCube.x == allCubes[i].x && helperCube.y == allCubes[i].y && helperCube.z == allCubes[i].z)
				isContained = true;
		}
		if(!isContained)
			allCubes.push_back(helperCube);
	}

	for (int i = 0; i < allCubes.size(); i++)
	{
		allCubes[i].updateNeighbors();
	}


	for (int x = 0; x < GRID_SIZE; x++)
	{
		for (int y = 0; y < GRID_SIZE; y++)
		{
			for (int z = 0; z < GRID_SIZE; z++)
			{
				grid.first.push_back({ x,y,z });
				grid.second.push_back(false);
				grid.first[grid.first.size() - 1].updateNeighbors();
			}
		}
	}

	bool firstCoordinates = true;

	for (int i = 0; i < allCubes.size(); i++)
	{
		for (int j = 0; j < grid.first.size(); j++)
		{
			if (!grid.second[j] && allCubes[i].x == grid.first[j].x && allCubes[i].y == grid.first[j].y && allCubes[i].z == grid.first[j].z)
			{
				
				grid.second[j] = true;

				if (firstCoordinates)
				{
					minX = allCubes[i].x;
					maxX = allCubes[i].x;
					minY = allCubes[i].y;
					maxY = allCubes[i].y;
					minZ = allCubes[i].z;
					maxZ = allCubes[i].z;

					firstCoordinates = false;
				}
				else
				{
					if (minX > allCubes[i].x)
					{
						minX = allCubes[i].x;
					}
					else if (maxX < allCubes[i].x)
					{
						maxX = allCubes[i].x;
					}
					if (minY > allCubes[i].y)
					{
						minY = allCubes[i].y;
					}
					else if (maxY < allCubes[i].y)
					{
						maxY = allCubes[i].y;
					}
					if (minZ > allCubes[i].z)
					{
						minZ = allCubes[i].z;
					}
					else if (maxZ < allCubes[i].z)
					{
						maxZ = allCubes[i].z;
					}
				}
			}
		}
	}

	std::vector<Cube> cubesToCheck;


	for (int i = 0; i < grid.first.size(); i++)
	{
		if (!isAir2(i))
		{	
			bool isContained = false;
			for (int k = 0; k < cubesToCheck.size(); k++)
			{
				if (grid.first[i].x == cubesToCheck[k].x && grid.first[i].y == cubesToCheck[k].y && grid.first[i].z == cubesToCheck[k].z)
				{
					isContained = true;
				}
			}
			if (!isContained)
				cubesToCheck.push_back(grid.first[i]);
		}
	}


	for (int i = 0; i < cubesToCheck.size(); i++)
	{
		cubesToCheck[i].updateNeighbors();
	}

	std::vector<Cube> cubesInside;

	for (int i = 0; i < grid.first.size(); i++)
	{
		if (grid.second[i])
		{
			int counter = 0;
			for (int j = 0; j < grid.first.size(); j++)
			{
				if (grid.first[j].x == grid.first[i].x + 1)
				{
					if (grid.first[j].x <= maxX && grid.first[j].y == grid.first[i].y && grid.first[j].z == grid.first[i].z)
					{
						if (!grid.second[j])
						{
							for (int k = 0; k < cubesToCheck.size(); k++)
							{
								if (grid.first[j].x == cubesToCheck[k].x && grid.first[j].y == cubesToCheck[k].y && grid.first[j].z == cubesToCheck[k].z)
								{
									counter++;
								}
							}
						}
					}
				}
			}
			for (int j = 0; j < grid.first.size(); j++)
			{
				if (grid.first[j].x == grid.first[i].x - 1)
				{
					if (grid.first[j].x >= minX && grid.first[j].y == grid.first[i].y && grid.first[j].z == grid.first[i].z)
					{
						if (!grid.second[j])
						{
							for (int k = 0; k < cubesToCheck.size(); k++)
							{
								if (grid.first[j].x == cubesToCheck[k].x && grid.first[j].y == cubesToCheck[k].y && grid.first[j].z == cubesToCheck[k].z)
								{
									counter++;
								}
							}
						}
					}
				}
			}
			for (int j = 0; j < grid.first.size(); j++)
			{
				if (grid.first[j].y == grid.first[i].y + 1)
				{
					if (grid.first[j].y <= maxY && grid.first[j].x == grid.first[i].x && grid.first[j].z == grid.first[i].z)
					{
						if (!grid.second[j])
						{
							for (int k = 0; k < cubesToCheck.size(); k++)
							{
								if (grid.first[j].x == cubesToCheck[k].x && grid.first[j].y == cubesToCheck[k].y && grid.first[j].z == cubesToCheck[k].z)
								{
									counter++;
								}
							}
						}
					}
				}
			}
			for (int j = 0; j < grid.first.size(); j++)
			{
				if (grid.first[j].y == grid.first[i].y - 1)
				{
					if (grid.first[j].y >= minY && grid.first[j].x == grid.first[i].x && grid.first[j].z == grid.first[i].z)
					{
						if (!grid.second[j])
						{
							for (int k = 0; k < cubesToCheck.size(); k++)
							{
								if (grid.first[j].x == cubesToCheck[k].x && grid.first[j].y == cubesToCheck[k].y && grid.first[j].z == cubesToCheck[k].z)
								{
									counter++;
								}
							}
						}
					}
				}
			}
			for (int j = 0; j < grid.first.size(); j++)
			{
				if (grid.first[j].z == grid.first[i].z + 1)
				{
					if (grid.first[j].z <= maxZ && grid.first[j].y == grid.first[i].y && grid.first[j].x == grid.first[i].x)
					{
						if (!grid.second[j])
						{
							for (int k = 0; k < cubesToCheck.size(); k++)
							{
								if (grid.first[j].x == cubesToCheck[k].x && grid.first[j].y == cubesToCheck[k].y && grid.first[j].z == cubesToCheck[k].z)
								{
									counter++;
								}
							}
						}
					}
				}
			}
			for (int j = 0; j < grid.first.size(); j++)
			{
				if(grid.first[j].z == grid.first[i].z - 1)
				if (grid.first[j].z >= minZ && grid.first[j].y == grid.first[i].y && grid.first[j].x == grid.first[i].x)
				{
					if (!grid.second[j])
					{
						for (int k = 0; k < cubesToCheck.size(); k++)
						{
							if (grid.first[j].x == cubesToCheck[k].x && grid.first[j].y == cubesToCheck[k].y && grid.first[j].z == cubesToCheck[k].z)
							{
								counter++;
							}
						}
					}
				}
			}

			if (counter == 6)
			{
				cubesInside.push_back(grid.first[i]);
			}
		}
	}

	for (int i = 0; i < cubesInside.size(); i++)
	{
		cubesInside[i].updateNeighbors();
	}

	for (int i = 0; i < cubesInside.size(); i++)
	{
		for (int j = 0; j < allCubes.size(); j++)
		{
			if (cubesInside[i].x == allCubes[j].x && cubesInside[i].y == allCubes[j].y && cubesInside[i].z == allCubes[j].z)
			{
				allCubes.erase(allCubes.begin() + j);
				cubesToCheck.push_back(cubesInside[i]);
			}
		}
	}

	for (int i = 0; i < cubesToCheck.size(); i++)
	{
		cubesToCheck[i].updateNeighbors();
	}

	int result = 6 * allCubes.size();

	for (int i = 0; i < allCubes.size(); i++)
	{
		for (int j = 0; j < allCubes[i].neighbors.size(); j++)
		{
			if (!allCubes[i].neighbors[j].second)
			{
				for (int k = 0; k < allCubes.size(); k++)
				{
					if (i != k)
					{
						if (allCubes[i].neighbors[j].first.x == allCubes[k].x && allCubes[i].neighbors[j].first.y == allCubes[k].y && allCubes[i].neighbors[j].first.z == allCubes[k].z)
						{
							result -= 2;
							allCubes[i].neighbors[j].second = true;
							for (int l = 0; l < allCubes[k].neighbors.size(); l++)
							{
								if (allCubes[i].x == allCubes[k].neighbors[l].first.x && allCubes[i].y == allCubes[k].neighbors[l].first.y && allCubes[i].z == allCubes[k].neighbors[l].first.z)
								{
									allCubes[k].neighbors[l].second = true;
								}
							}
							k = allCubes.size();
						}
					}
				}
			}
		}
	}

	int counter = 6 * cubesToCheck.size();


	for (int i = 0; i < cubesToCheck.size(); i++)
	{
		for (int j = 0; j < cubesToCheck[i].neighbors.size(); j++)
		{
			if (!cubesToCheck[i].neighbors[j].second)
			{
				for (int k = 0; k < cubesToCheck.size(); k++)
				{
					if (i != k)
					{
						if (cubesToCheck[i].neighbors[j].first.x == cubesToCheck[k].x && cubesToCheck[i].neighbors[j].first.y == cubesToCheck[k].y && cubesToCheck[i].neighbors[j].first.z == cubesToCheck[k].z)
						{
							counter -= 2;
							cubesToCheck[i].neighbors[j].second = true;
							for (int l = 0; l < cubesToCheck[k].neighbors.size(); l++)
							{
								if (cubesToCheck[i].x == cubesToCheck[k].neighbors[l].first.x && cubesToCheck[i].y == cubesToCheck[k].neighbors[l].first.y && cubesToCheck[i].z == cubesToCheck[k].neighbors[l].first.z)
								{
									cubesToCheck[k].neighbors[l].second = true;
									continue;
								}
							}
							k = cubesToCheck.size();
						}
					}
				}
			}
		}
	}


	std::cout << result - counter << '\n';

	system("PAUSE");
	return 0;
}
*/