#pragma once
#include "Card.h"
class WarGameCardComparer
{
public:
	static int compare(const Card& card1,const Card& card2);
	static 	std::vector<int> WarGameCardComparer::compare(std::vector<Card> cardsOnTable, int numberOfPlayers);
};

