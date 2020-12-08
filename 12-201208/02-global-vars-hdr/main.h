#ifndef MAIN_H_
#define MAIN_H_

#include <string>  // Важно! Иначе нельзя включать "main.h", не включив <string> до этого.

extern int a;  // Типа "объявление", инициализировать нельзя.
namespace ns_for_s {
extern std::string s;  // Типа "объявление."
}

#endif  // MAIN_H_
