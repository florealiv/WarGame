#include "Player.h"



Player::Player()
{
}

Player::Player(std::string name)
{
	_name = name;
}

Player::~Player()
{
}

Cards Player::draw()
{
	Cards card = myCards.front();
	std::cout << _name + " plays "<< card << std::endl;
	myCards.pop();
	return card;
}
