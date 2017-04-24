#include "Deck.h"

Deck::Deck()
{
	for (int i = 2; i <= 14; i++) {
		Card c1(diamond, i), c2(spade, i), c3(heart, i), c4(club, i);
		cards.push_back(c1);
		cards.push_back(c2);
		cards.push_back(c3);
		cards.push_back(c4);
	}
}

Deck::Deck(int minCard, int maxCard)
{
	for (int i = minCard; i <= maxCard; i++) {
		Card c1(diamond, i), c2(spade, i), c3(heart, i), c4(club, i);
		cards.push_back(c1);
		cards.push_back(c2);
		cards.push_back(c3);
		cards.push_back(c4);
	}
}




Card Deck::draw()
{

	Card card = cards.front();
	cards.erase(cards.begin());
	return card;
}
