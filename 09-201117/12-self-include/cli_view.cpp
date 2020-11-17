#include <iostream>
// Ensure that there is no discrepancy between declarations and definitions.
// E.g. in return types of functions.
#include "cli_view.h"

namespace cli_view {
void show_field(const field::Field &f) {
    std::cout << f.width << "x" << f.height << "\n";
}
}  // namespace cli_view

