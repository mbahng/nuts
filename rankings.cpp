#include "rankings.h"
#include "card.h"
#include <algorithm>
#include <optional>
#include <array>

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

struct ValueComparator {
  bool operator() (const Card& card1, const Card& card2){
      if (card1.value == card2.value) {
        return card1.suit < card2.suit; 
      }
      return card1.value < card2.value; 
    }
}; 


std::optional<BestHand> CombinedHand::isRoyalFlush() { 
  std::sort(hand.begin(), hand.end(), SuitComparator()); 

  for (int i = 0; i < 3; ++i) {
    if ((hand[i].suit == hand[i+4].suit) && (hand[i].value == Value::ten) && (hand[i+5].value == Value::ace)) {
      BestHand besthand {std::array<Card, 5> {
        hand[i], 
        hand[i+1], 
        hand[i+2], 
        hand[i+3], 
        hand[i+4]
      }, Ranking::royal_flush};
      return besthand; 
    }
  }
  return std::nullopt; 
}

std::optional<BestHand> CombinedHand::isStraightFlush() {

  throw std::logic_error("Not implemented"); 
}

std::optional<BestHand> CombinedHand::isFourOfAKind() {
  throw std::logic_error("Not implemented"); 
}

std::optional<BestHand> CombinedHand::isFullHouse() {
  throw std::logic_error("Not implemented"); 
}

std::optional<BestHand> CombinedHand::isFlush() {
  std::sort(hand.begin(), hand.end(), SuitComparator()); 

  int in_a_row = 1; 
  std::array<Card, 5> my_flush {}; 
  my_flush[4] = hand[6];

  for (int i = 5; i >= 0 ; --i) {
    if (hand[i].suit == hand[i+1].suit) {
      in_a_row++; 
      my_flush[5 - in_a_row] = hand[i];
      if (in_a_row == 5) {
        BestHand besthand {my_flush, Ranking::flush};
        printCards<5>(my_flush); 
        return besthand; 
      }
    }
    else if (hand[i].suit == hand[i+1].suit){
      continue; 
    }
    else {
      my_flush[4] = hand[i];
      in_a_row = 1; 
    }
  }
  return std::nullopt; 
}

std::optional<BestHand> CombinedHand::isStraight() {
  std::sort(hand.begin(), hand.end(), ValueComparator()); 

  int in_a_row = 1; 
  std::array<Card, 5> my_straight {}; 
  my_straight[4] = hand[6];

  for (int i = 5; i >= 0 ; --i) {
    if ((int)hand[i].value == (int)hand[i+1].value - 1) {
      in_a_row++; 
      my_straight[5 - in_a_row] = hand[i];
      if (in_a_row == 5) {
        BestHand besthand {my_straight, Ranking::straight};
        printCards<5>(my_straight); 
        return besthand; 
      }
    }
    else if (hand[i].value == hand[i+1].value){
      continue; 
    }
    else {
      my_straight[4] = hand[i];
      in_a_row = 1; 
    }
  }
  return std::nullopt; 
}

std::optional<BestHand> CombinedHand::isThreeOfAKind() {
  std::sort(hand.begin(), hand.end(), ValueComparator()); 

  int in_a_row = 1; 
  std::array<Card, 5> my_three_of_a_kind {}; 
  my_three_of_a_kind[0] = hand[6];

  for (int i = 5; i >= 0 ; --i) {
    if (hand[i].value == hand[i+1].value) {
      in_a_row++; 
      my_three_of_a_kind[in_a_row - 1] = hand[i];
      if (in_a_row == 3) {
        int j = 3;
        for (int i = 6; i >= 0; --i) {
          if (j == 5) {
            return BestHand {my_three_of_a_kind, Ranking::three_of_a_kind};
          } 
          if (hand[i].value != my_three_of_a_kind[0].value) {
            my_three_of_a_kind[j] = hand[i]; 
            j++; 
          }
        }
      }
    }
    else {
      in_a_row = 1; 
      my_three_of_a_kind[0] = hand[i];
    }
  }
  return std::nullopt; 
}

std::optional<BestHand> CombinedHand::isTwoPair() {
  throw std::logic_error("Not implemented"); 
}

std::optional<BestHand> CombinedHand::isPair() {
  throw std::logic_error("Not implemented"); 
}

BestHand CombinedHand::get_best_hand(Hand hand) {

  throw std::logic_error("Not implemented"); 
}

