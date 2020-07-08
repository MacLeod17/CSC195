
#include "deck.h"
#include <algorithm> //(so random_shuffle can be used)

Deck::Deck()
{
    // add all 52 cards of the deck
    //< for loop Card::id_t i = 0; i < static_cast<>(Card::Suit::Size) >
        //< for loop Card::id_t j = 0; j < static_cast<>(Card::Rank::Size) >
            //< push back onto m_cards Card{ i << 4 | j } >
    for (Card::id_t i = 0; i < static_cast<Card::id_t>(Card::Suit::Size); i++)
    {
        for (Card::id_t j = 0; j < static_cast<Card::id_t>(Card::Rank::Size); j++)
        {
            Deck::m_cards.push_back(Card{ static_cast<Card::id_t>(i << 4 | j) });
        }
    }

}

void Deck::Shuffle()
{
    std::random_shuffle(Deck::m_cards.begin(), Deck::m_cards.end());
}

Card Deck::DealCard()
{
    assert(!(Deck::m_cards.empty()));

    Card card = Deck::m_cards.back(); // < get the back card of m_cards >
    Deck::m_cards.pop_back();

    return card;
}
