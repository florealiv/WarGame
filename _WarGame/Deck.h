#pragma once
#include "Card.h"
#include <algorithm>
#include <vector>
#include <ctime>  

class Deck
{
public:
	Deck();
	Deck(int minCard, int maxCard);
	void shuffle() {
		std::srand(unsigned(std::time(0)));
		std::random_shuffle(cards.begin(), cards.end());
	};
	Card draw();
	bool isEmpty() const { return cards.size() == 0; };
private:
	std::vector<Card> cards;
};


