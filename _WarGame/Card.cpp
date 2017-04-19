#include "Card.h"

Card::Card()
{
	suit = spade;
	rank = 1;
}

Card::Card(suits suits, int ranks)
{
	suit = suits;
	rank = ranks;
}


std::ostream & operator << (std::ostream & out, Card & aCard) {
	switch (aCard.rank) {
	case 11: out << "Jack";  break;
	case 12: out << "Queen"; break;
	case 13: out << "King";  break;
	case 14:  out << "Ace";   break;
	default:
		out << aCard.rank; break;
	}

	switch (aCard.suit) {
	case diamond: out << " of Diamonds"; break;
	case spade:   out << " of Spades";   break;
	case heart:   out << " of Hearts";   break;
	case club:    out << " of Clubs";    break;
	}
	return out;
};
