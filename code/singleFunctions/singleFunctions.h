#ifndef _SINGLEFUNCTIONS_
#define _SINGLEFUNCTIONS_

#include <string_view>
#include "../header.h"

void printError(std::string_view _Error, int _ErrorCode = 1);
void printToken(std::vector<Token> *_VecToken);

#endif
