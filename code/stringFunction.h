#ifndef _STRINGFUNCTION_
#define _STRINGFUNCTION_

#include <iostream>

namespace si {

size_t find(std::string _Value, char _Ch);

size_t find(std::string *_Value, char _Ch);

size_t find(std::string &_Value, char _Ch);

}

#endif
