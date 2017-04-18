#pragma once
#include "Cards.h"
#include <algorithm>
#include <vector>
#include <random>	
#include <ctime>  

class Deck
{
public:
	Deck();
	~Deck();
	void shuffle() {
	/*	auto engine = std::default_random_engine{};
		std::shuffle(cards.begin(), cards.end(),engine);*/
		std::srand(unsigned(std::time(0)));
		std::random_shuffle(cards.begin(), cards.end());
	};
	bool isEmpty() {
		return topCard <= 0;
	};
	Cards draw();
	std::vector<Cards> cards;
	int topCard;
};


