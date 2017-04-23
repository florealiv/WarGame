#pragma once
#include "stdafx.h"
#include <iostream>

enum suits { diamond, club, heart, spade };

class Card
{
public:
	Card();
	Card(suits suit,int rank);
	friend std::ostream& operator << (std::ostream& out, Card& aCard);
	int getRank() const { return rank; };
private:
	int rank;
	suits suit;
};

