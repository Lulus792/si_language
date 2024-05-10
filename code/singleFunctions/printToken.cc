#include "singleFunctions.h"

void printToken(std::vector<Token> *_VecToken) {
  for (Token _Val : *_VecToken) {
    switch(_Val._TValue) {
      case SEMICOLON:
        std::cout << "SEMICOLON\n";
        break;
      case OPEN_PAREN:
        std::cout << "OPEN_PAREN\n";
        break;
      case CLOSE_PAREN:
        std::cout << "CLOSE_PAREN\n";
        break;
      case INT:
        std::cout << "INT : " << _Val._Value << "\n";
        break;
      case STRING:
        std::cout << "STRING : " << _Val._Value << "\n";
        break;
      case FLOAT:
        std::cout << "FLOAT : " << _Val._Value << "\n";
        break;
      case EXIT:
        std::cout << "EXIT\n";
        break;
      case PRINTF:
        std::cout << "PRINTF\n";
        break;
      case VARIABLE:
        std::cout << "VARIABLE : " << _Val._Value << "\n";
        break;
      case SCANF:
        std::cout << "SCANF\n";
        break;
    }
  }
}
