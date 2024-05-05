#include "singleFunctions.h"

void printError(std::string_view _Error, int _ExitCode) {
  std::cout << "Error: " << _Error << "\n";
  exit(_ExitCode);
}
