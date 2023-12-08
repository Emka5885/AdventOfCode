/*
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>

struct Node
{
	std::string id;
	std::string left;
	std::string right;
};

long long NWD(long long a, long long b)
{
	while (b != 0)
	{
		long long r = a % b;
		a = b;
		b = r;
	}
	return a;
}

long long NWW(long long a, long long b)
{
	return a * b / NWD(a, b);
}

long long CountSteps(std::vector<Node>& nodes, std::queue<char> sequence, int k)
{
	long long counter = 0;
	while (nodes[k].id[2] != 'Z')
	{
		if (sequence.front() == 'R')
		{
			for (int j = 0; j < nodes.size(); j++)
			{
				if (nodes[k].right == nodes[j].id)
				{
					k = j;
					break;
				}
			}
		}
		else
		{
			for (int j = 0; j < nodes.size(); j++)
			{
				if (nodes[k].left == nodes[j].id)
				{
					k = j;
					break;
				}
			}
		}
		counter++;
		sequence.push(sequence.front());
		sequence.pop();
	}

	return counter;
}

int main()
{
	std::fstream file("AdventOfCode//2023//File_txt//08-12-2023.txt");

	std::vector<Node> nodes;
	std::queue<char> sequence;

	bool start = true;

	while (!file.eof())
	{
		std::string line;
		std::getline(file, line);

		if (start)
		{
			for (int i = 0; i < line.size(); i++)
			{
				sequence.push(line[i]);
			}
			start = false;
		}
		else if (line.size() > 0)
		{
			Node node;
			node.id = line.substr(0, 3);
			node.left = line.substr(7, 3);
			node.right = line.substr(12, 3);
			nodes.emplace_back(node);
		}
	}
	file.close();

	std::vector<int> steps;
	for (int i = 0; i < nodes.size(); i++)
	{
		if (nodes[i].id[2] == 'A')
		{
			steps.emplace_back(CountSteps(nodes, sequence, i));
		}
	}

	long long result = steps[0];
	for (int i = 1; i < steps.size(); i++)
	{
		result = NWW(result, steps[i]);
	}
	std::cout << result << '\n';

	return 0;
}
*/