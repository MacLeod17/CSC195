#pragma once

#include "deck.h"
#include <string>

class Player
{
public:
	Player() {}
	Player(const std::string& name) : m_name(name) {}

	void AddCard(const Card& card) 
	{ 
		m_cards.push_back(card);
	}
	void AddCards(const cards_t& cards) //Effectively a push_front() for a vector of cards
	{
		for (Card card : cards)
		{
			cards_t temp = m_cards; //Saves cards in player's hand
			m_cards.clear(); //Clears hand
			m_cards.push_back(card); //Puts card at front of hands
			for (Card tempCard : temp)
			{
				m_cards.push_back(tempCard); //Puts saved cards behind new card
			}
		}
	}
	void SetCards(const cards_t& cards) 
	{ 
		m_cards = cards; 
	}

	void SetScore()
	{
		m_score = m_cards.size();
	}

	Card RemoveCard()
	{
		Card card = m_cards[m_cards.size() - 1]; //Saves the last card (The one on top)
		m_cards.pop_back(); //Removes said card from player's stack
		return card; //Returns the card that was removed
	}
	void RemoveAllCards() 
	{ 
		m_cards.clear();
	}

	const std::string& GetName() const
	{
		return m_name;
	}

	const cards_t& GetCards() const
	{
		return m_cards;
	}

	const int& GetScore() const
	{
		return m_score;
	}

	friend std::ostream& operator << (std::ostream& stream, const Player& player)
	{
		stream << "Player: " << player.m_name << std::endl;
		for (const Card& card : player.m_cards)
		{
			stream << card << std::endl;
		}

		return stream;
	}

private:
	std::string m_name;
	cards_t m_cards;
	int m_score{ 0 };
};

