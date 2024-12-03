/*
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <regex>

int main()
{
	std::fstream file("AdventOfCode//2024//File_txt//03-12-2024.txt");

	long long int result = 0;

	std::regex w(R"(mul\((\d+),(\d+)\))");

	std::string lineFromFile = "";
	while (!file.eof())
	{
		std::string line;
		std::getline(file, line);
		lineFromFile += line;
	}

	auto begin = std::sregex_iterator(lineFromFile.begin(), lineFromFile.end(), w);
	auto end = std::sregex_iterator();

	for (auto it = begin; it != end; ++it)
	{
		std::smatch wynik = *it;
		result += std::atoi(wynik[1].str().c_str()) * std::atoi(wynik[2].str().c_str());
	}

	std::regex w1(R"(don't\(\).*?do\(\))");
	begin = std::sregex_iterator(lineFromFile.begin(), lineFromFile.end(), w1);
	end = std::sregex_iterator();

	for (auto it = begin; it != end; ++it)
	{
		std::smatch wynik = *it;
		std::string line = wynik[0].str();

		auto begin1 = std::sregex_iterator(line.begin(), line.end(), w);
		auto end1 = std::sregex_iterator();

		for (auto it = begin1; it != end1; ++it)
		{
			std::smatch wynik1 = *it;
			result -= std::atoi(wynik1[1].str().c_str()) * std::atoi(wynik1[2].str().c_str());
		}
	}

	std::regex w2(R"(don't\(\)(.*))");
	begin = std::sregex_iterator(lineFromFile.begin(), lineFromFile.end(), w2);
	end = std::sregex_iterator();

	std::string line;
	for (auto it = begin; it != end; ++it)
	{
		std::smatch wynik = *it;
		line = wynik[0].str();
	}

	size_t count = 0;
	size_t pos = line.find("don't()");
	size_t idx = 0;

	while (pos != std::string::npos)
	{
		idx = pos;
		pos = line.find("don't()", pos + 1);
		++count;
	}

	if (count > 1 && idx != std::string::npos)
	{
		line = line.substr(idx);
	}

	std::regex w3(R"(don't\(\)(.*?)(do\(\)))");
	begin = std::sregex_iterator(line.begin(), line.end(), w3);
	end = std::sregex_iterator();

	bool bCheck = false;
	for (auto it = begin; it != end; ++it)
	{
		bCheck = true;
		break;
	}

	if (!bCheck)
	{
		auto begin1 = std::sregex_iterator(line.begin(), line.end(), w);
		auto end1 = std::sregex_iterator();

		for (auto it = begin1; it != end1; ++it)
		{
			std::smatch wynik1 = *it;
			result -= std::atoi(wynik1[1].str().c_str()) * std::atoi(wynik1[2].str().c_str());
		}
	}

	file.close();

	std::cout << result << std::endl;

	return 0;
}
*/