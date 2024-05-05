#include "lexer.h"
#include "singleFunctions/singleFunctions.h"

Token getNumber(std::string *_Line, size_t *_Index) {
  Token _Ret(LITERAL);
  std::string _Number{};
  do {
    _Number += (*_Line)[*_Index];
    (*_Index)++;
  } 
  while (*_Index < _Line->size() && (isdigit((*_Line)[*_Index]) || 
  (*_Line)[*_Index] == '.'));

  size_t countDots = _Number.rfind('.');
  if (countDots == std::string::npos) {
    _Ret._TValue = INT;
  }
  else if (countDots == 1) {
    _Ret._TValue = FLOAT;
  }
  else {
    printError("Not a valid Number.");
  }
  _Ret._Value = _Number;

  return _Ret;
}

Token getCommand(std::string *_Line, size_t *_Index) {
  Token _Ret(KEYWORD);
  std::string _Command{};

  do {
    _Command += (*_Line)[*_Index];
    (*_Index)++;
  }
  while (*_Index < _Line->size() && isalpha((*_Line)[*_Index]));
  
  if (_Command == "exit") {
    _Ret._TValue = EXIT;
  }
  else if (_Command == "printf") {
    _Ret._TValue = PRINTF;
  }
  else {
    _Ret._TValue = VARIABLE;
    _Ret._Value = _Command;
  }

  return _Ret;
}

Token getSeparator(std::string *_Line, size_t *_Index) {
  Token _Ret(SEPARATOR);

  switch ((*_Line)[*_Index]) {
    case '(':
      _Ret._TValue = OPEN_PAREN;
      break;
    case ')':
      _Ret._TValue = CLOSE_PAREN;
      break;
    case ';':
      _Ret._TValue = SEMICOLON;
      break;
    default:
      printError("Not a Separator.");
      break;
  }

  return _Ret;
}

Token getString(std::string *_Line, size_t *_Index) {
  (*_Index)++;
  Token _Ret(LITERAL, STRING);
  std::string _String{};
  
  while (*_Index < _Line->size() && (*_Line)[*_Index] != '\"') {
    _String += (*_Line)[*_Index];
    (*_Index)++;
  }
  if (*_Index == _Line->size()) {
    printError("Missing Quotation mark.");
  }

  _Ret._Value = _String;
  return _Ret;
}

std::vector<Token> lexer(std::istream *_File) {
  std::vector<Token> _Ret{};
  std::string _Line{};

  while (getline(*_File, _Line)) {
    for (size_t i{}; i < _Line.size(); i++) {
      if (isdigit(_Line[i])) {
        _Ret.push_back(getNumber(&_Line, &i));
        i--;
      }
      else if (isalpha(_Line[i])) {
        _Ret.push_back(getCommand(&_Line, &i));
        i--;
      }
      else if (_Line[i] == '\"') {
        _Ret.push_back(getString(&_Line, &i));
      }
      else {
          _Ret.push_back(getSeparator(&_Line, &i));
      }
    }
  }  

  return _Ret;
}
