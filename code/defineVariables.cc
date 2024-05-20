#include "header.h"

// define functions
#define __EXIT__ { EXIT, OPEN_PAREN, INT, CLOSE_PAREN, SEMICOLON }
#define __PRINTF_S__ { PRINTF, OPEN_PAREN, STRING, CLOSE_PAREN, SEMICOLON }
#define __PRINTF_D__ { PRINTF, OPEN_PAREN, INT, CLOSE_PAREN, SEMICOLON }
#define __SCANF__ { SCANF, OPEN_PAREN, VARIABLE, CLOSE_PAREN, SEMICOLON }

std::map<std::vector<TokenValue>, InstrucType> _InstrucMap {
  { __EXIT__, __exit__ },
  { __PRINTF_S__, __printf__ },
  { __PRINTF_D__, __printf__ },
  { __SCANF__, __scanf__ },
};

std::vector<InstrucType> generateFunction{}; 

void Instruction::clear() {
  this->_Type = __EMPTY__;
  this->_Value.clear();
  this->_VecList.clear();
}

