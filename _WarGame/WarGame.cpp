// WarGame.cpp : Defines the entry point for the console application.
//
#pragma once
#include "stdafx.h"
#include "Deck.h"
#include "Player.h"
#include <algorithm>

int main()
{
	Deck deck;
	Player player1, player2;
	deck.shuffle();
	std::vector<Cards> table;
	for (int i = 0; i < 26; i++) {
		player1.myCards.push(deck.draw());
		player2.myCards.push(deck.draw());
	}
	while (!player1.myCards.empty() && !player2.myCards.empty())
	{
		table.push_back(player1.draw());
		table.push_back(player2.draw());
		if (table[0].rank > table[1].rank)
		{
			player1.myCards.push(table[0]);
			player1.myCards.push(table[1]);
			table.erase(table.begin(), table.end());
		}
		else if (table[0].rank = table[1].rank) {
			for (int i = 0; i < std::min(table[0].rank, std::min((int)player1.myCards.size(), (int)player2.myCards.size())); i++) {
				table.push_back(player1.draw());
				table.push_back(player2.draw());
			}
			if (table[table.size() - 1].rank > table[table.size() - 2].rank) {
				for each (Cards card in table)
				{
					player1.myCards.push(card);
				}
				table.erase(table.begin(), table.end());
			}
			else if (table[table.size() - 1].rank < table[table.size() - 2].rank) {
				for each (Cards card in table)
				{
					player2.myCards.push(card);
				}
				table.erase(table.begin(), table.end());
			}
			else {

			}
		}
		else {
			player2.myCards.push(table[0]);
			player2.myCards.push(table[1]);
			table.erase(table.begin(), table.end());
		}

	}
	return 0;
}

