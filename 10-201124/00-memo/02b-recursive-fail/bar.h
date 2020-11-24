#ifndef BAR_H_
#define BAR_H_

#include "foo_fwd.h"
#include "bar_fwd.h"  // Cross-check!

struct Bar {
    Foo &parent;
};

#endif  // BAR_H_
