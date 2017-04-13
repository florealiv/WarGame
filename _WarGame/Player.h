#pragma once
#include "Cards.h"
#include <queue>

class Player
{
public:
	Player();
	~Player();
	Cards draw();
	std::queue<Cards> myCards;
};
