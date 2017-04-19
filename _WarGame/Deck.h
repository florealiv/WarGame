#pragma once
#include "Card.h"
#include <algorithm>
#include <vector>
#include <ctime>  

class Deck
{
public:
	Deck();
	void shuffle() {
		std::srand(unsigned(std::time(0)));
		std::random_shuffle(cards.begin(), cards.end());
	};
	Card draw();
	bool isEmpty() { return cards.size() == 0; };
private:
	std::vector<Card> cards;
};


