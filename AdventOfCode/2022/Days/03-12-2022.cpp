/*
//#1
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ifstream i("AdventOfCode//2022//File_txt//03-12-2022.txt");

	string rucksack;
	vector<char> compartment1, compartment2, letter;
	int sum = 0;
	bool test = false;

	while (!i.eof())
	{
		while (getline(i, rucksack))
		{
			for (int j = 0; j < rucksack.size(); j++)
			{
				if (j < rucksack.size() / 2)
				{
					compartment1.push_back(rucksack[j]);
				}
				else
				{
					compartment2.push_back(rucksack[j]);
				}
				test = true;
			}

			if (test)
			{
				sort(compartment1.begin(), compartment1.end());
				sort(compartment2.begin(), compartment2.end());
				set_intersection(compartment1.begin(), compartment1.end(), compartment2.begin(), compartment2.end(), back_inserter(letter));

				if (letter[0] >= 97 && letter[0] <= 122)
				{
					sum += letter[0] - 96;
				}
				else
					sum += letter[0] - 38;
				test = false;
				compartment1.clear();
				compartment2.clear();
				letter.clear();
			}
		}
	}

	cout << sum << endl;

	i.close();

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

using namespace std;

int main()
{
	ifstream i("AdventOfCode//2022//File_txt//03-12-2022.txt");

	string rucksack;
	vector<char> rucksack1, rucksack2, rucksack3, r, letter;
	int sum = 0, count = 1;
	bool test = false;

	while (!i.eof())
	{
		while (getline(i, rucksack))
		{
			for (int j = 0; j < rucksack.size(); j++)
			{
				if (count == 1)
					rucksack1.push_back(rucksack[j]);
				else if(count == 2)
					rucksack2.push_back(rucksack[j]);
				else
					rucksack3.push_back(rucksack[j]);
			}
			count++;

			if (count == 4)
			{
				test = true;
				count = 1;
				sort(rucksack1.begin(), rucksack1.end());
				sort(rucksack2.begin(), rucksack2.end());
				sort(rucksack3.begin(), rucksack3.end());
				set_intersection(rucksack1.begin(), rucksack1.end(), rucksack2.begin(), rucksack2.end(), back_inserter(r));
				set_intersection(rucksack3.begin(), rucksack3.end(), r.begin(), r.end(), back_inserter(letter));
			}

			if (test)
			{
				if (letter[0] >= 97 && letter[0] <= 122)
				{
					sum += letter[0] - 96;
				}
				else
					sum += letter[0] - 38;

				rucksack1.clear();
				rucksack2.clear();
				rucksack3.clear();
				r.clear();
				letter.clear();
				test = false;
			}
		}
	}

	cout << sum << endl;

	i.close();

	system("PAUSE");
	return 0;
}
*/