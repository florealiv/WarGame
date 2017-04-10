#pragma once
#include "stdafx.h"
#include <iostream>

enum suits { diamond, club, heart, spade };

class Cards
{
public:
	int rank;
	suits suit;
	Cards();
	Cards(suits suit,int rank);
	~Cards();
	friend std::ostream& operator << (std::ostream& out, Cards& aCard);
};

