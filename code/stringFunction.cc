#include "stringFunction.h"

namespace si {

size_t find(std::string _Value, char _Ch) {
  size_t count{};
  for (char &c : _Value) {
    if (_Ch == c) {
      count++;
    } 
  }
  return count;
}

size_t find(std::string *_Value, char _Ch) {
  size_t count{};
  for (char &c : *_Value) {
    if (_Ch == c) {
      count++;
    } 
  } 
  return count; 
}

size_t find(std::string &_Value, char _Ch) {
  size_t count{};
  for (char &c : _Value) {
    if (_Ch == c) {
      count++;
    } 
  } 
  return count; 
}

}
