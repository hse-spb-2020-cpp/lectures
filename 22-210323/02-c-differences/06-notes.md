Lots of compiler-specific stuff:

https://gcc.gnu.org/onlinedocs/gcc-10.2.0/gcc/#toc-Extensions-to-the-C-Language-Family

* Nested functions in C
* `__attribute__((constructor))`
* https://gcc.gnu.org/onlinedocs/gcc-10.2.0/gcc/Pointer-Arith.html#Pointer-Arith

Lots of macros. Lots. Lots.
E.g. `json_object_object_foreach`: https://github.com/json-c/json-c/blob/041cef434afe0d0c6da8b6ac1d1fa26087246dda/json_object.h#L473-L505
Inline functions are only supported by C99, and not all compilers.
Not all compilers are able to include pointer-to-function call.

