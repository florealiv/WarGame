#pragma once
#include "Cards.h"
#include <vector>

class Player
{
public:
	Player();
	~Player();
	Cards draw();
	std::vector<Cards> myCards;
};
