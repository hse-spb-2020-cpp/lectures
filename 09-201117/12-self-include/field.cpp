// Do not copy-paste struct definition.
#include "field.h"

namespace field {
int Field::area() const {
    return width * height;
}

Field create_field(int width, int height) {
    return {width, height};
}
}  // namespace field
