/*
//#1
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Monkey
{
	vector<int> items;
	char operation;
	int num;
	int operations()
	{
		switch (operation)
		{
		case '+':
			return items[0] + num;
			break;
		case '*':
			return items[0] * num;
			break;
		}
	}
	int numD;
	bool divisible()
	{
		items[0] = operations() / 3;
		return (items[0] % numD == 0);
	}
	int ifTrue;
	int ifFalse;
	int inspectsItems = 0;
	bool check = false;
};

int main()
{
	ifstream o("AdventOfCode//2022//File_txt//11-12-2022.txt");

	string input;
	int howManyMonkeys = 8;
	vector<Monkey> m;

	for (int i = 0; i < howManyMonkeys; i++)
		m.push_back(Monkey());

	int num = 0;

	while (!o.eof())
	{
		while (getline(o, input))
		{
			int n = -1;
			for (int i = 0; i < input.size(); i++)
				if (isalpha(input[i]))
				{
					n = i;
					break;
				}

			if (n != -1)
			{
				string helper = "";
				if (input.substr(n, 6) == "Monkey")
					num = input[input.size() - 2] - 48;
				else if (input.substr(n, 8) == "Starting")
				{
					for (int i = n; i < input.size(); i++)
					{
						if (isdigit(input[i]))
							helper += input[i];
						else if (input[i] == ',')
						{
							m[num].items.push_back(stoi(helper));
							helper = "";
						}
					}
					if (helper != "")
						m[num].items.push_back(stoi(helper));
				}
				else if (input.substr(n, 9) == "Operation")
				{
					for (int i = n; i < input.size(); i++)
					{
						if (input[i] == '+' || input[i] == '*')
							m[num].operation = input[i];
						else if (isdigit(input[i]))
							helper += input[i];
					}
					if (helper == "")
					{
						m[num].num = m[num].items[0];
						m[num].check = true;
					}
					else
						m[num].num = stoi(helper);
				}
				else if (input.substr(n, 4) == "Test")
				{
					for (int i = n; i < input.size(); i++)
					{
						if (isdigit(input[i]))
							helper += input[i];
					}
					m[num].numD = stoi(helper);
				}
				else if (input.substr(n, 7) == "If true")
					m[num].ifTrue = input[input.size() - 1] - 48;
				else if (input.substr(n, 8) == "If false")
					m[num].ifFalse = input[input.size() - 1] - 48;
			}
		}
	}

	o.close();

	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < howManyMonkeys; j++)
		{
			while (!m[j].items.empty())
			{
				if (m[j].check)
					m[j].num = m[j].items[0];
				m[j].inspectsItems++;
				if (m[j].divisible())
					m[m[j].ifTrue].items.push_back(m[j].items[0]);
				else
					m[m[j].ifFalse].items.push_back(m[j].items[0]);
				m[j].items.erase(m[j].items.begin());
			}
		}
	}

	int num1 = 0, num2 = 0;
	vector<int> mI;
	for (int i = 0; i < howManyMonkeys; i++)
	{
		mI.push_back(m[i].inspectsItems);
	}

	int index = 0;
	for (int i = 0; i < mI.size(); i++)
		if (mI[i] > num1)
		{
			num1 = mI[i];
			index = i;
		}
	mI.erase(mI.begin() + index);
	num2 = *max_element(mI.begin(), mI.end());

	cout << num1 * num2 << endl;


	system("PAUSE");
	return 0;
}
*/



//#2