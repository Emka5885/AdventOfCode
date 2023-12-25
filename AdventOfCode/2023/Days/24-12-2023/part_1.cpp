/*
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

struct Position
{
	long long x;
	long long y;
};

struct Velocity
{
	int x;
	int y;
};

bool CheckIntersection(std::pair<Position, Velocity>& h1, std::pair<Position, Velocity>& h2, long long min, long long max)
{
	if (h1.second.y * h2.second.x == h2.second.y * h1.second.x)
		return false;

	long double t1 = static_cast<long double>(h2.second.y * (h1.first.x - h2.first.x) - h2.second.x * (h1.first.y - h2.first.y)) / (h1.second.y * h2.second.x - h1.second.x * h2.second.y);
	long double t2 = static_cast<long double>(h1.second.y * (h2.first.x - h1.first.x) - h1.second.x * (h2.first.y - h1.first.y)) / (h2.second.y * h1.second.x - h2.second.x * h1.second.y);

	return t1 > 0 && min < h1.first.x + t1 * h1.second.x && h1.first.x + t1 * h1.second.x < max && t2 > 0 && min < h1.first.y + t1 * h1.second.y && h1.first.y + t1 * h1.second.y < max;
}

int main()
{
	std::fstream file("AdventOfCode//2023//File_txt//24-12-2023.txt");

	std::vector<std::pair<Position, Velocity>> input;

	std::string line;
	while (std::getline(file, line))
	{
		input.emplace_back(std::pair<Position, Velocity>());
		input.back().first.x = std::stoll(line.substr(0, line.find(',')).c_str());
		line.erase(0, line.find(',') + 2);
		input.back().first.y = std::stoll(line.substr(0, line.find(',')).c_str());
		line.erase(0, line.find('@') + 2);
		input.back().second.x = std::stoll(line.substr(0, line.find(',')).c_str());
		line.erase(0, line.find(',') + 2);
		input.back().second.y = std::stoll(line.substr(0, line.find(',')).c_str());
	}
	file.close();

	long long min = 200000000000000;
	long long max = 400000000000000;

	int count = 0;
	for (int i = 0; i < input.size() - 1; i++)
	{
		for (int j = i + 1; j < input.size(); j++)
		{
			if (CheckIntersection(input[i], input[j], min, max))
				count++;
		}
	}
	std::cout << count << '\n';

	std::cin.get();
	return 0;
}
*/