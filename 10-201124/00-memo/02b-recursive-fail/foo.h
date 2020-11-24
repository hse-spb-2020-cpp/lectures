#ifndef FOO_H_
#define FOO_H_

#include "bar.h"
#include "foo_fwd.h"  // Cross-check!

struct Foo {
    Bar b = {*this};
};

#endif  // FOO_H_
