/*
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

long long changeHexToDec(std::string hex)
{
	long long dec = 0;
	for (int i = hex.size() - 1; i >= 0; i--)
	{
		if (std::isdigit(hex[i]))
			dec += std::pow(16, hex.size() - 1 - i) * (hex[i] - '0');
		else
			dec += std::pow(16, hex.size() - 1 - i) * (hex[i] - 'a' + 10);
	}
	return dec;
}

int main()
{
	std::fstream file("AdventOfCode//2023//File_txt//18-12-2023.txt");

	std::vector<long long> distance;
	std::vector<int> direction;

	std::string line;
	while (std::getline(file, line))
	{
		distance.emplace_back(changeHexToDec(line.substr(line.find('(') + 2, 5)));
		direction.emplace_back(std::atoi(line.substr(line.find(')') - 1, 1).c_str()));
	}
	file.close();

	long long perimeter = 0, shoelace = 0;
	long long x = 0, y = 0;
	std::vector<std::pair<long long, long long>> pts = { {0, 0} };

	for (size_t i = 0; i < distance.size(); i++)
	{
		long long dx, dy;
		switch (direction[i])
		{
		case 0:
			dx = 1; dy = 0;
			break;
		case 1:
			dx = 0; dy = 1;
			break;
		case 2:
			dx = -1; dy = 0;
			break;
		case 3:
			dx = 0; dy = -1;
			break;
		}

		x += dx * distance[i];
		y += dy * distance[i];
		pts.emplace_back(x, y);
		perimeter += distance[i];
	}

	for (size_t i = 0; i < pts.size() - 1; i++)
	{
		shoelace += (pts[i].first * pts[i + 1].second - pts[i + 1].first * pts[i].second);
	}
	shoelace /= 2;

	std::cout << shoelace + perimeter / 2 + 1 << '\n';

	std::cin.get();
	return 0;
}
*/