// WarGame.cpp : Defines the entry point for the console application.
//
#pragma once
#include "stdafx.h"
#include "Deck.h"
#include "Player.h"
#include <algorithm>
#include "Dealer.h"
#include "WarGameCardComparer.h"


void War(std::vector<Card> table, Player* player1, Player* player2);
void War(std::vector<Card> table, std::vector<Player> &players, std::vector<int> winners);
int GetMinNumberOfCards(std::vector<Card> table, std::vector<Player> &players);

int main()
{
	Deck deck;
	Dealer dealer;
	std::queue<Card> emptyCards;
	int minimumPlayers = 2, maximumPlayers = 6;
	int numberOfPlayers = minimumPlayers + (rand() % (int)(maximumPlayers - minimumPlayers + 1));
	std::vector<Player> players{};
	for (int i = 1; i <= numberOfPlayers; i++) {
		players.push_back(Player("Player" + std::to_string(i)));
	}
	std::vector<Card> table;
	dealer.shuffle(deck);
	dealer.deal(deck, players);
	while (players.size() > 1)
	{

		for (int i = 0; i < (int)players.size(); i++) {
			table.push_back(players[i].draw());
			std::cout << players[i].getName() + " plays " << table[table.size() - 1] << std::endl;
		}

		auto winner = WarGameCardComparer::compare(table, players.size());
		if (winner.size() > 1) {
			if (players.size() > 2) {
				War(table, players, winner);
			}
			else {
				War(table, &players[0], &players[1]);
			}
		}
		else {

			for each (Card card in table)
			{
				players[winner[0]].pushCard(card);
			}

		}
		std::cout << players[winner[0]].getName() << " wins hand!" << std::endl;
		winner.clear();
		table.clear();
		for (int i = 0; i < (int)players.size(); i++) {
			if (players[i].numberOfCards() == 0) {
				players.erase(players.begin() + i);
			}
		}
	}

	std::cout << players[0].getName() << " wins!" << std::endl;
	return 0;
}

void War(std::vector<Card> table, Player* player1, Player* player2) {
	std::cout << "War started!" << std::endl;


	int tableCardRank = table[table.size() - 1].getRank();
	while (WarGameCardComparer::compare(table[table.size() - 2], table[table.size() - 1]) == 0 && std::min((int)player1->numberOfCards(), (int)player2->numberOfCards()) > 0)
	{
		int minCards = std::min((int)player1->numberOfCards(), (int)player2->numberOfCards());
		for (int i = 0; i < std::min(tableCardRank, minCards); i++) {
			table.push_back(player1->draw());
			std::cout << player1->getName() + " plays " << table[table.size() - 2] << std::endl;
			table.push_back(player2->draw());
			std::cout << player2->getName() + " plays " << table[table.size() - 1] << std::endl;
		}
		if (WarGameCardComparer::compare(table[table.size() - 2], table[table.size() - 1]) == 2) {
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
	}
}

void War(std::vector<Card> table, std::vector<Player> &players, std::vector<int> winners) {
	std::cout << "War started!" << std::endl;
	int tableCardRank = table[table.size() - 1].getRank(), numberOfPlayers = winners.size();
	while (winners.size() > 1)
	{
		for (int i = 0; i < std::min(GetMinNumberOfCards(table, players), tableCardRank); i++) {
			for (int j = 0; j < (int)winners.size(); j++) {
				table.push_back(players[winners[j]].draw());
				std::cout << players[winners[j]].getName() + " plays " << table[table.size() - 1] << std::endl;
			}
		}
		winners = WarGameCardComparer::compare(table, winners.size());
	}
	WarGameCardComparer::compare(table, numberOfPlayers);
	for each (Card card  in table)
	{
		players[winners[0]].pushCard(card);
	}
	std::cout << "War ended!";
	std::cout << players[winners[0]].getName() << " wins war!!" << std::endl;
}

int GetMinNumberOfCards(std::vector<Card> table, std::vector<Player> &players) {
	std::vector<int> numberOfCards;
	for each (Player player in players)
	{
		numberOfCards.push_back(player.numberOfCards());
	}

	int min = *std::min_element(numberOfCards.begin(), numberOfCards.end());
	return min;
}

