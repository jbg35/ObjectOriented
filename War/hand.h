#pragma once
#include "deck.h"

class Hand {
private:
	int size;
	std::vector<Card> hand1;
	std::vector<Card> hand2;

public:
	Hand() {	
/*		int index = 0;
		for (auto it = Deck::deck.begin(); it != Deck::deck.end(); ++it)
		{
			if (index % NUMBER_OF_PLAYERS == 0) {
				hand1->addCard(*it);
			}
			else if (index % NUMBER_OF_PLAYERS == 1) {
				hand2->addCard(*it);
			}
			index++;
		}*/
	};
	void print();
};

void Hand::print() {
/*
        int topCard = 0;
        for (int i = topCard; i < 52; i++) {
            hand[i].showCard(); 
            if (((i+1) % 13) == 0) 
                std::cout << "\n";
    }*/
}