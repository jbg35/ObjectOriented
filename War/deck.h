#ifndef DECK_H
#define DECK_H

#include <iostream>
#include <vector>
#include "card.h"


class Deck {
private:
	

public:
	Deck();
	~Deck(){}
	static std::vector<Card> makeDeck();
};

std::vector<Card> Deck::makeDeck() {
	std::vector<Card> deck;

	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 13; j++) {
			deck.push_back(Card(RANK(j), SUIT(i)));
			std::cout << Card::rankToString(RANK(j)) << " OF " << Card::suitToString(SUIT(i)) << "\n";
		}

return deck;
}
#endif