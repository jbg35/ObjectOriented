#ifndef CARD_H
#define CARD_H

#include <iostream>

enum SUIT {
	SPADES,
	HEARTS,
	CLUBS,
	DIAMONDS,	
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
}

class Card {
private:
	SUIT suit;
	RANK rank;

public:
	Card();
	~Card(){}

	std::string suitToString() const {
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

	std::string rankToString() const {
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

};


#endif