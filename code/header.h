#ifndef _HEADER_
#define _HEADER_

#include <iostream>
#include <vector>
#include <fstream>
#include <map>

typedef enum {
  INT,
  FLOAT,
  STRING,
  EXIT,
  PRINTF,
  SCANF,
  VARIABLE,
  OPEN_PAREN,
  CLOSE_PAREN,
  SEMICOLON,
} TokenValue;

typedef enum {
  LITERAL,
  KEYWORD,
  SEPARATOR,
} TokenType;

typedef enum {
  __function__,
  __variable__,
  __exit__,
  __printf__,
  __scanf__,
  __EMPTY__,
} InstrucType;

typedef struct Token {
public:
  TokenType _Type;
  TokenValue _TValue;
  std::string _Value;

public:
  Token() = default;
  Token(TokenType t_type) : _Type(t_type) {}
  Token(TokenType t_type, TokenValue t_tvalue) : _Type(t_type), _TValue(t_tvalue) {}
} Token;

typedef struct Instruction {
  void clear();
  std::vector<TokenValue> _VecList;
  InstrucType _Type;
  std::vector<std::string> _Value;
} Instruction;

extern std::map<std::vector<TokenValue>, InstrucType> _InstrucMap;

#endif 
