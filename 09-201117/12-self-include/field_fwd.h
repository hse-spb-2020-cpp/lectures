#ifndef FIELD_FWD_H
#define FIELD_FWD_H

// Declarations only: structs and functions. Increases compilation speed and reduces dependencies.
namespace field {
struct Field;
Field create_field(int width, int height);
}

#endif // FIELD_FWD_H_
