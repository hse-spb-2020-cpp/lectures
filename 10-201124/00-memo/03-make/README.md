* `make`
* Ensure it prints 10, not 10.5
* Change `foo.h` to have `double` instead of `int`
* `make` does not recompile anything; it does not know that `foo.h` is important
* Re-save `foo.cpp` to update timestamp
* `make` now recompiles `foo.o`
* `./main` yields undefined behavior because `main.o` still thinks that `Foo` has `int` field.
* Fix dependencies in `Makefile`
* `make` now recompiles everything if `foo.h` is changed
