#pragma once
#include "Cards.h"

class Player
{
public:
	Player();
	~Player();
	Cards draw();
	Cards myCards[];
};

