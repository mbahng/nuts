#include "rankings.h"
#include "card.h"
#include <algorithm>

CombinedHand::CombinedHand(Hand myhand, Table table) {
  for (int i = 0; i < 2; ++i) {
    hand[i] = myhand.hand[i]; 
  }
  for (int i = 0; i < 5; ++i) {
    hand[i + 2] = table.table[i]; 
  } 
  std::sort(hand.begin(), hand.end()); 
}

struct SuitComparator {
  bool operator() (const Card& card1, const Card& card2){
      if (card1.suit == card2.suit) {
        return card1.value < card2.value; 
      }
      return card1.suit < card2.suit; 
    }
}; 

bool CombinedHand::isRoyalFlush() { 
  std::sort(hand.begin(), hand.end(), SuitComparator()); 

  for (int i = 0; i < 3; ++i) {
    if ((hand[i].suit == hand[i+4].suit) && (hand[i].value == Value::ten) && (hand[i+5].value == Value::ace)) {
      return true; 
    }
  }
  return false; 
}

bool CombinedHand::isStraightFlush() {
  throw std::logic_error("Not implemented"); 
}

bool isFourOfAKind() {
  throw std::logic_error("Not implemented"); 
}

bool isFullHouse() {
  throw std::logic_error("Not implemented"); 
}

bool isFlush() {
  throw std::logic_error("Not implemented"); 
}

bool isStraight() {
  throw std::logic_error("Not implemented"); 
}

bool isThreeOfAKind() {
  throw std::logic_error("Not implemented"); 
}

bool isTwoPair() {
  throw std::logic_error("Not implemented"); 
}

bool isPair() {
  throw std::logic_error("Not implemented"); 
}

BestHand CombinedHand::get_best_hand(Hand hand) {

  throw std::logic_error("Not implemented"); 
}

