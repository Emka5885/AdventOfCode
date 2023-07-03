/*
//#1
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <numeric>


int main()
{
	std::ifstream o("AdventOfCode//2022//File_txt//13-12-2022.txt");

	std::string input;

	std::vector<std::vector<char>> pair;
	pair.push_back(std::vector<char>());
	pair.push_back(std::vector<char>());

	int index = 1;
	std::vector<int> indexes;
	bool test = false;

	while (!o.eof())
	{
		while (getline(o, input))
		{
			if (pair[0].empty())
			{
				for (char n : input)
					pair[0].push_back(n);
			}
			else
			{
				for (char n : input)
					pair[1].push_back(n);
				test = true;
			}


			if (test)
			{
				int i = 0, j = 0;
				while (i < pair[0].size() && j < pair[1].size())
				{
					if (isdigit(pair[0][i]) && isdigit(pair[1][j]))
					{
						std::string x1 = "", x2 = "";
						while (i < pair[0].size() && isdigit(pair[0][i]))
						{
							x1 += pair[0][i];
							i++;
						}
						while (j < pair[1].size() && isdigit(pair[1][j]))
						{
							x2 += pair[1][j];
							j++;
						}
						if (stoi(x1) < stoi(x2))
						{
							indexes.push_back(index);
							break;
						}
						if (stoi(x1) > stoi(x2))
						{
							break;
						}
					}
					else if (pair[0][i] == pair[1][j])
					{
						i++; j++;
					}
					else
					{
						if (pair[0][i] == ']' && isdigit(pair[1][j]))
						{
							indexes.push_back(index);
							break;
						}
						if (pair[1][i] == ']' && isdigit(pair[0][j]))
						{
							break;
						}
						else if (pair[1][j] == ']')
						{
							break;
						}
						else if (pair[0][i] == ']')
						{
							indexes.push_back(index);
							break;
						}
						if (pair[0][i] == ']' && pair[1][j] == '[')
						{
							indexes.push_back(index);
							break;
						}
						else if (pair[0][i] == '[' && pair[1][j] != '[')
						{
							std::vector<char> helper;
							int s = pair[1].size();
							for (int l = j; l < s; l++)
							{
								helper.push_back(pair[1][j]);
								pair[1].erase(pair[1].begin() + j);
							}
							pair[1].push_back('[');
							bool p = true;
							for (int l = 0; l < helper.size(); l++)
							{
								if (!isdigit(helper[l]) && p)
								{
									pair[1].push_back(']');
									p = false;
								}
								pair[1].push_back(helper[l]);
							}
						}
						else if (pair[1][j] == '[' && pair[0][i] != '[')
						{
							std::vector<char> helper;
							int s = pair[0].size();
							for (int l = i; l < s; l++)
							{
								helper.push_back(pair[0][i]);
								pair[0].erase(pair[0].begin() + i);
							}
							pair[0].push_back('[');
							bool p = true;
							for (int l = 0; l < helper.size(); l++)
							{
								if (!isdigit(helper[l]) && p)
								{
									pair[0].push_back(']');
									p = false;
								}
								pair[0].push_back(helper[l]);
							}
						}
					}
				}
				pair[0].clear(); pair[1].clear();
				index++;
				test = false;
			}
		}
	}

	o.close();

	int ans = 0;
	std::cout << std::accumulate(indexes.begin(), indexes.end(), ans) << std::endl;

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
#include <numeric>
#include <algorithm>

std::vector<std::vector<char>> pair;

bool compare(std::string& packet1, std::string& packet2)
{
	if (packet1.empty() || packet2.empty())
		return false;
	pair[0].clear(); pair[1].clear();
	for (int n : packet1)
		pair[0].push_back(n);
	for (int n : packet2)
		pair[1].push_back(n);

	bool test = false;

	int i = 0, j = 0;
	while (i < pair[0].size() && j < pair[1].size())
	{
		if (isdigit(pair[0][i]) && isdigit(pair[1][j]))
		{
			std::string x1 = "", x2 = "";
			while (i < pair[0].size() && isdigit(pair[0][i]))
			{
				x1 += pair[0][i];
				i++;
			}
			while (j < pair[1].size() && isdigit(pair[1][j]))
			{
				x2 += pair[1][j];
				j++;
			}
			if (stoi(x1) < stoi(x2))
			{
				test = true;
				break;
			}
			else if (stoi(x1) > stoi(x2))
			{
				test = false;
				break;
			}
		}
		else if (pair[0][i] == pair[1][j])
		{
			i++; j++;
		}
		else
		{
			if (pair[0][i] == ']' && isdigit(pair[1][j]))
			{
				test = true;
				break;
			}
			else if (pair[1][i] == ']' && isdigit(pair[0][j]))
			{
				test = false;
				break;
			}
			else if (pair[1][j] == ']')
			{
				test = false;
				break;
			}
			else if (pair[0][i] == ']')
			{
				test = true;
				break;
			}
			if (pair[0][i] == ']' && pair[1][j] == '[')
			{
				test = true;
				break;
			}
			else if (pair[0][i] == '[' && pair[1][j] != '[')
			{
				std::vector<char> helper;
				int s = pair[1].size();
				for (int l = j; l < s; l++)
				{
					helper.push_back(pair[1][j]);
					pair[1].erase(pair[1].begin() + j);
				}
				pair[1].push_back('[');
				bool p = true;
				for (int l = 0; l < helper.size(); l++)
				{
					if (!isdigit(helper[l]) && p)
					{
						pair[1].push_back(']');
						p = false;
					}
					pair[1].push_back(helper[l]);
				}
			}
			else if (pair[1][j] == '[' && pair[0][i] != '[')
			{
				std::vector<char> helper;
				int s = pair[0].size();
				for (int l = i; l < s; l++)
				{
					helper.push_back(pair[0][i]);
					pair[0].erase(pair[0].begin() + i);
				}
				pair[0].push_back('[');
				bool p = true;
				for (int l = 0; l < helper.size(); l++)
				{
					if (!isdigit(helper[l]) && p)
					{
						pair[0].push_back(']');
						p = false;
					}
					pair[0].push_back(helper[l]);
				}
			}
		}
	}

	return test;
}

int main()
{
	std::ifstream o("AdventOfCode//2022//File_txt//13-12-2022.txt");

	std::string input;

	pair.push_back(std::vector<char>());
	pair.push_back(std::vector<char>());

	std::vector<std::string> packets;

	bool test = false;

	while (!o.eof())
	{
		while (getline(o, input))
		{
			if (!input.empty())
				packets.push_back(input);
		}
	}

	o.close();

	packets.push_back("[[2]]");
	packets.push_back("[[6]]");

	std::sort(std::begin(packets), std::end(packets), compare);

	int num1 = 0, num2 = 0;

	for (int i = 0; i < packets.size(); i++)
	{
		if (packets[i] == "[[2]]")
			num1 = i + 1;
		else if (packets[i] == "[[6]]")
			num2 = i + 1;
	}

	std::cout << num1*num2 << std::endl;

	system("PAUSE");
	return 0;
}
*/