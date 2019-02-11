#include <iostream>

#include "card.h"
#include "deck.h"
#include "hand.h"

int main() {

	std::cout << "\n";
	Deck deck;
	deck.Deck::print();
	std::cout << "\n";
	deck.Deck::shuffle();
	deck.Deck::print();
	std::cout << "\n";


}