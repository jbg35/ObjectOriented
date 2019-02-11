#ifndef DECK_H
#define DECK_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include "card.h"

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::default_random_engine e(seed);

class Deck {
private:
    std::vector<Card> deck;

public:
    Deck() {  
      for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 13; j++) {
          deck.push_back(Card(RANK(j), SUIT(i)));
          std::cout << RANK(j) << "" << SUIT(i) << " ";
        }
        std::cout << "\n";
       }
    }

    void shuffle();
    void print();
    ~Deck(){}
};

void Deck::shuffle() {
    std::shuffle(deck.begin(), deck.end(), e);
   
}

void Deck::print() {

        int topCard = 0;
        for (int i = topCard; i < 52; i++) {
            deck[i].showCard(); 
            if (((i+1) % 13) == 0) 
                std::cout << "\n";
    }
}
#endif