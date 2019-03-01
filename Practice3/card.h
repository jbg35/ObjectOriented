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

class Card {
private:
	unsigned char byte;

public:
	Card();
	~Card(){}

	Card(int i, int j) {
		byte = suit(i);
		byte = rank(j);
	}

	unsigned char rank(int j) {
	switch(j) {
		case 1: return 0b00000000;  // ACE
		case 2: return 0b00000001;  // 2
		case 3: return 0b00000010;  // 3
		case 4: return 0b00000011;  // 4 
		case 5: return 0b00000100;  // 5
		case 6: return 0b00000101;  // 6
		case 7: return 0b00000110;  // 7
		case 8: return 0b00000111;  // 8
		case 9: return 0b00001000;  // 9
		case 10: return 0b00001001; // 10
		case 11: return 0b00001010; // Jack
		case 12: return 0b00001011; // Queen
		case 13: return 0b00001100; // King
	}
}
	unsigned char suit(int i) {
		unsigned char bytetest = this->byte;
	switch(i) {
		case 1: return bytetest&00000000; // SPADES
		case 2: return bytetest&00010000; // HEARTS
		case 3: return bytetest&00100000; // CLUBS
		case 4: return bytetest&00110000; // DIAMONDS
	}
}
	//SUIT getSuit() { return suit; }
	//RANK getRank() { return rank; }

};





inline std::ostream & operator<<(std::ostream & os, byte) {
	switch(byte&00110000 >> 4) {
		case 00: return os << "H";
    	case 01: return os << "D";
    	case 10: return os << "C";
		case 11: return os << "S";
	}
	return os; // !!Questionable, added to remove warning
}

inline std::ostream & operator<<(std::ostream & os, byte){   
    switch(byte&00001111) {
    case 1: return os << "A";  // ACE
	case 2: return os << "2"; // 2
	case 3: return os << "3";  // 3
	case 4: return os << "4";  // 4 
	case 5: return os << "5";  // 5
	case 6: return os << "6";  // 6
	case 7: return os << "7"; // 7
	case 8: return os << "8"; // 8
	case 9: return os << "9";  // 9
	case 10: return os << "T"; // 10
	case 11: return os << "J"; // Jack
	case 12: return os << "Q";// Queen
	case 13: return os << "K"; // King
    }
    return os; // !!Questionable, added to remove warning
}