#pragma once

#include <iostream>
#include <vector>
#include <ostream>

// 00SSRRRR
// RANK&00001111
// if
// 00000000 -> ACE  
// 00000001 -> TWO
// 00000010 -> THREE
// 00000011 -> FOUR
// 00000100 -> FIVE
// 00000101 -> SIX
// 00000110 -> SEVEN
// 00000111 -> EIGHT
// 00001000 -> NINE
// 00001001 -> TEN
// 00001010 -> JACK
// 00001011 -> QUEEN
// 00001100 -> KING
// 
// SUIT >> 4
// if
// 00000000 -> 0000 -> SPADES
// 00010000 -> 0001 -> HEARTS
// 00100000 -> 0010 -> CLUBS
// 00110000 -> 0011 -> DIAMONDS
// (left most bits don't matter,
//  if they did would use SUIT&00110000)

/*unsigned char SANDR = 0xf;

switch(SANDR&0xf) {
	case 0000: return 1;
	case 0001: return 2;
	case 0010: return 3;
	case 0011: return 4;
	case 0100: return 5;
	case 0101: return 6;
	case 0110: return 7;
	case 0111: return 8;
	case 1000: return 9;
	case 1001: return 10;
	case 1010: return 11;
	case 1011: return 12;
	case 1100: return 13;
}*/

enum SUIT {
	SPADES, HEARTS, CLUBS, DIAMONDS,	
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
	ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN,
	EIGHT, NINE, TEN, JACK, QUEEN, KING,
};

inline std::ostream & operator<<(std::ostream & os, RANK r){   
    switch(r){
    case ACE: return os << "A";
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

	Card(RANK rank, SUIT suit):
		suit (suit), rank(rank) {}

	SUIT getSuit() { return suit; }
	RANK getRank() { return rank; }

	void showCard() {
		std::cout << RANK(this->rank) << SUIT(this->suit) << " ";
		
	}

};
