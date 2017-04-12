#include "Deck.h"

Deck::Deck()
{
	topCard = 0;
	for (int i = 1; i <= 13; i++) {
		Cards c1(diamond, i), c2(spade, i), c3(heart, i), c4(club, i);
		cards[topCard++] = c1;
		cards[topCard++] = c2;
		cards[topCard++] = c3;
		cards[topCard++] = c4;
	}
}


Deck::~Deck()
{
}

Cards Deck::draw()
{
	{
		if (!isEmpty())
			return cards[--topCard];
		else {	  // otherwise return ace of spades
			Cards spadeAce(spade, 1);
			return spadeAce;
		}
	}
}
