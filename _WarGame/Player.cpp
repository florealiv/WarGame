#include "Player.h"

Player::Player( std::string name)
	 :_name(name)
{
}


Card Player::draw()
{
	Card card = myCards.front();
	popCard();
	return card;
}

void Player::pushCard(Card card) {
	myCards.push(card);
}