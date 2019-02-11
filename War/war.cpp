#include <iostream>

#include "deck.h"
#include "card.h"

int main() {
	Deck deck1;
	std::cout << "\n";
	Deck deck2;
	deck1.Deck::shuffle();
	deck2.Deck::shuffle();
	std::cout << "\n\n";
	deck1.Deck::print();
	std::cout << "\n";
	deck2.Deck::print();
	std::cout << "\n\n";
}