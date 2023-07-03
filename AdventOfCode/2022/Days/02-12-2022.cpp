/*
//#1
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	ifstream i("AdventOfCode//2022//File_txt//02-12-2022.txt");

	string round;
	char enemy = ' ', you = ' ';
	int result = 0, score = 0;
	bool test = false;

	while (!i.eof())
	{
		while (getline(i, round))
		{
			for (int j = 0; j < round.size(); j++)
			{
				if (j == 0)
					enemy = round[0];
				else if (j == 2)
				{
					you = round[2];
					test = true;
				}
			}

			if (test)
			{
				switch (you)
				{
				case 'X':
					score++;
					switch (enemy)
					{
					case 'A':
						score += 3;
						break;

					case 'B':
						break;

					case 'C':
						score += 6;
						break;
					}
					break;

				case 'Y':
					score += 2;
					switch (enemy)
					{
					case 'A':
						score += 6;
						break;

					case 'B':
						score += 3;
						break;

					case 'C':
						break;
					}
					break;

				case 'Z':
					score += 3;
					switch (enemy)
					{
					case 'A':
						break;

					case 'B':
						score += 6;
						break;

					case 'C':
						score += 3;
						break;
					}
					break;
				}
				result += score;
				score = 0;
			}
			test = false;
		}
	}

	cout << result << endl;

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

using namespace std;

int main()
{
	ifstream i("AdventOfCode//2022//File_txt//02-12-2022.txt");

	string round;
	char enemy = ' ', you = ' ';
	int result = 0, score = 0;
	bool test = false;

	while (!i.eof())
	{
		while (getline(i, round))
		{
			for (int j = 0; j < round.size(); j++)
			{
				if (j == 0)
					enemy = round[0];
				else if (j == 2)
				{
					you = round[2];
					test = true;
				}
			}

			if (test)
			{
				switch (enemy)
				{
				case 'A':
					switch (you)
					{
					case 'X':
						score += 3;
						break;

					case 'Y':
						score += 3;
						score ++;
						break;

					case 'Z':
						score += 6;
						score += 2;
						break;
					}
					break;

				case 'B':
					switch (you)
					{
					case 'X':
						score ++;
						break;

					case 'Y':
						score += 3;
						score+=2;
						break;

					case 'Z':
						score += 6;
						score +=3;
						break;
					}
					break;

				case 'C':
					switch (you)
					{
					case 'X':
						score+=2;
						break;

					case 'Y':
						score += 3;
						score+=3;
						break;

					case 'Z':
						score += 6;
						score++;
						break;
					}
					break;
				}
				result += score;
				score = 0;
			}
			test = false;
		}
	}

	cout << result << endl;

	i.close();

	system("PAUSE");
	return 0;
}
*/