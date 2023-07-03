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
	ifstream i("AdventOfCode//2022//File_txt//04-12-2022.txt");

	string pair;
	vector<int> first1, first2, second1, second2;
	int f1 = 0, f2 = 0, s1 = 0, s2 = 0;
	int sum = 0;
	bool test = false, test2 = false;

	while (!i.eof())
	{
		while (getline(i, pair))
		{
			for (int j = 0; j < pair.size(); j++)
			{
				if (pair[j] == ',')
				{
					test = true;
					test2 = false;
				}
				else if (pair[j] == '-')
					test2 = true;
				else if (!test)
				{
					if (!test2)
						first1.push_back(pair[j] - 48);
					else
						first2.push_back(pair[j] - 48);
				}
				else
				{
					if (!test2)
						second1.push_back(pair[j] - 48);
					else
						second2.push_back(pair[j] - 48);
				}
			}
			test = false;
			test2 = false;

			for (int n = 0; n < first1.size(); n++)
				if (n != 0)
				{
					int pom = (first1[first1.size() - 1 - n]);
					for (int k = 1; k <= n; k++)
						pom *= 10;
					f1 += pom;
				}
				else
					f1 += (first1[first1.size() - 1]);

			for (int n = 0; n < first2.size(); n++)
				if (n != 0)
				{
					int pom = (first2[first2.size() - 1 - n]);
					for (int k = 1; k <= n; k++)
						pom *= 10;
					f2 += pom;
				}
				else
					f2 += (first2[first2.size() - 1]);

			for (int n = 0; n < second1.size(); n++)
				if (n != 0)
				{
					int pom = (second1[second1.size() - 1 - n]);
					for (int k = 1; k <= n; k++)
						pom *= 10;
					s1 += pom;
				}
				else
					s1 += (second1[second1.size() - 1]);

			for (int n = 0; n < second2.size(); n++)
				if (n != 0)
				{
					int pom = (second2[second2.size() - 1 - n]);
					for (int k = 1; k <= n; k++)
						pom *= 10;
					s2 += pom;
				}
				else
					s2 += (second2[second2.size() - 1]);

			if ((f1 >= s1 && f2 <= s2) || (s1 >= f1 && s2 <= f2))
				sum++;

			first1.clear();
			first2.clear();
			second1.clear();
			second2.clear();
			f1 = 0;
			f2 = 0;
			s1 = 0;
			s2 = 0;
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
	ifstream i("AdventOfCode//2022//File_txt//04-12-2022.txt");

	string pair;
	vector<int> first1, first2, second1, second2;
	int f1 = 0, f2 = 0, s1 = 0, s2 = 0;
	int sum = 0;
	bool test = false, test2 = false;

	while (!i.eof())
	{
		while (getline(i, pair))
		{
			for (int j = 0; j < pair.size(); j++)
			{
				if (pair[j] == ',')
				{
					test = true;
					test2 = false;
				}
				else if (pair[j] == '-')
					test2 = true;
				else if (!test)
				{
					if (!test2)
						first1.push_back(pair[j] - 48);
					else
						first2.push_back(pair[j] - 48);
				}
				else
				{
					if (!test2)
						second1.push_back(pair[j] - 48);
					else
						second2.push_back(pair[j] - 48);
				}
			}
			test = false;
			test2 = false;

			for (int n = 0; n < first1.size(); n++)
				if (n != 0)
				{
					int pom = (first1[first1.size() - 1 - n]);
					for (int k = 1; k <= n; k++)
						pom *= 10;
					f1 += pom;
				}
				else
					f1 += (first1[first1.size() - 1]);

			for (int n = 0; n < first2.size(); n++)
				if (n != 0)
				{
					int pom = (first2[first2.size() - 1 - n]);
					for (int k = 1; k <= n; k++)
						pom *= 10;
					f2 += pom;
				}
				else
					f2 += (first2[first2.size() - 1]);

			for (int n = 0; n < second1.size(); n++)
				if (n != 0)
				{
					int pom = (second1[second1.size() - 1 - n]);
					for (int k = 1; k <= n; k++)
						pom *= 10;
					s1 += pom;
				}
				else
					s1 += (second1[second1.size() - 1]);

			for (int n = 0; n < second2.size(); n++)
				if (n != 0)
				{
					int pom = (second2[second2.size() - 1 - n]);
					for (int k = 1; k <= n; k++)
						pom *= 10;
					s2 += pom;
				}
				else
					s2 += (second2[second2.size() - 1]);

			if ((f1 >= s1 && f1 <= s2) || (f2 >= s1 && f2 <= s2) || (s1 >= f1 && s1 <= f2) || (s2 >= f1 && s2 <= f2))
				sum++;

			first1.clear();
			first2.clear();
			second1.clear();
			second2.clear();
			f1 = 0;
			f2 = 0;
			s1 = 0;
			s2 = 0;
		}
	}

	cout << sum << endl;

	i.close();

	system("PAUSE");
	return 0;
}
*/