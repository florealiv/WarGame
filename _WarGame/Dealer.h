#pragma once
#include "Deck.h"
#include "Player.h"
class Dealer
{
public:
	void shuffle(Deck& deck);
	void deal(Deck& deck, std::vector<Player>& players);
};

