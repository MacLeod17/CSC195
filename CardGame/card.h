#pragma once

#include <iostream>
#include <string>
#include <vector>

class Card
{
public:
	friend class Game;
public:
	enum class Suit
	{
		Spades,
		Hearts,
		Clubs,
		Diamonds,
		Size
	};
	enum class Rank
	{
		Ace,
		Two,
		Three,
		Four,
		Five,
		Six,
		Seven,
		Eight,
		Nine,
		Ten,
		Jack,
		Queen,
		King,
		Size
	};

	using id_t = unsigned char; // (0, 0, suit, suit, rank, rank, rank, rank)

public:
	Card() {};
	Card(Rank rank, Suit suit) : m_rank{ rank }, m_suit{ suit } {};
	Card(id_t id)
	{
		m_rank = static_cast<Rank>(id & 0xf);
		m_suit = static_cast<Suit>(id >> 4);
	};

	bool operator == (const Card& other) const
	{
		return (m_rank == other.m_rank) && (m_suit == other.m_suit);
	}
	bool operator != (const Card& other) const
	{
		return (!(*this == other));
	}

	bool operator < (const Card& other) const
	{
		return (this->GetValue() < other.GetValue());
	}
	bool operator > (const Card& other) const
	{
		return (this->GetValue() > other.GetValue());
	}
	
	bool operator == (const Suit suit) const
	{
		return (this->m_suit == suit);
	}
	bool operator == (const Rank rank) const
	{
		return (this->m_rank == rank);
	}

	int GetValue() const 
	{ 
		return s_values[static_cast<int>(m_rank)]; 
	}

	friend std::ostream& operator << (std::ostream& stream, const Card& card)
	{
		stream << s_rankStrings[static_cast<int>(card.m_rank)] << " of ";
		stream << s_suitStrings[static_cast<int>(card.m_suit)];

		return stream;
	}

private:
	Suit m_suit;
	Rank m_rank;
	static const int s_values[];
	static const std::string s_rankStrings[];
	static const std::string s_suitStrings[];

};

using cards_t = std::vector<Card>;