#pragma once
#include "Cards.h"
#include <queue>
#include <iostream>
#include <string>

class Player
{
public:
	Player();
	Player(std::string name);
	~Player();
	Cards draw();
	std::queue<Cards> myCards;
	std::string _name;
};
