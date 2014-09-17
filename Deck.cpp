#include <iostream>
#include <algorithm>
#include "Deck.h"

Deck::Deck()
{
	deck = {1, 1, 1, 1,
					2, 2, 2, 2,
					3, 3, 3, 3,
					4, 4, 4, 4,
					5, 5, 5, 5,
					6, 6, 6, 6,
					7, 7, 7, 7,
					8, 8, 8, 8,
					9, 9, 9, 9,
					10, 10, 10, 10,
					10, 10, 10, 10,
					10, 10, 10, 10,
					11, 11, 11, 11};

	std::random_shuffle(deck.begin(), deck.end());
}

int Deck::draw_card()
{
	if (deck.size() > 0)
	{
		int x = deck[rand() % 52 + 1];
		deck.erase(deck.begin()+x);
		return x;
	}
	else {
		return 0;
	}
}
