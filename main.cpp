#include <iostream>
#include <ncurses.h>
#include "Deck.h"

int main() {
	WINDOW* window;
	window = initscr();

	srand((unsigned)time(NULL));

	bool close = false;
	bool win = false;

	int player_sum=0;
	int dealer_sum=0;

	bool player_turn=true;

	Deck deck;

	player_sum+=deck.draw_card();
	player_sum+=deck.draw_card();
	dealer_sum+=deck.draw_card();
	dealer_sum+=deck.draw_card();

	while (!close)
	{
		mvprintw(1, 1, "BLACK JACK");

		mvprintw(2, 1, "Dealer's Hand: ##");
		mvprintw(3, 1, "Player's Hand: %i", player_sum);
		mvprintw(4,	1, "[h]it | [s]tay");
		refresh();

		if (player_turn)
		{
			char ch = getchar();
			if (ch == 27) {close=true; endwin();}
			else if (tolower(ch) == 'h') {
				player_sum+=deck.draw_card();
			}
			else if (tolower(ch) == 's') {
				player_turn=false;
			}
		}
		else
		{
			if (dealer_sum < 17) dealer_sum+=deck.draw_card();
			else if (dealer_sum >= 17) close=true;
		}

		if (dealer_sum == 21 || player_sum == 21) close=true;
		if (dealer_sum > 21 || player_sum > 21) close=true;
	}

	clear();
	mvprintw(2, 1, "Dealer's Hand: %i", dealer_sum);
	mvprintw(3, 1, "Player's Hand: %i", player_sum);

	if (dealer_sum > 21) mvprintw(4, 1, "Dealer Bust!");
	else if (player_sum > 21) mvprintw(4, 1, "Player Bust!");
	else {
		if (dealer_sum > player_sum) mvprintw(4, 1, "You Lost!");
		else if (player_sum > dealer_sum) mvprintw(4, 1, "You Won!");
		else if (player_sum == dealer_sum) mvprintw(4, 1, "Dealer Won By Default!");
	}
	mvprintw(5, 1, "Press Any Key To Quit");
	getch();
	endwin();

  return 0;
}