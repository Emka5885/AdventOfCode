/*
//#1
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream o("AdventOfCode//2022//File_txt//06-12-2022.txt");

	string input;
	const int CHARACTERS = 4;
	bool test = false, test2 = true;

	while (!o.eof())
	{
		o >> input;

		string check;
		int unique = 0;
		int marker = 0;

		while (true)
		{
			check = input.substr(marker, CHARACTERS);

			for (int j = 0; j < check.size(); j++)
			{
				if (!test2)
					break;
				for (int k = j + 1; k < check.size(); k++)
				{
					if (check[j] == check[k])
					{
						unique = j + 1;
						test = true;
						test2 = false;
						break;
					}
				}
			}
			if (!test)
				break;
			else
				marker += unique;

			test = false;
			test2 = true;
		}

		marker += CHARACTERS;
		cout << marker << endl;
	}
	o.close();

	system("PAUSE");
	return 0;
}
*/



/*
//#2
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream o("AdventOfCode//2022//File_txt//06-12-2022.txt");

	string input;
	const int CHARACTERS = 14;
	bool test = false, test2 = true;

	while (!o.eof())
	{
		o >> input;

		string check;
		int unique = 0;
		int marker = 0;

		while(true)
		{
			check = input.substr(marker, CHARACTERS);

			for (int j = 0; j < check.size(); j++)
			{
				if (!test2)
					break;
				for (int k = j + 1; k < check.size(); k++)
				{
					if (check[j] == check[k])
					{
						unique = j + 1;
						test = true;
						test2 = false;
						break;
					}
				}
			}
			if (!test)
				break;
			else
				marker += unique;

			test = false;
			test2 = true;
		}

		marker += CHARACTERS;
		cout << marker << endl;
	}
	o.close();

	system("PAUSE");
	return 0;
}
*/