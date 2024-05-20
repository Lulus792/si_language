#include "lexer.h"
#include "parser.h"
#include "generateCode.h"

int main(int argc, char **argv) {

  if (argc < 2) {
    printError("Wrong syntax. Correct syntax: compiler <file.si>");
  }


  std::ifstream file(argv[1]);
  std::vector<Token> _Code = lexer(&file);
  std::vector<Instruction> _Instructions = parser(&_Code);

  std::string flags{};
  if (argc == 3) {
    unsigned int i{};
    while (argv[2][i] != '\0') {
      flags += argv[2][i];
      i++;
    } 
  }
  generateCode(&_Instructions, argv[1], flags);

  file.close();

  return 0;
}
