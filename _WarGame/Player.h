#pragma once
#include "Card.h"
#include <queue>
#include <iostream>
#include <string>

class Player
{
public:
	Player(std::string name);
	Card draw();
	std::string getName() const { return _name; };
	void pushCard(Card card);
	int numberOfCards() const { return (int)myCards.size(); };
private:
	std::queue<Card> myCards;
	std::string _name;
};
