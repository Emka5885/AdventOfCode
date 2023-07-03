//NIE DZIA£A!

//#1
//#include <iostream>
//#include <fstream>
//#include <vector>
//#include <string>
//
//std::vector<std::pair<std::pair<int,int>,char>> informationOnCurrentBlizzards;
//
//void blizzardMovement(std::vector<std::string>& v)
//{
//	std::vector<std::string> helperValley;
//
//	for (int i = 1; i < helperValley.size()-1; i++)
//	{
//		helperValley.clear();
//		for (int k = 0; k < v.size(); k++)
//		{
//			helperValley.push_back(v[k]);
//		}
//		bool isSideBySideRight = false;
//		bool isNewLeft = false;
//		for (int j = 1; j < helperValley[i].size()-1; j++)
//		{
//			if (isdigit(helperValley[i][j]))
//			{
//				for (int k = 0; k < helperValley[i][j]; k++)
//				{
//					for (int l = 0; l < informationOnCurrentBlizzards.size(); l++)
//					{
//						if (informationOnCurrentBlizzards[l].first.first == i && informationOnCurrentBlizzards[l].first.second == j)
//						{
//							switch (informationOnCurrentBlizzards[l].second)
//							{
//							case '>':
//								if (helperValley[i][j + 1] == '>')
//								{
//									informationOnCurrentBlizzards.push_back({ { i, j + 1}, '>' });
//									switch (helperValley[i][j + 1])
//									{
//									case '<':
//										informationOnCurrentBlizzards.push_back({ { i, j + 1}, '<' });
//										break;
//									case '^':
//										informationOnCurrentBlizzards.push_back({ { i, j + 1}, '^' });
//										break;
//									case 'v':
//										informationOnCurrentBlizzards.push_back({ { i, j + 1}, 'v' });
//										break;
//									}
//									helperValley[i][j + 1] = '2';
//								}
//								else if (isdigit(helperValley[i][j + 1]))
//								{
//									informationOnCurrentBlizzards.push_back({ { i, j + 1}, '>' });
//									helperValley[i][j + 1]++;
//								}
//								else if (helperValley[i][j + 1] == '#')
//								{
//									helperValley[i][1] = informationOnCurrentBlizzards[l].second;
//								}
//								else
//								{
//									helperValley[i][j + 1] = informationOnCurrentBlizzards[l].second;
//								}
//								break;
//							case '<':
//								if (helperValley[i][j - 1] == '<')
//								{
//									informationOnCurrentBlizzards.push_back({ { i, j - 1}, '<' });
//									switch (helperValley[i][j - 1])
//									{
//									case '>':
//										informationOnCurrentBlizzards.push_back({ { i, j - 1}, '>' });
//										break;
//									case '^':
//										informationOnCurrentBlizzards.push_back({ { i, j - 1}, '^' });
//										break;
//									case 'v':
//										informationOnCurrentBlizzards.push_back({ { i, j - 1}, 'v' });
//										break;
//									}
//									helperValley[i][j] = '.';
//									helperValley[i][j - 1] = '2';
//								}
//								else if (isdigit(helperValley[i][j - 1]))
//								{
//									informationOnCurrentBlizzards.push_back({ { i, j - 1}, '<' });
//									helperValley[i][j - 1]++;
//								}
//								else if (helperValley[i][j - 1] == '#')
//								{
//									helperValley[i][helperValley.size() - 2] = informationOnCurrentBlizzards[l].second;
//								}
//								else
//								{
//									helperValley[i][j - 1] = informationOnCurrentBlizzards[l].second;
//								}
//								break;
//							case '^':
//								if (helperValley[i - 1][j] == '^')
//								{
//									informationOnCurrentBlizzards.push_back({ { i - 1, j}, '^' });
//									switch (helperValley[i - 1][j])
//									{
//									case '<':
//										informationOnCurrentBlizzards.push_back({ { i - 1, j}, '<' });
//										break;
//									case '>':
//										informationOnCurrentBlizzards.push_back({ { i - 1, j}, '>' });
//										break;
//									case 'v':
//										informationOnCurrentBlizzards.push_back({ { i - 1, j}, 'v' });
//										break;
//									}
//									helperValley[i][j] = '.';
//									helperValley[i - 1][j] = '2';
//								}
//								else if (isdigit(helperValley[i - 1][j]))
//								{
//									informationOnCurrentBlizzards.push_back({ { i - 1, j}, '^' });
//									helperValley[i - 1][j]++;
//								}
//								else if (helperValley[i - 1][j] == '#')
//								{
//									helperValley[helperValley.size() - 2][j] = informationOnCurrentBlizzards[l].second;
//								}
//								else
//								{
//									helperValley[i - 1][j] = informationOnCurrentBlizzards[l].second;
//								}
//								break;
//							case 'v':
//								if (helperValley[i + 1][j] == 'v')
//								{
//									informationOnCurrentBlizzards.push_back({ { i + 1, j}, 'v' });
//									switch (helperValley[i + 1][j])
//									{
//									case '<':
//										informationOnCurrentBlizzards.push_back({ { i + 1, j}, '<' });
//										break;
//									case '>':
//										informationOnCurrentBlizzards.push_back({ { i + 1, j}, '>' });
//										break;
//									case '^':
//										informationOnCurrentBlizzards.push_back({ { i + 1, j}, '^' });
//										break;
//									}
//									helperValley[i][j] = '.';
//									helperValley[i + 1][j] = '2';
//								}
//								else if (isdigit(helperValley[i + 1][j]))
//								{
//									informationOnCurrentBlizzards.push_back({ { i + 1, j}, 'v' });
//									helperValley[i + 1][j]++;
//								}
//								else if (helperValley[i + 1][j] == '#')
//								{
//									helperValley[1][j] = informationOnCurrentBlizzards[l].second;
//								}
//								else
//								{
//									helperValley[i + 1][j] = informationOnCurrentBlizzards[l].second;
//								}
//								break;
//							}
//							informationOnCurrentBlizzards.erase(informationOnCurrentBlizzards.begin() + l);
//						}
//					}
//				}
//			}
//			else
//			{
//				switch (helperValley[i][j])
//				{
//				case '>':
//					/*if (helperValley[i][j + 1] != '.')
//					{
//						informationOnCurrentBlizzards.push_back({ { i, j + 1}, '>' });
//						switch (helperValley[i][j + 1])
//						{
//						case '<':
//							informationOnCurrentBlizzards.push_back({ { i, j + 1}, '<' });
//							break;
//						case '^':
//							informationOnCurrentBlizzards.push_back({ { i, j + 1}, '^' });
//							break;
//						case 'v':
//							informationOnCurrentBlizzards.push_back({ { i, j + 1}, 'v' });
//							break;
//						}
//						helperValley[i][j] = '.';
//						helperValley[i][j + 1] = '2';
//					}
//					else if (isdigit(helperValley[i][j + 1]))
//					{
//						informationOnCurrentBlizzards.push_back({ { i, j + 1}, '>' });
//						helperValley[i][j + 1]++;
//					}
//					else */if (helperValley[i][j + 1] == '#')
//					{
//						if (isdigit(v[i][1]))
//						{
//							informationOnCurrentBlizzards.push_back({ { i, 1}, '>' });
//							v[i][1]++;
//						}
//						else if (v[i][1] != '.')
//						{
//							informationOnCurrentBlizzards.push_back({ { i, 1}, '>' });
//							informationOnCurrentBlizzards.push_back({ { i, 1}, v[i][1] });
//							v[i][1] = '2';
//						}
//						else
//						{
//							v[i][1] = '>';
//							if (v[i][j] == '>')
//							{
//								v[i][j] = '.';
//							}
//							if (isSideBySideRight)
//							{
//								v[i][j] = '>';
//								isSideBySideRight = false;
//							}
//						}
//					}
//					else if (helperValley[i][j + 1] == '>')
//					{
//						v[i][j] = '.';
//						isSideBySideRight = true;
//					}
//					else if (helperValley[i][j + 1] == '<')
//					{
//						std::swap(v[i][j], v[i][j + 1]);
//						j++;
//					}
//					else
//					{
//						v[i][j + 1] = '>';
//						v[i][j] = '.';
//						if (isSideBySideRight)
//						{
//							v[i][j] = '>';
//							isSideBySideRight = false;
//						}
//					}
//					break;
//				case '<':
//					/*if (helperValley[i][j - 1] != '.')
//					{
//						informationOnCurrentBlizzards.push_back({ { i, j - 1}, '<' });
//						switch (helperValley[i][j - 1])
//						{
//						case '>':
//							informationOnCurrentBlizzards.push_back({ { i, j - 1}, '>' });
//							break;
//						case '^':
//							informationOnCurrentBlizzards.push_back({ { i, j - 1}, '^' });
//							break;
//						case 'v':
//							informationOnCurrentBlizzards.push_back({ { i, j - 1}, 'v' });
//							break;
//						}
//						helperValley[i][j] = '.';
//						helperValley[i][j - 1] = '2';
//					}
//					else */if (isdigit(v[i][j - 1]))
//					{
//						informationOnCurrentBlizzards.push_back({ { i, j - 1}, '<' });
//						v[i][j - 1]++;
//					}
//					else if (v[i][j - 1] == '#')
//					{
//						/*if (isdigit(v[i][v.size() - 2]))
//						{
//							informationOnCurrentBlizzards.push_back({ { i, j - 1}, '<' });
//							v[i][v.size() - 2]++;
//						}
//						else if (v[i][1] != '.')
//						{
//							informationOnCurrentBlizzards.push_back({ { i, v.size()-2}, '<'});
//							informationOnCurrentBlizzards.push_back({ { i, v.size() - 2}, v[i][v.size() - 2] });
//							v[i][j] = '.';
//							v[i][v.size() - 2] = '2';
//						}
//						else
//						{*/
//						v[i][j] = '.';
//						v[i][v.size() - 2] = '<';
//						isNewLeft = true;
//							//std::swap(v[i][j], v[i][v.size() - 2]);
//						//}
//					}
//					else if (v[i][j - 1] != '.')
//					{
//						if (!isNewLeft)
//						{
//							informationOnCurrentBlizzards.push_back({ { i, j - 1}, '<' });
//							informationOnCurrentBlizzards.push_back({ { i, j - 1}, v[i][j - 1] });
//							v[i][j] = '.';
//							v[i][j - 1] = '2';
//						}
//					}
//					else
//					{
//						if (!isNewLeft)
//						{
//							std::swap(v[i][j], v[i][j - 1]);
//						}
//					}
//					break;
//				case '^':
//					if (helperValley[i - 1][j] != '.')
//					{
//						informationOnCurrentBlizzards.push_back({ { i - 1, j}, '^' });
//						switch (helperValley[i - 1][j])
//						{
//						case '<':
//							informationOnCurrentBlizzards.push_back({ { i - 1, j}, '<' });
//							break;
//						case '>':
//							informationOnCurrentBlizzards.push_back({ { i - 1, j}, '>' });
//							break;
//						case 'v':
//							informationOnCurrentBlizzards.push_back({ { i - 1, j}, 'v' });
//							break;
//						}
//						helperValley[i][j] = '.';
//						helperValley[i - 1][j] = '2';
//					}
//					else if (isdigit(helperValley[i - 1][j]))
//					{
//						informationOnCurrentBlizzards.push_back({ { i - 1, j}, '^' });
//						helperValley[i - 1][j]++;
//					}
//					else if (helperValley[i - 1][j] == '#')
//					{
//						std::swap(helperValley[i][j], helperValley[helperValley.size() - 2][j]);
//					}
//					else
//					{
//						std::swap(helperValley[i][j], helperValley[i - 1][j]);
//					}
//					break;
//				case 'v':
//					if (helperValley[i + 1][j] != '.')
//					{
//						informationOnCurrentBlizzards.push_back({ { i + 1, j}, 'v' });
//						switch (helperValley[i + 1][j])
//						{
//						case '<':
//							informationOnCurrentBlizzards.push_back({ { i + 1, j}, '<' });
//							break;
//						case '>':
//							informationOnCurrentBlizzards.push_back({ { i + 1, j}, '>' });
//							break;
//						case '^':
//							informationOnCurrentBlizzards.push_back({ { i + 1, j}, '^' });
//							break;
//						}
//						helperValley[i][j] = '.';
//						helperValley[i + 1][j] = '2';
//					}
//					else if (isdigit(helperValley[i + 1][j]))
//					{
//						informationOnCurrentBlizzards.push_back({ { i + 1, j}, 'v' });
//						helperValley[i + 1][j]++;
//					}
//					else if (helperValley[i + 1][j] == '#')
//					{
//						std::swap(helperValley[i][j], helperValley[1][j]);
//					}
//					else
//					{
//						std::swap(helperValley[i][j], helperValley[i + 1][j]);
//					}
//					break;
//				}
//			}
//		}
//	}
//
//	/*v.clear();
//	for (int i = 0; i < helperValley.size(); i++)
//	{
//		v.push_back(helperValley[i]);
//	}*/
//}
//
//int main()
//{
//	std::ifstream o("AdventOfCode//2022//File_txt//test5.txt");
//
//	std::string input;
//
//	std::vector<std::string> valley;
//
//
//	while (!o.eof())
//	{
//		while (getline(o, input))
//		{
//			if (!input.empty())
//			{
//				valley.push_back(input);
//			}
//		}
//	}
//
//	valley[0][1] = 'E';
//
//	for (int i = 0; i < valley.size(); i++)
//	{
//		std::cout << valley[i] << '\n';
//	}
//	std::cout << "\n\n";
//	blizzardMovement(valley);
//	for (int i = 0; i < valley.size(); i++)
//	{
//		std::cout << valley[i] << '\n';
//	}
//
//	o.close();
//
//	system("PAUSE");
//	return 0;
//}