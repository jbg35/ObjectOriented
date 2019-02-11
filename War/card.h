#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <vector>
#include <ostream>

enum SUIT {
	SPADES,
	HEARTS,
	CLUBS,
	DIAMONDS,	
};

inline std::ostream & operator<<(std::ostream & os, SUIT s) {
	switch(s) {
		case HEARTS: return os << "H";
    	case DIAMONDS: return os << "D";
    	case CLUBS: return os << "C";
		case SPADES: return os << "S";
	}
	return os; // !!Questionable, added to remove warning
}

enum RANK {
	ACE,
	TWO,
	THREE,
	FOUR,
	FIVE,
	SIX,
	SEVEN,
	EIGHT,
	NINE,
	TEN,
	JACK,
	QUEEN,
	KING,
};

inline std::ostream & operator<<(std::ostream & os, RANK r){   
    switch(r){
    case TWO: return os << "2";
    case THREE: return os << "3";
    case FOUR: return os << "4";
    case FIVE: return os << "5";
    case SIX: return os << "6";
    case SEVEN: return os << "7";
    case EIGHT: return os << "8";
    case NINE: return os << "9";
    case TEN: return os << "T";
    case JACK: return os << "J";
    case QUEEN: return os << "Q";
    case KING: return os << "K";
    case ACE: return os << "A";
    }
    return os; // !!Questionable, added to remove warning
}

class Card {
private:
	SUIT suit;
	RANK rank;

public:
	Card();
	~Card(){}

	Card(RANK rank = ACE , SUIT suit = CLUBS):
		suit (suit), rank(rank) {}

	SUIT getSuit() { return suit; }
	RANK getRank() { return rank; }

	void showCard() {
		
		std::cout << RANK(this->rank) << SUIT(this->suit) << " ";
		
	}

};

#endif