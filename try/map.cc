#include <iostream>
#include <map>

std::map<int, int> _Map = {
  { 10, 1010 },
  { 15, 1111 },
};

int main() {
  
  if (_Map.contains(2)) {
    std::cout << "True\n";
  }
  if (_Map.contains(2)) {
    std::cout << "True\n";
  }
  std::cout << "10 : " << _Map[10] << "\n";

  return 0;
}
