#include "lexer.h"
#include "parser.h"
#include "singleFunctions/singleFunctions.h"

int main(int argc, char **argv) {

  if (argc < 2) {
    printError("Wrong syntax. Correct syntax: compiler <file.si>");
  }

  std::ifstream file(argv[1]);
  std::vector<Token> _Code = lexer(&file);
  std::vector<Instruction> _Instructions = parser(&_Code);

  file.close();

  return 0;
}
