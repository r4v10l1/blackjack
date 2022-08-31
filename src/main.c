#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
#include <sys/time.h>
#else
#include <time.h>
#endif

#include "lib/colors.h"
#include "defines.h"
#include "helpers.h"

// See defines.h
#ifdef USE_NCURSES
#include <locale.h>     // For ncurses and wide chars
#include "blackjack_ncurses.h"
#else
#include "blackjack.h"
#endif

int main(int argc, char** argv) {
    #ifdef USE_NCURSES
    setlocale(LC_ALL, "");      // For wide chars
    initscr();
    move(0, 0);
    refresh();
    #endif

    clear_deck(pDeck);              // Initialize it
    shuffle(pDeck);                 // Shuffle the deck

    player_t dealer;
    player_t* pDealer = &dealer;
    init_player(pDealer, 0, DEALER_MONEY);
    player_t player1;
    player_t* pPlayer1 = &player1;
    init_player(pPlayer1, 1, PLAYER_MONEY);

    // Bets
    read_bet_input(pPlayer1);

    // First deal initial cards
    deal_card(pPlayer1);
    deal_card(pDealer);
    dealer.hand[0].hidden = 1;      // First dealer card is hidden
    deal_card(pPlayer1);
    deal_card(pDealer);

    // Print player information after initial dealing
    print_player(pDealer);
    print_player(pPlayer1);

    // Ask player for deal
    int bDealing = 1;
    while (bDealing) {
        bDealing = 0;       // Reset to false, will be set to true if we need to deal

        separator();

        if (player1.hitting) user_deal_option(pPlayer1);           // Check the first time so we only ask the ones that just draw a card
        if (player1.hitting) bDealing = 1;                         // Check again because the value will change depending on the input
    }

    // Dealer card unhides and picks cards
    separator();
    dealer.hand[0].hidden = 0;
    dealer_draw(pDealer);           // Draw til thresold and print_player()
    print_player(pPlayer1);

    // Bet outcome
    compare_players(pDealer, pPlayer1);

    #ifdef USE_NCURSES
    printw("Press any key to exit...");
    refresh();
    getchar();
    endwin();
    #endif

    return 0;
}

