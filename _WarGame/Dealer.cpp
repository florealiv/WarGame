#include "Dealer.h"

void Dealer::shuffle(Deck &deck)
{
	deck.shuffle();
}

void Dealer::deal(Deck& deck, std::vector<Player>& players)
{
	int i = 0, numberOfPlayers = players.size();
	while (!deck.isEmpty()) {
		players[i%numberOfPlayers].pushCard(deck.draw());
		i++;
	}
}

