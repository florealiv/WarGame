// WarGame.cpp : Defines the entry point for the console application.
//
#pragma once
#include "stdafx.h"
#include "Deck.h"
#include "Player.h"
#include <algorithm>
#include <Dealer.h>
#include <WarGameCardComparer.h>


void War(std::vector<Card> table, Player* player1, Player* player2);

int main()
{
	Deck deck;
	Dealer dealer;
	/*std::vector<Player*> players;
	players.push_back(&Player("Player 1"));
	players.push_back(&Player("Player 2"));*/
	Player player1 = Player("Player 1");
	Player player2 = Player("Player 2");
	std::vector<Card> table;
	dealer.shuffle(&deck);
	dealer.deal(&deck, { &player1,&player2 });
	//for (int i = 0; i < 26; i++) {
	//	player1.pushCard(deck.draw());
	//	player2.pushCard(deck.draw());
	//}
	while (player1.numberOfCards() > 0 && player2.numberOfCards() > 0)
	{
		table.push_back(player1.draw());
		table.push_back(player2.draw());
		if (WarGameCardComparer::compare(table[0], table[1]) == 1)
		{
			for each (Card card in table)
			{
				player1.pushCard(card);
			}
			table.erase(table.begin(), table.end());
			std::cout << "Player 1 wins hand!" << std::endl;
			std::cout << std::endl;
		}
		else if (WarGameCardComparer::compare(table[0], table[1]) == 2) {
			for each (Card card in table)
			{
				player2.pushCard(card);
			}
			table.erase(table.begin(), table.end());
			std::cout << "Player 2 wins hand!" << std::endl;
			std::cout << std::endl;
		}

		else {
			War(table, &player1, &player2);
			table.erase(table.begin(), table.end());
		}
	}
	if (player1.numberOfCards() == 0) {
		std::cout << "Player 2 wins!" << std::endl;
	}
	else {
		std::cout << "Player 1 wins!" << std::endl;
	}
	return 0;
}

void War(std::vector<Card> table, Player* player1, Player* player2) {
	std::cout << "War started!" << std::endl;

	int minCards = std::min((int)player1->numberOfCards(), (int)player2->numberOfCards());
	int tableCardRank = table[table.size() - 1].getRank();
	if (minCards > 0)
	{
		for (int i = 0; i < std::min(tableCardRank, minCards); i++) {
			table.push_back(player1->draw());
			table.push_back(player2->draw());
		}
		if (WarGameCardComparer::compare( table[table.size() - 2], table[table.size() - 1])==2) {
			for each (Card card in table)
			{
				player2->pushCard(card);
			}
			std::cout << "War ended!" << std::endl;
			std::cout << "Player 2 wins war!" << std::endl;
			std::cout << std::endl;
		}
		else if (WarGameCardComparer::compare(table[table.size() - 2], table[table.size() - 1]) == 1) {
			for each (Card card in table)
			{
				player1->pushCard(card);
			}
				std::cout << "War ended!" << std::endl;
				std::cout << "Player 1 wins war!" << std::endl;
				std::cout << std::endl;
		}
		else {
			War(table, player1, player2);
		}

	}

}

