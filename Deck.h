#include <iostream>
#include <vector>

#ifndef DECK_H
#define DECK_H

class Deck
{
private:
	std::vector<int> deck;
public:
	Deck();
	~Deck()=default;

	int draw_card();

};

#endif
