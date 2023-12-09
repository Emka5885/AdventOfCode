/*
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void ChangeStringToIntVector(std::string& str, std::vector<long long>& numbers)
{
	std::string num = "";
	bool space = true;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '-')
		{
			num += str[i];
			space = false;
		}
		else if (std::isdigit(str[i]))
		{
			num += str[i];
			space = false;
		}
		else if (!space)
		{
			numbers.emplace_back(std::stoll(num.c_str()));
			num = "";
			space = true;
		}
	}
	numbers.emplace_back(std::stoll(num.c_str()));
}

int main()
{
	std::fstream file("AdventOfCode//2023//File_txt//09-12-2023.txt");

	int result = 0;
	while (!file.eof())
	{
		std::string line;
		std::getline(file, line);

		std::vector<std::vector<long long>> sequences;
		sequences.emplace_back(std::vector<long long>());
		ChangeStringToIntVector(line, sequences.back());

		bool endOfSequence = false;
		while (!endOfSequence)
		{
			endOfSequence = true;
			sequences.emplace_back(std::vector<long long>());
			for (int i = 1; i < sequences[sequences.size() - 2].size(); i++)
			{
				sequences.back().emplace_back(sequences[sequences.size() - 2][i] - sequences[sequences.size() - 2][i - 1]);
				if (sequences.back()[i - 1] != 0)
				{
					endOfSequence = false;
				}
			}
		}
		
		for (int i = sequences.size() - 2; i >= 0; i--)
		{
			sequences[i].emplace_back(sequences[i + 1].back() + sequences[i].back());
		}
		
		result += sequences[0].back();
	}
	file.close();

	std::cout << result << '\n';

	system("PAUSE");
	return 0;
}
*/