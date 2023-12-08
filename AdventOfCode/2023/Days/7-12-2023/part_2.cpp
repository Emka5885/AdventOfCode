/*
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

enum Type { FiveOfAKind, FourOfAKind, FullHouse, ThreeOfAKind, TwoPair, OnePair, HighCard };

void SetStrength(const std::string& hand, std::vector<int>& strength)
{
	for (int i = 0; i < 13; i++)
		strength.emplace_back(0);	// [J, 2, 3, 4, 5, 6, 7, 8, 9, T, Q, K, A]

	for (char card : hand)
	{
		int id;
		if (card == 'T') id = 9;
		else if (card == 'J') id = 0;
		else if (card == 'Q') id = 10;
		else if (card == 'K') id = 11;
		else if (card == 'A') id = 12;
		else id = card - '1';

		strength[id]++;
	}
}

Type SetType(std::string& hand)
{
	std::vector<int> counts;
	SetStrength(hand, counts);

	int pairs, triples, fours, fives;
	pairs = triples = fours = fives = 0;

	int Jpairs, Jtriples, Jfours, Jfives;
	Jpairs = Jtriples = Jfours = Jfives = 0;

	int jCards = counts[0];
	int k = -1;
	switch(jCards)
	{
	case 1:
		for (int j = 4; j > 0; j--)
		{
			for (int i = 1; i < counts.size(); i++)
			{
				if (counts[i] == j)
				{
					k = i;
					switch (j)
					{
					case 4:
						Jfives++;
						break;
					case 3:
						Jfours++;
						break;
					case 2:
						Jtriples++;
						break;
					case 1:
						Jpairs++;
						break;
					}
					j = 0;
					i = counts.size();
				}
			}
		}
		break;

	case 2:
		for (int j = 3; j > 0; j--)
		{
			for (int i = 1; i < counts.size(); i++)
			{
				k = i;
				if (counts[i] == j)
				{
					switch (j)
					{
					case 3:
						Jfives++;
						break;
					case 2:
						Jfours++;
						break;
					case 1:
						Jtriples++;
						break;
					}
					i = counts.size();
					j = 0;
				}
			}
		}
		break;

	case 3:
		for (int j = 2; j > 0; j--)
		{
			for (int i = 1; i < counts.size(); i++)
			{
				k = i;
				if (counts[i] == j)
				{
					switch (j)
					{
					case 2:
						Jfives++;
						break;
					case 1:
						Jfours++;
						break;
					}
					i = counts.size();
					j = 0;
				}
			}
		}
		break;

	case 4:
		for (int i = 1; i < counts.size(); i++)
		{
			k = i;
			if (counts[i] == 1)
			{
				Jfives++;
				break;
			}
		}
		break;
	}

	for (int i = 1; i < counts.size(); i++)
	{
		if (i != k)
		{
			if (counts[i] == 2) pairs++;
			else if (counts[i] == 3) triples++;
			else if (counts[i] == 4) fours++;
			else if (counts[i] == 5) fives++;
		}
	}

	if (jCards == 5)
		Jfives++;

	if (fives == 1 || Jfives == 1) return FiveOfAKind;
	if (fours == 1 || Jfours == 1) return FourOfAKind;
	if ((pairs == 1 && triples == 1) || (Jtriples == 1 && pairs == 1)) return FullHouse;
	if (triples == 1 || Jtriples == 1) return ThreeOfAKind;
	if (pairs == 2 || (Jpairs == 1 && pairs == 1)) return TwoPair;
	if (pairs == 1 || Jpairs == 1) return OnePair;

	return HighCard;
}

bool customComparator(const std::string& a, const std::string& b)
{
	std::string strength = "J23456789TQKA";

	for (int i = 0; i < 5; i++)
	{
		int idA = strength.find(a[i]);
		int idB = strength.find(b[i]);

		if (idA > idB)
			return true;
		if (idA < idB)
			return false;
	}

	return false;
}

int main()
{
	std::fstream file("AdventOfCode//2023//File_txt//07-12-2023.txt");

	std::vector<std::vector<std::string>> camelCardsTypes(7);
	std::vector<std::pair<std::string, int>> camelCards;

	while (!file.eof())
	{
		std::string line;
		std::getline(file, line);

		std::string hand = line.substr(0, 5);
		camelCardsTypes[SetType(hand)].emplace_back(hand);

		camelCards.emplace_back(hand, std::atoi(line.substr(6).c_str()));
	}
	file.close();

	for (int i = 0; i < camelCardsTypes.size(); i++)
	{
		std::sort(camelCardsTypes[i].begin(), camelCardsTypes[i].end(), customComparator);
	}

	std::vector<int> newCamelCards;
	for (int i = camelCardsTypes.size() - 1; i >= 0; i--)
	{
		for (int j = camelCardsTypes[i].size() - 1; j >= 0; j--)
		{
			for (int k = 0; k < camelCards.size(); k++)
			{
				if (camelCardsTypes[i][j] == camelCards[k].first)
				{
					newCamelCards.emplace_back(camelCards[k].second);
				}
			}
		}
	}

	int result = 0;
	for (int i = 0; i < newCamelCards.size(); i++)
	{
		result += newCamelCards[i] * (i + 1);
	}
	std::cout << result << '\n';

	return 0;
}
*/