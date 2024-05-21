#include "singleFunctions.h"

void printInstruction(std::vector<Instruction> *_Instruc) {
  for (Instruction &value : *_Instruc) {
    switch(value._Type) {
      case __function__:
        std::cout << "Function\n";
        break;
      case __variable__:
        std::cout << "Variable\n";
        break;
      case __exit__:
        std::cout << "Exit\n";
        break;
      case __printf__:
        std::cout << "Printf\n";
        break;
      case __scanf__:
        std::cout << "Scanf\n";
        break;
      default:
        std::cout << "Error\n";
    }
  }
}
