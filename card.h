#pragma once 
#include <iostream>
#include <array>
#include <optional>

enum Suit {
  club, 
  diamond, 
  heart, 
  spade
}; 

enum class Value:int {
  two = 2, 
  three = 3, 
  four = 4, 
  five = 5, 
  six = 6, 
  seven = 7, 
  eight = 8, 
  nine = 9, 
  ten = 10, 
  jack = 11, 
  queen = 12, 
  king = 13, 
  ace = 14
}; 

enum Ranking {
  high_card, 
  pair, 
  two_pair, 
  three_of_a_kind, 
  straight, 
  flush, 
  full_house, 
  four_of_a_kind, 
  straight_flush, 
  royal_flush
}; 

class Card {
  public: 
    enum Suit suit; 
    enum Value value; 

  bool operator< (const Card& other) const; 
}; 

class Hand {
  public: 
    std::array<Card, 2> hand; 
}; 

class BestHand {
  public: 
    std::array<Card, 5> hand; 
    Ranking ranking; 
}; 

class Table {
  public: 
    std::array<Card, 5> table; 
}; 

class CombinedHand {

  public: 
    std::array<Card, 7> hand; 

  CombinedHand(Hand hand, Table table);  
  BestHand get_best_hand(Hand hand); 

  std::optional<BestHand> isRoyalFlush(); 
  std::optional<BestHand> isStraightFlush(); 
  std::optional<BestHand> isFourOfAKind(); 
  std::optional<BestHand> isFullHouse(); 
  std::optional<BestHand> isFlush(); 
  std::optional<BestHand> isStraight(); 
  std::optional<BestHand> isThreeOfAKind(); 
  std::optional<BestHand> isTwoPair(); 
  std::optional<BestHand> isPair(); 
}; 

std::ostream& operator<< (std::ostream& os, const enum Suit& suit); 
std::ostream& operator<< (std::ostream& os, const enum Value& value); 
std::ostream& operator<< (std::ostream& os, const Card& card); 

template <int i>
void printCards(std::array<Card, i> cards) {
  for (int j = 0; j < i; ++j) {
    std::cout << cards[j] << " , "; 
  }
  std::cout << '\n'; 
}

