#include "parser.h"
#include "header.h"
#include <algorithm>

std::vector<Instruction> parser(std::vector<Token> *_VecToken) {
  std::vector<Instruction> _Ret{};
  Instruction _Instruc{};

  for (Token &_Tk : *_VecToken) {
    switch (_Tk._TValue) {
      case SEMICOLON:
          _Instruc._VecList.push_back(SEMICOLON);
          if (_InstrucMap.contains(_Instruc._VecList)) {
            _Instruc._Type = _InstrucMap[_Instruc._VecList];
            if (!std::binary_search(generateFunction.begin(),
                                    generateFunction.end(),
                                    _InstrucMap[_Instruc._VecList])) {
              generateFunction.push_back(_InstrucMap[_Instruc._VecList]);
          }
            
            _Ret.push_back(_Instruc);
            _Instruc.clear();
          }
        break;
      default:
        _Instruc._VecList.push_back(_Tk._TValue);
        switch (_Tk._Type) {
          case LITERAL:
            _Instruc._Value.push_back(_Tk._Value);
            break;
          default: break;
        }
        break;
    }
  }

  return _Ret;
}
