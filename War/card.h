#ifndef CARD_H
#define CARD_H

#include <iostream>

enum SUIT {
	SPADES,
	HEARTS,
	CLUBS,
	DIAMONDS,	
};

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


	static std::string suitToString(SUIT suit) {
		switch(suit) {
			case SPADES:
				return "Spades";
			case HEARTS:
				return "Hearts";
			case CLUBS:
				return "Clubs";
			case DIAMONDS:
				return "Diamonds";
			default:
				return "bad suit";
		}
	}

	static std::string rankToString(RANK rank) {
	switch(rank) {
		case ACE:
			return "Ace";
		case TWO: 
			return "Two";
		case THREE:
			return "Three";
		case FOUR:
			return "Four";
		case FIVE:
			return "Five";
		case SIX:
			return "Six";
		case SEVEN:
			return "Seven";
		case EIGHT:
			return "Eight";
		case NINE:
			return "Nine";
		case TEN:
			return "Ten";
		case JACK:
			return "Jack";
		case QUEEN:
			return "Queen";
		case KING:
			return "King";
		default:
			return "bad rank";
		}
	}
	std::string name() { return rankToString(rank) + " of " + suitToString(suit); }
};

#endif