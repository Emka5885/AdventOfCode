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
		else if(line.size() > 0)
		{
			Node node;
			node.id = line.substr(0, 3);
			node.left = line.substr(7, 3);
			node.right = line.substr(12, 3);
			nodes.emplace_back(node);
		}		
	}
	file.close();

	int counter = 0;
	for (int i = 0; i < nodes.size(); i++)
	{
		if (nodes[i].id == "AAA")
		{
			int k = i;
			while (nodes[k].id != "ZZZ")
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
			break;
		}
	}
	std::cout << counter << '\n';

	return 0;
}
*/