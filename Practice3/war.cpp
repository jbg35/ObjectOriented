#include <iostream>
#include <vector>
#include "card.h"


int main() {

	std::vector<Card> deck;

	for(int i = 1; i < 5; i++) {
		for(int j = 1; j < 14; j++) {
			deck.push_back(Card(i, j))
		}
	}


}