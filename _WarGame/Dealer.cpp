#include "Dealer.h"

void Dealer::shuffle(Deck * deck)
{
	deck->shuffle();
}

void Dealer::deal(Deck * deck, std::vector<Player*> players)
{
	int i = 0;
	while(!deck->isEmpty()){
		players[i]->pushCard(deck->draw());
		i++;
		if (i > players.size()-1) {
			i = 0;
		}
	}
}
