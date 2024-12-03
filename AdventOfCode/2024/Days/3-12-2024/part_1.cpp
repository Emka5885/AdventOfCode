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

	while (!file.eof())
	{
		std::string lineFromFile;
		std::getline(file, lineFromFile);

		auto begin = std::sregex_iterator(lineFromFile.begin(), lineFromFile.end(), w);
		auto end = std::sregex_iterator();

		for (auto it = begin; it != end; ++it)
		{
			std::smatch wynik = *it;
			result += std::atoi(wynik[1].str().c_str()) * std::atoi(wynik[2].str().c_str());
		}
	}

	file.close();

	std::cout << result << std::endl;

	return 0;
}
*/