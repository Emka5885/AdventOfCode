/*
//#1
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	ifstream i("AdventOfCode//2022//File_txt//01-12-2022.txt");

	int maxAmount = 0, count = 0, amountI = 0, pom;
	string amountS;
	vector<int> amountV;

	while (!i.eof())
	{
		while (getline(i, amountS))
		{
			if (!amountS.empty())
			{
				for (int j = 0; j < amountS.size(); j++)
					amountV.push_back(amountS[j]);

				for (int j = 0; j < amountV.size(); j++)
				{
					if (j != 0)
					{
						pom = (amountV[amountV.size() - 1 - j] - 48);
						for (int k = 1; k <= j; k++)
							pom *= 10;
						amountI += pom;
					}
					else
						amountI += (amountV[amountV.size() - 1]-48);
				}
				count += amountI;
				amountI = 0;
				amountV.clear();
			}
			else
			{
				if (maxAmount < count)
					maxAmount = count;
				count = 0;
			}
		}
	}

	cout << maxAmount << endl;
	i.close();

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
#include <algorithm>
#include <numeric>

using namespace std;

int main()
{
	ifstream i("AdventOfCode//2022//File_txt//01-12-2022.txt");

	int Amount = 0, count = 0, amountI = 0, pom;
	string amountS;
	vector<int> amountV, amountTotal;

	while (!i.eof())
	{
		while (getline(i, amountS))
		{
			if (!amountS.empty())
			{
				for (int j = 0; j < amountS.size(); j++)
					amountV.push_back(amountS[j]);

				for (int j = 0; j < amountV.size(); j++)
				{
					if (j != 0)
					{
						pom = (amountV[amountV.size() - 1 - j] - 48);
						for (int k = 1; k <= j; k++)
							pom *= 10;
						amountI += pom;
					}
					else
						amountI += (amountV[amountV.size() - 1] - 48);
				}
				count += amountI;
				amountI = 0;
				amountV.clear();
			}
			else
			{
				amountTotal.push_back(count);
				count = 0;
			}
		}
	}

	sort(amountTotal.begin(), amountTotal.end());

	Amount = accumulate(amountTotal.end()-3, amountTotal.end(), 0);

	cout << Amount << endl;
	i.close();

	system("PAUSE");
	return 0;
}
*/