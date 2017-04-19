#include "WarGameCardComparer.h"

int WarGameCardComparer::compare(Card card1, Card card2)
{
	if (card1.getRank() > card2.getRank()) {
		return 1;
	}
	if (card1.getRank() < card2.getRank()) {
		return 2;
	}
	return 0;
}
