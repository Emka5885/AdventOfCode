/*
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int CalculateValue(std::string& step)
{
	int value = 0;
	for (char& c : step)
	{
		value = (value + c) * 17 % 256;
	}

	return value;
}

void Add(std::string& label, int focalLength, std::vector<std::vector<std::pair<std::string, int>>>& boxes)
{
	int nrBox = CalculateValue(label);
	for (auto& i : boxes[nrBox])
	{
		if (i.first == label)
		{
			i.second = focalLength;
			return;
		}
	}
	boxes[nrBox].emplace_back(label, focalLength);
}

void Erase(std::string& label, std::vector<std::vector<std::pair<std::string, int>>>& boxes)
{
	int nrBox = CalculateValue(label);
	auto& box = boxes[nrBox];
	bool erase = false;
	for (int i = 0; i < box.size(); i++)
	{
		if (box[i].first == label)
			erase = true;

		if (erase)
		{
			if (i + 1 < box.size())
				box[i] = box[i + 1];
			else
				box.pop_back();
		}
	}
}

int main()
{
	std::fstream file("AdventOfCode//2023//File_txt//15-12-2023.txt");

	std::string input = "";
	std::string line;
	while (std::getline(file, line))
	{
		input += line;
	}
	file.close();
	input += ',';

	std::vector<std::vector<std::pair<std::string, int>>> boxes(256);

	std::string label;
	int focalLength, index;
	while ((index = input.find(',')) != std::string::npos)
	{
		bool signEquals = true;
		auto equals = input.find('=');
		auto minus = input.find('-');

		if ((equals != std::string::npos && minus != std::string::npos && equals > minus) || equals == std::string::npos)
			signEquals = false;

		if (signEquals)
		{
			label = input.substr(0, equals);
			focalLength = std::atoi(input.substr(equals + 1, index - equals - 1).c_str());
			Add(label, focalLength, boxes);
		}
		else
		{
			label = input.substr(0, minus);
			Erase(label, boxes);
		}
		input.erase(0, index + 1);
	}

	long long result = 0;
	for (int i = 0; i < boxes.size(); i++)
	{
		int counter = 1;
		for (auto& b : boxes[i])
		{
			result += (i + 1) * counter * b.second;
			counter++;
		}
	}
	std::cout << result << '\n';

	std::cin.get();
	return 0;
}
*/