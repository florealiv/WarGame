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

std::vector<int> WarGameCardComparer::compare(std::vector<Card> cardsOnTable,int numberOfPlayers) {
	std::vector<int> cardRanks;
	std::vector<int> winningCards;
	std::vector<Card> cardsToCompare;
	Card maxCard;
	
	for (int i = numberOfPlayers ; i >0; i--) {
		cardRanks.push_back(cardsOnTable[cardsOnTable.size()-i].getRank());
		cardsToCompare.push_back(cardsOnTable[cardsOnTable.size() - i]);
	}

	maxCard = cardsToCompare[0];
	for (int i = 1; i < cardsToCompare.size(); i++) {
		if (compare(maxCard, cardsToCompare[i ]) == 2) {
			maxCard = cardsToCompare[i];
		}
	}
	//for each (Card card in cardsOnTable)
	//{
	//	cardRanks.push_back(card.getRank());
	//}
	int maxValue = maxCard.getRank();
	
	for (int i = 0; i <(int)cardsToCompare.size(); i++)
	{
		if (cardsToCompare[i].getRank() == maxValue) {
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
