#include "parser.h"

std::vector<Instruction> parser(std::vector<Token> *_VecToken) {
  std::vector<Instruction> _Ret{};
  Instruction _Instruc{};
  Statement _Statement{};

  for (Token &_Tk : *_VecToken) {
    switch (_Tk._TValue) {
      case SEPARATOR:
        break;
      default:
        _Statement._Instruc.push_back(_Tk._TValue);
        switch (_Tk._Type) {
          case LITERAL:
            _Statement._Value.push_back(_Tk._Value);
            break;
          default: break;
        }
        break;
    }
  }

  return _Ret;
}
