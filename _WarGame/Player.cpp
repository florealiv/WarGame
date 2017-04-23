#include "Player.h"

Player::Player(std::string name)
{
	_name = name;
	myCards = {};
}

Card Player::draw()
{
	Card card = myCards.front();
	myCards.pop();
	return card;
}

void Player::pushCard(Card card ) {
	myCards.push(card);
}