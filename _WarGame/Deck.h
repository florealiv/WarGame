#pragma once
#include "Cards.h"
#include <algorithm>

class Deck
{
public:
	Deck();
	~Deck();
	void shuffle() {
		std::random_shuffle(cards, cards + 52);
	};
	bool isEmpty() {
		return topCard <= 0;
	};
	Cards draw();
	Cards cards[52];
	int topCard;
};


