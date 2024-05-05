#ifndef _HEADER_
#define _HEADER_

#include <iostream>
#include <vector>
#include <fstream>

typedef enum {
  INT,
  FLOAT,
  STRING,
  EXIT,
  PRINTF,
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
  FUNCTION,
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

typedef struct {
  std::vector<TokenValue> _Instruc;
  std::vector<std::string> _Value;
} Statement;

typedef struct {
  InstrucType _Type;
  std::vector<std::string> _Value;
} Instruction;

#endif 
