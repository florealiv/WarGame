// WarGame.cpp : Defines the entry point for the console application.
//
#pragma once
#include "stdafx.h"
#include "Deck.h"
#include "Player.h"
#include <algorithm>


void War(std::vector<Cards> table, Player* player1, Player* player2);

int main()
{
	Deck deck;
	Player player1 = Player("Player 1");
	Player player2 = Player("Player 2");
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
			for each (Cards card in table)
			{
				player1.myCards.push(card);
			}
			table.erase(table.begin(), table.end());
		}
		else if (table[0].rank == table[1].rank) {
			War(table, &player1, &player2);
			table.erase(table.begin(), table.end());
		}
		else {
			for each (Cards card in table)
			{
				player2.myCards.push(card);
			}
			table.erase(table.begin(), table.end());
		}

	}
	if(player1.myCards.empty()){
		std::cout << "Player 1 wins!" << std::endl;
	}
	else {
		std::cout << "Player 2 wins!" << std::endl;
	}
	return 0;
}

void War(std::vector<Cards> table, Player* player1, Player* player2) {
	std::cout << "War started!"<<std::endl;
	for (int i = 0; i < std::min(table[table.size() - 1].rank, std::min((int)player1->myCards.size(), (int)player2->myCards.size())); i++) {
		table.push_back(player1->draw());
		table.push_back(player2->draw());
	}
	if (table[table.size() - 1].rank > table[table.size() - 2].rank) {
		for each (Cards card in table)
		{
			player2->myCards.push(card);
		}
		//table.erase(table.begin(), table.end());
	}
	else if (table[table.size() - 1].rank < table[table.size() - 2].rank) {
		for each (Cards card in table)
		{
			player1->myCards.push(card);
		}
		//table.erase(table.begin(), table.end());
	}
	else {
		War(table, player1, player2);
	}


}

