#include <iostream>
#include "../code/stringFunction.h"

int main() {
  std::string str = "Hello World\n\n";
  size_t len = si::find(&str, '\n');
  std::cout << len;

  return 0;
}
