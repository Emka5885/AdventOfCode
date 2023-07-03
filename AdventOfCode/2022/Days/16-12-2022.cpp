//NIE DZIA£A !!!

/*
//#1
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

int main()
{
	std::ifstream o("AdventOfCode//2022//File_txt//test4.txt");

	std::string input;

	std::vector<std::pair<std::pair<std::string, int>, std::vector<std::string>>> valves;

	while (!o.eof())
	{
		while (getline(o, input))
		{
			if (!input.empty())
			{
				int tester = 6;
				valves.push_back(std::pair<std::pair<std::string, int>, std::vector<std::string>>());
				std::string helper;
				helper += input[tester];
				helper += input[tester + 1];
				valves[valves.size() - 1].first.first = helper;
				tester += 17;
				std::string rate = "";
				while (isdigit(input[tester]))
				{
					rate += input[tester];
					tester++;
				}
				valves[valves.size() - 1].first.second = stoi(rate);

				tester += 8;
				if (input[tester] == 's')
					tester += 17;
				else
					tester += 16;

				while (tester < input.size())
				{
					helper.clear();
					helper += input[tester];
					helper += input[tester + 1];
					valves[valves.size() - 1].second.push_back(helper);
					tester+=4;
				}
			}
			
		}
	}

	//for (int i = 0; i < valves.size(); i++)
	//{
	//	std::cout << valves[i].first.first << ":" << valves[i].first.second << ":";
	//	for (int j = 0; j < valves[i].second.size(); j++)
	//	{
	//		std::cout << valves[i].second[j] << ":";
	//	}
	//	std::cout << "\n";
	//}

	int me = 0, total = 0;
	std::pair<int, std::pair<std::string, int>> compare;
	for (int i = 0; i < 30; i++)
	{
		
	}


	o.close();

	system("PAUSE");
	return 0;
}
*/