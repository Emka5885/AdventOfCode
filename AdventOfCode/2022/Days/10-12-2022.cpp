/*
//#1
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	ifstream i("AdventOfCode//2022//File_txt//10-12-2022.txt");

	int sum = 0, cycle = 1, x = 1, num, count = 0;
	string signal;
	vector<char> str;

	while (!i.eof())
	{
		while (getline(i, signal))
		{
			if (signal != "noop")
			{
				cycle++;
				if (cycle == 20 + count)
				{
					sum += (20 + count) * x;
					count += 40;
				}

				for (int i = 0; i < signal.size(); i++)
				{
					if (signal[i] == '-' || isdigit(signal[i]))
						str.push_back(signal[i]);
				}
				string number(str.begin(), str.end());
				num = stoi(number);

				cycle++;
				x += num;
			}
			else
				cycle++;

			if (cycle == 20 + count)
			{
				sum += (20 + count) * x;
				count += 40;
			}

			str.clear();
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
#include <vector>
#include <string>

using namespace std;

int main()
{
	ifstream i("AdventOfCode//2022//File_txt//10-12-2022.txt");

	int cycle = 0, x = 1, num, count = 0, counter = 0, n = 0;
	string signal;
	vector<char> str, line, CRT;

	for (int i = 0; i < 40; i++)
		line.push_back('.');

	line[0] = '#';
	line[1] = '#';
	line[2] = '#';


	while (!i.eof())
	{
		while (getline(i, signal))
		{
			if (signal != "noop")
			{
				cycle++;
				CRT.push_back(line[counter]);
				counter++;
				if (cycle == 40 + count)
				{
					count += 40;
					counter = 0;
				}

				for (int i = 0; i < signal.size(); i++)
				{
					if (signal[i] == '-' || isdigit(signal[i]))
						str.push_back(signal[i]);
				}
				string number(str.begin(), str.end());
				num = stoi(number);

				cycle++;
				CRT.push_back(line[counter]);
				counter++;

				x += num;
				line.clear();
				for (int i = 0; i < 40; i++)
					line.push_back('.');

				if(0+x-1 >= 0 && 0+x-1 < 40)
					line[0+x-1] = '#';
				if (1+x-1 >= 0 && 1+x-1 < 40)
					line[1+x-1] = '#';
				if (2+x-1 >= 0 && 2+x-1 < 40)
					line[2+x-1] = '#';
			}
			else
			{
				cycle++;
				CRT.push_back(line[counter]);
				counter++;
			}

			if (cycle == 40 + count)
			{
				count += 40;
				counter = 0;
			}

			str.clear();
		}
	}

	i.close();

	for (int i = 0; i < CRT.size(); i++)
	{
		if (i == 40 + n)
		{
			cout << endl;
			n+=40;
		}
		cout << CRT[i];
	}
	cout << endl;

	system("PAUSE");
	return 0;
}
*/