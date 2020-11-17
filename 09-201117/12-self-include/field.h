// Alternative: '#pragma once', not in standard, but all major compilers support it.

#ifndef FIELD_H_  // Include guards
#define FIELD_H_

#include "field_fwd.h"

// Adds definitions of structs.
namespace field {
struct Field {
    int width, height;

    int area() const;
};
}  // namespace field

#endif  // FIELD_H_
