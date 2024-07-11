#include "card.h"
#include <iostream>
#include "card.h"
#include <cassert>

void checkRoyalFlush() {
}
void checkStraightFlush() {
}
void checkFourOfAKind() {
}
void checkFullHouse() {
}
void checkFlush() {
  Card card1 {Suit::club, Value::jack}; 
  Card card2 {Suit::heart, Value::nine}; 
  Card card3 {Suit::heart, Value::ten}; 
  Card card4 {Suit::heart, Value::jack}; 
  Card card5 {Suit::heart, Value::four}; 
  Card card6 {Suit::heart, Value::seven}; 
  Card card7 {Suit::heart, Value::ace}; 

  Hand hand {card1, card2}; 
  Table table {
    card7,
    card4, 
    card6, 
    card5, 
    card3
  }; 

  CombinedHand comb_hand {hand, table}; 

  assert(comb_hand.isFlush() && "Flush tests did not succeed. "); 
}
void checkStraight() {
  Card card1 {Suit::club, Value::jack}; 
  Card card2 {Suit::heart, Value::nine}; 
  Card card3 {Suit::heart, Value::ten}; 
  Card card4 {Suit::diamond, Value::jack}; 
  Card card5 {Suit::spade, Value::eight}; 
  Card card6 {Suit::spade, Value::seven}; 
  Card card7 {Suit::heart, Value::ace}; 

  Hand hand {card1, card2}; 
  Table table {
    card7,
    card4, 
    card6, 
    card5, 
    card3
  }; 

  CombinedHand comb_hand {hand, table}; 

  assert(comb_hand.isStraight() && "Straight tests did not succeed. "); 
}
void checkThreeOfAKind() {
  Card card1 {Suit::club, Value::jack}; 
  Card card2 {Suit::heart, Value::jack}; 
  Card card4 {Suit::diamond, Value::jack}; 
  Card card3 {Suit::heart, Value::ten}; 
  Card card5 {Suit::spade, Value::eight}; 
  Card card6 {Suit::spade, Value::seven}; 
  Card card7 {Suit::heart, Value::ace}; 

  Hand hand {card1, card2}; 
  Table table {
    card7,
    card4, 
    card6, 
    card5, 
    card3
  }; 

  CombinedHand comb_hand {hand, table}; 

  assert(comb_hand.isThreeOfAKind() && "Three of a kind tests did not succeed. "); 
}
void checkTwoPair() {
}
void checkPair() {
}
void checkHighCard() {
}


int main() {

  checkRoyalFlush(); 
  checkStraightFlush(); 
  checkFourOfAKind(); 
  checkFullHouse(); 
  checkFlush(); 
  checkStraight(); 
  checkThreeOfAKind(); 
  checkTwoPair(); 
  checkPair(); 
  checkHighCard(); 

  return 0; 
}

