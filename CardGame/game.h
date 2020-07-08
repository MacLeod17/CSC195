#pragma once

#include "deck.h"
#include "player.h"
#include <vector>

class Game
{
public:
	Game() {}

	void StartGame();
	bool IsGameOver()
	{
		//Return end game condition (One player has all 52 cards)
		for (Player player : m_players)
		{
			if (player.GetScore() == 52)
			{
				return true;
			}
		}
		return false;
	}

	const Player GetWinner() const
	{
		//Return winner
		Player winner{ "Tie!" };

		for (Player player : m_players)
		{
			if (player.GetScore() == 52)
			{
				winner = player;
			}
		}
		return winner;
	}

	Player& GetPlayer(size_t index)
	{
		return m_players[index];
	}

	void StartRound();
	void PlayRound();

	void AddPlayer(const Player& player) 
	{ 
		m_players.push_back(player); 
	}

private:
	Deck m_deck;
	std::vector<Player> m_players;
	int m_round{ 0 };
};

