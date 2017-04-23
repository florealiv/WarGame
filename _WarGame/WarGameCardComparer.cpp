#include "WarGameCardComparer.h"
#include <vector>
#include <algorithm>

static int getIndex(std::vector<int> v, const int c);

int WarGameCardComparer::compare(const Card& card1, const Card& card2)
{
	const std::vector<int> cards = { 2,3,4,5,6,7,8,9,10,12,13,14,11 };
	
	if (getIndex(cards, card1.getRank()) > getIndex(cards, card2.getRank())) {
		return 1;
	}
	if (getIndex(cards, card1.getRank()) < getIndex(cards, card2.getRank())) {
		return 2;
	}
	return 0;
}

std::vector<int> WarGameCardComparer::compare(std::vector<Card> cardsOnTable) {
	std::vector<int> cardRanks;
	std::vector<int> winningCards;
	for each (Card card in cardsOnTable)
	{
		cardRanks.push_back(card.getRank());
	}
	int maxValue = *std::max_element(cardRanks.begin(), cardRanks.end());
	
	for (int i = 0; i < cardsOnTable.size(); i++)
	{
		if (cardsOnTable[i].getRank() == maxValue) {
			winningCards.push_back(i);
		}
	}
	//TODO
	return winningCards	;
}

static int getIndex(std::vector<int> v,const int c) {
	std::vector<int>::iterator iter = std::find(v.begin(), v.end(), c);
	return (int) std::distance(v.begin(), iter);
}
