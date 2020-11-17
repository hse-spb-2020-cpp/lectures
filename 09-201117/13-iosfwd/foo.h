#ifndef FOO_H_
#define FOO_H_

//#include <iostream>  // Slow compilation
#if 0  // Undefined behavior.
namespace std {  
    struct ostream;  // Also, ostream is actually a template alias.
};
#endif

#include <iosfwd>  // Forward-declarations from <iostream>, faster compilation.
                   // Careful: not everyone knows about it.

struct Foo {};
std::ostream& operator<<(std::ostream&, const Foo&);

#endif // FOO_H_
