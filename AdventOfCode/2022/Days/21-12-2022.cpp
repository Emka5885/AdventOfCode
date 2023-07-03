/*
//#1
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

struct Monkey
{
	std::string name;
	std::string number;
};

std::vector<Monkey> allMonkeys;

uint64_t yellNumber(Monkey monkey)
{
	if (isdigit(monkey.number[0]))
	{
		return std::stoi(monkey.number);
	}
	else
	{
		int monkey1 = 0, monkey2 = 0;

		for (int i = 0; i < allMonkeys.size(); i++)
		{
			if (monkey.number.substr(0, 4) == allMonkeys[i].name)
			{
				monkey1 = i;
			}
			if (monkey.number.substr(7, 4) == allMonkeys[i].name)
			{
				monkey2 = i;
			}
		}

		switch (monkey.number[5])
		{
		case '+':
			return yellNumber(allMonkeys[monkey1]) + yellNumber(allMonkeys[monkey2]);
			break;

		case '-':
			return yellNumber(allMonkeys[monkey1]) - yellNumber(allMonkeys[monkey2]);
			break;

		case '*':
			return yellNumber(allMonkeys[monkey1]) * yellNumber(allMonkeys[monkey2]);
			break;

		case '/':
			return yellNumber(allMonkeys[monkey1]) / yellNumber(allMonkeys[monkey2]);
			break;
		}
	}
}

int main()
{
	std::ifstream o("AdventOfCode//2022//File_txt//21-12-2022.txt");

	std::string input;

	while (!o.eof())
	{
		while (getline(o, input))
		{
			allMonkeys.push_back(Monkey());
			allMonkeys[allMonkeys.size() - 1].name = input.substr(0, 4);
			allMonkeys[allMonkeys.size() - 1].number = input.substr(6);
		}
	}

	uint64_t result = 0;
	for (int i = 0; i < allMonkeys.size(); i++)
	{
		if (allMonkeys[i].name == "root")
		{
			result = yellNumber(allMonkeys[i]);
		}
	}

	std::cout << result << "\n";

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

struct Monkey
{
	std::string name;
	std::string number;
	bool calced = false;
	uint64_t value = 0;
};

std::vector<Monkey> allMonkeys;


int main()
{
	std::ifstream o("AdventOfCode//2022//File_txt//21-12-2022.txt");

	std::string input;

	while (!o.eof())
	{
		while (getline(o, input))
		{
			allMonkeys.push_back(Monkey());
			allMonkeys[allMonkeys.size() - 1].name = input.substr(0, 4);
			allMonkeys[allMonkeys.size() - 1].number = input.substr(6);
			if (isdigit(allMonkeys.back().number[0]))
			{
				allMonkeys.back().calced = true;
				allMonkeys.back().value = std::stoi(allMonkeys.back().number);
			}
		}
	}

	std::string root1, root2;
	uint64_t result = 0;
	for (int i = 0; i < allMonkeys.size(); i++)
	{
		if (allMonkeys[i].name == "root")
		{
			root1 = allMonkeys[i].number.substr(0, 4);
			root2 = allMonkeys[i].number.substr(7, 4);
			allMonkeys[i].calced = true;
			allMonkeys[i].number[5] = '=';
			break;
		}
		if (allMonkeys[i].name == "humn")
		{
			allMonkeys[i].number = "?";
		}
	}

	Monkey* human = nullptr;
	
	for (int i = 0; i < allMonkeys.size(); i++)
	{
		if (allMonkeys[i].name == "humn")
		{
			human = &allMonkeys[i];
			human->calced = false;
		}
	}

	while (true)
	{
		for (auto& monkey : allMonkeys)
		{
			std::cout << monkey.name << ":" << monkey.value << '\n';
			if (!monkey.calced && monkey.name != "humn")
			{
				if (!isdigit(monkey.number[0]))
				{
					uint64_t helperMonkey1, helperMonkey2;
					bool nextMonkey = false;
					for (int i = 0; i < allMonkeys.size(); i++)
					{
						if (allMonkeys[i].name == monkey.number.substr(0, 4))
						{
							if (!allMonkeys[i].calced)
							{
								nextMonkey = true;
								continue;
							}
							else
							{
								helperMonkey1 = allMonkeys[i].value;
							}
						}
						if (allMonkeys[i].name == monkey.number.substr(7, 4))
						{
							if (!allMonkeys[i].calced)
							{
								nextMonkey = true;
								continue;
							}
							else
							{
								helperMonkey2 = allMonkeys[i].value;
							}
						}
					}

					if (nextMonkey)
					{
						continue;
					}

					switch (monkey.number[5])
					{
					case '+':
						monkey.value = helperMonkey1 + helperMonkey2;
						break;
					case '-':
						monkey.value = helperMonkey1 - helperMonkey2;
						break;
					case '*':
						monkey.value = helperMonkey1 * helperMonkey2;
						break;
					case '/':
						monkey.value = helperMonkey1 / helperMonkey2;
						break;
					case '=':
						monkey.value = (helperMonkey1 == helperMonkey2);
						break;
					}
				}
				monkey.calced = true;
			}
			if (monkey.calced && !isdigit(monkey.number[0]))
			{
				Monkey* helperMonkey1 = nullptr;
				Monkey* helperMonkey2 = nullptr;
				for (int i = 0; i < allMonkeys.size(); i++)
				{
					if (allMonkeys[i].name == monkey.number.substr(0, 4))
					{
						helperMonkey1 = &allMonkeys[i];
					}
					if (allMonkeys[i].name == monkey.number.substr(7, 4))
					{
						helperMonkey2 = &allMonkeys[i];
					}
				}
				if ((helperMonkey1->calced && helperMonkey2->calced) || (!helperMonkey1->calced && !helperMonkey2->calced))
				{
					continue;
				}
				else if (!helperMonkey1->calced && helperMonkey2->calced)
				{
					switch (monkey.number[5])
					{
					case '+':
						helperMonkey1->value = monkey.value - helperMonkey2->value;
						break;
					case '-':
						helperMonkey1->value = monkey.value + helperMonkey2->value;
						break;
					case '*':
						helperMonkey1->value = monkey.value / helperMonkey2->value;
						break;
					case '/':
						helperMonkey1->value = monkey.value * helperMonkey2->value;
						break;
					case '=':
						helperMonkey1->value = helperMonkey2->value;
						break;
					}
					helperMonkey1->calced = true;
				}
				else
				{
					switch (monkey.number[5])
					{
					case '+':
						helperMonkey2->value = monkey.value - helperMonkey1->value;
						break;
					case '-':
						helperMonkey2->value = helperMonkey1->value - monkey.value;
						break;
					case '*':
						helperMonkey2->value = monkey.value / helperMonkey1->value;
						break;
					case '/':
						helperMonkey2->value = helperMonkey1->value / monkey.value;
						break;
					}

					helperMonkey2->calced = true;
				}
			}
			if (human->calced)
			{
				std::cout << human->value << '\n';
				system("PAUSE");
				return 0;
			}
		}
	}

	system("PAUSE");
	return 0;
}
*/