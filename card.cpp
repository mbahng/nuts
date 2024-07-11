#include <iostream>
#include "card.h"

std::ostream& operator<< (std::ostream& os, const enum Suit& suit) {
  switch (suit) {
    case Suit::spade: 
      return os << "S"; 
    case Suit::heart: 
      return os << "H"; 
    case Suit::diamond: 
      return os << "D"; 
    case Suit::club: 
      return os << "C"; 
    default: 
      throw std::logic_error("Not a supported suit. "); 
  }
} 

std::ostream& operator<< (std::ostream& os, const enum Value& value) {
  switch (value) {
    case Value::ace: 
      return os << "A"; 
    case Value::two: 
      return os << "2"; 
    case Value::three: 
      return os << "3"; 
    case Value::four: 
      return os << "4"; 
    case Value::five: 
      return os << "5"; 
    case Value::six: 
      return os << "6"; 
    case Value::seven: 
      return os << "7"; 
    case Value::eight: 
      return os << "8"; 
    case Value::nine: 
      return os << "9"; 
    case Value::ten: 
      return os << "T"; 
    case Value::jack: 
      return os << "J"; 
    case Value::queen: 
      return os << "Q"; 
    case Value::king: 
      return os << "K"; 
    default: 
      throw std::logic_error("Not a supported suit. "); 
  }
} 

std::ostream& operator<< (std::ostream& os, const Card& card) {
  return os << card.value << card.suit; 
}

bool Card::operator< (const Card& other) const {
  return value < other.value; 
} 

