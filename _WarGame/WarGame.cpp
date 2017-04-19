// WarGame.cpp : Defines the entry point for the console application.
//
#pragma once
#include "stdafx.h"
#include "Deck.h"
#include "Player.h"
#include <algorithm>
#include <Dealer.h>


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
	dealer.deal(&deck, {&player1,&player2});
	//for (int i = 0; i < 26; i++) {
	//	player1.pushCard(deck.draw());
	//	player2.pushCard(deck.draw());
	//}
	while (player1.numberOfCards() > 0 && player2.numberOfCards()> 0)
	{
		table.push_back(player1.draw());
		table.push_back(player2.draw());
		if (table[0].getRank() > table[1].getRank())
		{
			for each (Card card in table)
			{
				player1.pushCard(card);
			}
			table.erase(table.begin(), table.end());
			std::cout << "Player 1 wins hand!" << std::endl;
			std::cout << std::endl;
		}
		else if (table[0].getRank()== table[1].getRank()) {
			War(table, &player1, &player2);
			table.erase(table.begin(), table.end());
		}
		else {
			for each (Card card in table)
			{
				player2.pushCard(card);
			}
			table.erase(table.begin(), table.end());
			std::cout << "Player 2 wins hand!" << std::endl;
			std::cout << std::endl;
		}

	}
	if(player1.numberOfCards() == 0){
		std::cout << "Player 2 wins!" << std::endl;
	}
	else {
		std::cout << "Player 1 wins!" << std::endl;
	}
	return 0;
}

void War(std::vector<Card> table, Player* player1, Player* player2) {
	std::cout << "War started!"<<std::endl;
	
	int minCards = std::min((int)player1->numberOfCards(), (int)player2->numberOfCards());
	int tableCardRank = table[table.size() - 1].getRank();
	if (minCards>0)
	{
		for (int i = 0; i < std::min(tableCardRank, minCards); i++) {
			table.push_back(player1->draw());
			table.push_back(player2->draw());
		}
		if (table[table.size() - 1].getRank() > table[table.size() - 2].getRank()) {
			for each (Card card in table)
			{
				player2->pushCard(card);
			}
			std::cout << "War ended!" << std::endl;
			std::cout << "Player 2 wins war!" << std::endl;
			std::cout << std::endl;
		}
		else if (table[table.size() - 1].getRank() < table[table.size() - 2].getRank()) {
			for each (Card card in table)
			{
				player1->pushCard(card);
				std::cout << "War ended!" << std::endl;
				std::cout << "Player 1 wins war!" << std::endl;
				std::cout << std::endl;
			}
		}
		else {
			War(table, player1, player2);
		}

	}
	
}

