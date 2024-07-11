#include "card.h"
#include <iostream>
#include "card.h"


int main() {

  Card card2 {Suit::heart, Value::nine}; 
  Card card3 {Suit::heart, Value::ten}; 
  Card card4 {Suit::heart, Value::jack}; 
  Card card1 {Suit::club, Value::jack}; 
  Card card5 {Suit::heart, Value::queen}; 
  Card card6 {Suit::heart, Value::king}; 
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

  if (comb_hand.isFlush()) {
    std::cout << "Fucking flush" << std::endl; 
  }
  else {
    std::cout << "Fucking not flush" << std::endl; 
  }

  return 0; 
}

