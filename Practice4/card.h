#pragma once

#include <iostream>
#include <vector>
#include <ostream>
#include <cassert>
#include <deque>


enum SUIT {
	SPADES, HEARTS, CLUBS, DIAMONDS,	
};

enum RANK {
	ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN,
	EIGHT, NINE, TEN, JACK, QUEEN, KING,
};


enum COLOR {
	BLACK,
	RED,
};

class StdCard {
public:
	StdCard(RANK r, SUIT s) :
	rank(r), suit(s) { }

	RANK get_rank() const { return rank; }
	SUIT get_suit() const { return suit; }

private:
	RANK rank;
	SUIT suit;
};

bool operator==(StdCard a, StdCard b);
bool operator!=(StdCard a, StdCard b);

bool operator<(StdCard a, StdCard b);
bool operator>(StdCard a, StdCard b);
bool operator<=(StdCard a, StdCard b);
bool operator>=(StdCard a, StdCard b);


class JokerCard {
public:
	JokerCard(COLOR c)
	: color(c) 
	{ }

	COLOR get_color() const { return color; }

private:
	COLOR color;

};

union PlayingCardUnion {
	PlayingCardUnion(RANK r, SUIT s)
	: sc(r, s) 
	{ }
	PlayingCardUnion(COLOR c)
	: jc(c) 
	{ }

	StdCard sc;
	JokerCard jc;

};

enum CardKind {
	Standard,
	Joker,
};

class Card {
public:
	Card(RANK r, SUIT s)
	: tag(Standard), data(r,s) 
	{ }

	Card(COLOR c)
	: tag(Joker), data(c) 
	{ }

	bool isStd() const { return tag == Standard; }
	bool isJoker() const { return tag == Joker; }

	StdCard get_as_standard() {
    assert(isStd());
    return data.sc;
 	}
  	RANK getRank() { 
  		assert(isStd());
  		return data.sc.get_rank();
  	}
  	SUIT getSuit() {
  		assert(isStd());
  		return data.sc.get_suit();
  	}
  	JokerCard get_as_joker() {
  		assert(isJoker());
  		return data.jc;
  	}
  	COLOR getColor() {
  		assert(isJoker());
  		return data.jc.get_color();
  	}

private:
	CardKind tag;
	PlayingCardUnion data;

};

struct Deck : std::deque<Card> {
	using std::deque<Card>::deque;
};

std::ostream & operator<<(std::ostream & os, SUIT s) {
	switch(s) {
		case HEARTS: return os << "H";
    	case DIAMONDS: return os << "D";
    	case CLUBS: return os << "C";
		case SPADES: return os << "S";
	}
}

std::ostream & operator<<(std::ostream & os, RANK r){   
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
}

std::ostream& operator<<(std::ostream& os, COLOR c) {
	return os << (c == BLACK ? "B" : "R");
}

std::ostream& operator<<(std::ostream& os, StdCard c)
{
  return os << c.get_rank() << c.get_suit();
}
std::ostream& operator<<(std::ostream& os, JokerCard c)
{
  return os << c.get_color();
}

std::ostream& operator<<(std::ostream& os, Card c)
{
  if (c.isStd())
    return os << c.get_as_standard();
  else
    return os << c.get_as_joker();
}

std::ostream& operator<<(std::ostream& os, Deck const& d)
{
  int n = 0;
  for (Card c : d) {
    os << c << ' ';
    if (n == 12) {
      os << '\n';
      n = 0;
    }
    else {
      ++n;
    }
  }
  return os;
}