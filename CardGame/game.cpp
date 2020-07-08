
#include "game.h"
#include <algorithm>

void Game::StartGame()
{
	//Shuffles cards
	Game::m_deck.Shuffle(); 

	//Splits cards between both players
	cards_t cards = Game::m_deck.m_cards;
	size_t half_size = cards.size() / 2;

	cards_t split_lo(cards.begin(), cards.begin() + half_size);
	cards_t split_hi(cards.begin() + half_size, cards.end());

	Game::m_players[0].SetCards(split_lo);
	Game::m_players[1].SetCards(split_hi);
}

void Game::StartRound()
{
	Game::m_round++;
	std::cout << "Round: " << Game::m_round << std::endl;
	for (Player& player : Game::m_players)
	{
		player.SetScore();
		std::cout << player.GetName() << std::endl;
		std::cout << "Score: " << player.GetScore() << std::endl;
		std::cout << std::endl;
	}
	std::cout << std::endl;

	std::string no_purpose;
	std::cout << "Press Enter to continue";
	std::getline(std::cin, no_purpose);
	std::cout << std::endl;
}

void Game::PlayRound()
{
	cards_t p1Cards;
	cards_t p2Cards;

	//Plays top card for both players
	p1Cards.push_back(Game::m_players[0].RemoveCard());
	p2Cards.push_back(Game::m_players[1].RemoveCard());

	//Shows played card for both players
	std::cout << Game::m_players[0].GetName() << "'s card: ";
	std::cout << p1Cards[p1Cards.size() - 1] << std::endl;

	std::cout << Game::m_players[1].GetName() << "'s card: ";
	std::cout << p2Cards[p2Cards.size() - 1] << std::endl;
	
	//Plays next two cards for both players if player's cards have equal value (first card face down, second face up)
	while (p1Cards[p1Cards.size() - 1].GetValue() == p2Cards[p2Cards.size() - 1].GetValue())
	{
		std::cout << "War!" << std::endl;

		//Checks to see if either player has less than 2 cards left (War can't happen if less than 2 cards left, other player wins)
		if (Game::m_players[0].GetCards().size() < 2)
		{
			Game::m_players[1].AddCards(Game::m_players[0].GetCards());
			Game::m_players[1].AddCards(p1Cards);
			Game::m_players[1].AddCards(p2Cards);

			Game::m_players[0].RemoveAllCards();
			p1Cards.clear();

			Game::m_players[0].SetScore();
			Game::m_players[1].SetScore();
			std::cout << Game::m_players[0].GetName() << " doesn't have enough cards for war!" << std::endl;
			return;
		}
		else if (Game::m_players[1].GetCards().size() < 2)
		{
			Game::m_players[0].AddCards(Game::m_players[1].GetCards());
			Game::m_players[0].AddCards(p1Cards);
			Game::m_players[0].AddCards(p2Cards);

			Game::m_players[1].RemoveAllCards();
			p2Cards.clear();

			Game::m_players[0].SetScore();
			Game::m_players[1].SetScore();
			std::cout << Game::m_players[1].GetName() << " doesn't have enough cards for war!" << std::endl;
			return;
		}

		//Executes war if both players have 2 or more cards left
		else {
			p1Cards.push_back(Game::m_players[0].RemoveCard());
			p1Cards.push_back(Game::m_players[0].RemoveCard());

			p2Cards.push_back(Game::m_players[1].RemoveCard());
			p2Cards.push_back(Game::m_players[1].RemoveCard());

			//Shows played card for both players
			std::cout << Game::m_players[0].GetName() << "'s card: ";
			std::cout << p1Cards[p1Cards.size() - 1] << std::endl;
			std::cout << Game::m_players[1].GetName() << "'s card: ";
			std::cout << p2Cards[p2Cards.size() - 1] << std::endl;
		}
	}

	//Puts all of the played cards together and shuffles them 
	//(Simulating human error, that the played cards are rarely kept in the same order when they're put in somebody's deck)
	cards_t allPlayed;
	{
		for (Card card : p1Cards)
		{
			allPlayed.push_back(card);
		}
		for (Card card : p2Cards)
		{
			allPlayed.push_back(card);
		}
		std::random_shuffle(allPlayed.begin(), allPlayed.end());
	}

	if (p1Cards[p1Cards.size() - 1] > p2Cards[p2Cards.size() - 1] || Game::m_players[0].GetCards().size() == 52)
	{
		//If player 1 wins round, they are given all of the played cards and announced winner of round
		std::cout << Game::m_players[0].GetName() << " wins the round!" << std::endl;

		//Game::m_players[0].AddCards(p1Cards);
		//Game::m_players[0].AddCards(p2Cards);
		Game::m_players[0].AddCards(allPlayed);
	}
	else if (p1Cards[p1Cards.size() - 1] < p2Cards[p2Cards.size() - 1] || Game::m_players[1].GetCards().size() == 52)
	{
		//If player 2 wins round, they are given all of the played cards and announced winner of round
		std::cout << Game::m_players[1].GetName() << " wins the round!" << std::endl;
		
		//Game::m_players[1].AddCards(p1Cards);
		//Game::m_players[1].AddCards(p2Cards);
		Game::m_players[1].AddCards(allPlayed);
	}

	Game::m_players[0].SetScore();
	Game::m_players[1].SetScore();
	
	std::string no_purpose;
	std::cout << "Press Enter to continue";
	std::getline(std::cin, no_purpose);

	std::cout << std::endl;
}