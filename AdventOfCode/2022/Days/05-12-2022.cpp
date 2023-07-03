/*
//#1
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int main()
{
	ifstream i("AdventOfCode//2022//File_txt//05-12-2022.txt");

	string input;
	bool test = true, test2 = true, m = true, f = false, t = false, twoDigits = false;

	stack<char> stacks[9], reverseStacks[9];
	int move = 0, from = 0, to = 0, c = 0;

	while (!i.eof())
	{
		while (getline(i, input))
		{
			if (test)
			{
				if (isdigit(input[1]))
					test = false;
				else
				{
					for (int pos = 1, j = 0; pos < input.length(); ++j, pos += 4)
					{
						if (isalpha(input[pos]))
						{
							stacks[j].push(input[pos]);
						}
					}
				}
			}
			else
			{
				if (test2)
				{
					for (int j = 0; j < 9; j++)
					{
						int len = stacks[j].size();
						for (int k = 0; k < len; k++)
						{
							reverseStacks[j].push(stacks[j].top());
							stacks[j].pop();
						}
					}
					test2 = false;
				}

				if (input[0] == 'm')
				{
					for (int j = 0; j < input.length(); j++)
					{
						if (input[j] == 'm' && !f)
						{
							t = false;
							m = true;
						}
						else if (input[j] == 'f')
						{
							m = false;
							f = true;
						}
						else if (input[j] == 't')
						{
							f = false;
							t = true;
						}

						if (isdigit(input[j]))
						{
							if (isdigit(input[j + 1]))
								twoDigits = true;
							if (m)
							{
								if (twoDigits)
									if (c == 0)
									{
										move += (input[j] - 48) * 10;
										c = 1;
									}
									else
										move += input[j] - 48;
								else
									move += input[j] - 48;

							}
							else if (f)
							{
								from += input[j] - 48 - 1;
							}
							else if (t)
							{
								to += input[j] - 48 - 1;
							}
						}
					}

					for (int j = 1; j <= move; j++)
					{
						reverseStacks[to].push(reverseStacks[from].top());
						reverseStacks[from].pop();
					}

					move = 0; from = 0; to = 0, c = 0, twoDigits = false;
				}
			}

		}
	}

	for (int j = 0; j < 9; j++)
	{
		cout << reverseStacks[j].top();
		int len = reverseStacks[j].size();
		for (int k = 0; k < len; k++)
		{
			reverseStacks[j].pop();
		}
	}

	i.close();
	cout << endl;

	system("PAUSE");
	return 0;
}
*/



/*
//#2
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int main()
{
	ifstream i("AdventOfCode//2022//File_txt//05-12-2022.txt");

	string input;
	bool test = true, test2 = true, m = true, f = false, t = false, twoDigits = false;

	stack<char> stacks[9], reverseStacks[9];
	int move = 0, from = 0, to = 0, c = 0;

	while (!i.eof())
	{
		while (getline(i, input))
		{
			if (test)
			{
				if (isdigit(input[1]))
					test = false;
				else
				{
					for (int pos = 1, j = 0; pos < input.length(); ++j, pos += 4)
					{
						if (isalpha(input[pos]))
						{
							stacks[j].push(input[pos]);
						}
					}
				}
			}
			else
			{
				if (test2)
				{
					for (int j = 0; j < 9; j++)
					{
						int len = stacks[j].size();
						for (int k = 0; k < len; k++)
						{
							reverseStacks[j].push(stacks[j].top());
							stacks[j].pop();
						}
					}
					test2 = false;
				}

				if (input[0] == 'm')
				{
					for (int j = 0; j < input.length(); j++)
					{
						if (input[j] == 'm' && !f)
						{
							t = false;
							m = true;
						}
						else if (input[j] == 'f')
						{
							m = false;
							f = true;
						}
						else if (input[j] == 't')
						{
							f = false;
							t = true;
						}

						if (isdigit(input[j]))
						{
							if (isdigit(input[j + 1]))
								twoDigits = true;
							if (m)
							{
								if (twoDigits)
									if (c == 0)
									{
										move += (input[j] - 48) * 10;
										c = 1;
									}
									else
										move += input[j] - 48;
								else
									move += input[j] - 48;

							}
							else if (f)
							{
								from += input[j] - 48 - 1;
							}
							else if (t)
							{
								to += input[j] - 48 - 1;
							}
						}
					}

					stack<char> help;

					for (int j = 1; j <= move; j++)
					{
						help.push(reverseStacks[from].top());
						reverseStacks[from].pop();
					}

					while (!help.empty())
					{
						reverseStacks[to].push(help.top());
						help.pop();
					}

					move = 0; from = 0; to = 0, c = 0, twoDigits = false;
				}
			}

		}
	}

	for (int j = 0; j < 9; j++)
	{
		cout << reverseStacks[j].top();
		int len = reverseStacks[j].size();
		for (int k = 0; k < len; k++)
		{
			reverseStacks[j].pop();
		}
	}

	i.close();
	cout << endl;

	system("PAUSE");
	return 0;
}
*/