#ifndef _HEADER_
#define _HEADER_

#include <vector>
#include <fstream>
#include <map>

#include "stringFunction.h"

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
  EQUAL,
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

typedef struct DataSection {
  DataSection(std::string t_value, TokenValue t_type) 
    : _Value(t_value), _Type(t_type) {}
  std::string _Value;
  TokenValue _Type;
} DataSection;

extern std::map<std::vector<TokenValue>, InstrucType> _InstrucMap;
extern std::map<std::string, TokenValue> _CommandMap;
extern std::vector<InstrucType> generateFunction;

#endif 
