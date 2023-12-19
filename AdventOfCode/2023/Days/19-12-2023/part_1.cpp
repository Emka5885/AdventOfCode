/*
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>

void CheckConditions(std::string& workflow, std::vector<std::pair<char, int>>& parts, std::string& newKey)
{
	bool flag = true;
	while (flag)
	{
		int i;
		if (workflow[1] == '>' || workflow[1] == '<')
		{
			switch (workflow[0])
			{
			case 'x':
				i = 0;
				break;
			case 'm':
				i = 1;
				break;
			case 'a':
				i = 2;
				break;
			case 's':
				i = 3;
				break;
			default:
				newKey = workflow;
				return;
			}
		}
		else
		{
			newKey = workflow;
			return;
		}
		
		if (workflow[1] == '>')
		{
			if (parts[i].second > std::atoi(workflow.substr(workflow.find('>') + 1, workflow.find(':') - 2).c_str()))
			{
				workflow.erase(0, workflow.find(':') + 1);
				newKey = workflow.substr(0, workflow.find(','));
				flag = false;
			}
		}
		else
		{
			if (parts[i].second < std::atoi(workflow.substr(workflow.find('<') + 1, workflow.find(':') - 2).c_str()))
			{
				workflow.erase(0, workflow.find(':') + 1);
				newKey = workflow.substr(0, workflow.find(','));
				flag = false;
			}
		}
		workflow.erase(0, workflow.find(',') + 1);
	}
}

bool CheckIfAccepted(std::map<std::string, std::string>& workflows, std::vector<std::pair<char, int>>& parts)
{
	std::string key = "in";
	while (key != "R" && key != "A")
	{
		for (auto k : workflows)
		{
			if (k.first == key)
			{
				CheckConditions(k.second, parts, key);
			}
		}
	}

	if (key == "A")
		return true;
	else
		return false;
}

int main()
{
	std::fstream file("AdventOfCode//2023//File_txt//19-12-2023.txt");

	std::vector<std::vector<std::pair<char, int>>> parts;
	std::map<std::string, std::string> workflows;

	std::string line;
	bool flag = false;
	while (std::getline(file, line))
	{
		if (line == "")
		{
			flag = true;
		}
		else if (flag)
		{
			parts.emplace_back(std::vector<std::pair<char, int>>());
			parts.back().emplace_back('x', std::atoi(line.substr(line.find('x') + 2, line.find(',')).c_str()));
			line.erase(0, line.find(',') + 1);
			parts.back().emplace_back('m', std::atoi(line.substr(line.find('m') + 2, line.find(',')).c_str()));
			line.erase(0, line.find(',') + 1);
			parts.back().emplace_back('a', std::atoi(line.substr(line.find('a') + 2, line.find(',')).c_str()));
			line.erase(0, line.find(',') + 1);
			parts.back().emplace_back('s', std::atoi(line.substr(line.find('s') + 2, line.find(',')).c_str()));
		}
		else
		{
			workflows[line.substr(0, line.find('{'))] = line.substr(line.find('{') + 1, (line.find('}') - line.find('{') - 1));
		}
	}
	file.close();

	long long result = 0;
	for (int i = 0; i < parts.size(); i++)
	{
		if (CheckIfAccepted(workflows, parts[i]))
		{
			for (int j = 0; j < parts[i].size(); j++)
			{
				result += parts[i][j].second;
			}
		}
	}
	std::cout << result << '\n';

	std::cin.get();
	return 0;
}
*/