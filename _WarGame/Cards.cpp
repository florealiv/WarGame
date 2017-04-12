#include "Cards.h"

Cards::Cards()
{
	suit = spade;
	rank = 1;
}

Cards::Cards(suits suits, int ranks)
{
	suit = suits;
	rank = ranks;
}


Cards::~Cards()
{
}

 std::ostream & operator << (std::ostream & out, Cards & aCard){
	// first output rank
	switch (aCard.rank) {
	case 1:  out << "Ace";   break;
	case 11: out << "Jack";  break;
	case 12: out << "Queen"; break;
	case 13: out << "King";  break;
	default:	// output number
		out << aCard.rank; break;
	}

	// then output suit
	switch (aCard.suit) {
	case diamond: out << " of Diamonds"; break;
	case spade:   out << " of Spades";   break;
	case heart:   out << " of Hearts";   break;
	case club:    out << " of Clubs";    break;
	}
	return out;
};
