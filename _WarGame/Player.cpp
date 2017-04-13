#include "Player.h"



Player::Player()
{
}


Player::~Player()
{
}

Cards Player::draw()
{
	Cards card = myCards.front();
	myCards.pop();
	return card;
}
