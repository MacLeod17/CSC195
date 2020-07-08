
#include "game.h"
#include "player.h"
#include "deck.h"
#include "card.h"

#include <time.h>
#include <iostream>

using namespace std;

int main()
{
    srand(static_cast<unsigned int>(time(NULL)));

    //Game Name: War
    cout << "War" << endl;
    //Game Instructions
    cout << "The goal is to be the first player to 52 cards." << endl 
        << "Both players start with 26 cards, kept face down. " << endl
        << "Each player discards one card at the same time. The player with the higher value wins and takes " << endl
        << "both cards and puts them face down at the bottom of their stack. If the values are the same it is War; " << endl
        << "each player discards one card face down and another face up. The player with the higher value between the " << endl
        << "newest cards takes all of the discarded cards. This will repeat if the turned-up cards are the same value. " << endl;
    cout << endl;

    Game game;

    for (int i = 0; i < 2; i++) //Get 2 players
    {
        string name;
        cout << "Player " << (i + 1) << endl;
        cout << "Enter Name: ";
        getline(cin, name);
        game.AddPlayer(Player{ name });
    }

    //Play game
    game.StartGame();

    while (game.IsGameOver() == false) //Play game until game is over (Somebody wins or game ends in tie, if possible)
    {
        game.StartRound();
        game.PlayRound();
    }

    cout << "The winner of the game is: " << game.GetWinner().GetName();
    
    /*
    // random seed
    srand(static_cast<unsigned int>(time(NULL)));

    // create deck and shuffle
    Deck deck;
    deck.Shuffle();
    cout << "deck count: " << deck.GetCount() << endl;

    // deal and show card
    Card card = deck.DealCard();
    cout << card << endl;
    cout << "deck count: " << deck.GetCount() << endl << endl;

    // show all cards
    for (size_t i = 0; i < deck.GetCount(); i++)
    {
        cout << deck[i] << " - ";
    }
    cout << endl << endl;

    // show cards of suit
    for (size_t i = 0; i < deck.GetCount(); i++)
    {
        if (deck.GetCard(i) == Card::Suit::Diamonds)
        {
            cout << deck.GetCard(i) << " - ";
        }
    }
    cout << endl << endl;

    // show cards of rank
    for (size_t i = 0; i < deck.GetCount(); i++)
    {
        if (deck.GetCard(i) == Card::Rank::Ace)
        {
            cout << deck.GetCard(i) << endl;
        }
    }
    cout << endl << endl;

    // create game
    Game game;

    // add players
    game.AddPlayer(Player{ "Raymond" });
    game.AddPlayer(Player{ "Steve" });

    // play game
    game.StartGame();
    game.StartRound();
    */
}
