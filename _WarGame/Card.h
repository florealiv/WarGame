#pragma once
#include "stdafx.h"
#include <iostream>

enum suits { diamond, club, heart, spade };

class Card
{
public:
	Card();
	Card(suits suit,int rank);
	int getRank() const { return rank; };
	int getSuit() const { return suit; };
private:
	int rank;
	suits suit;
};

	std::ostream& operator << (std::ostream& out, Card& aCard);
