#pragma once
#include "Cards.h"
#include <algorithm>
#include <vector>

class Deck
{
public:
	Deck();
	~Deck();
	void shuffle() {
		std::random_shuffle(cards.begin(), cards.end());
	};
	bool isEmpty() {
		return topCard <= 0;
	};
	Cards draw();
	std::vector<Cards> cards;
	int topCard;
};


