* `#define` instead of `const` value
* `#define` instead of functions.
  * Inline functions are since C99 only and not everyone support them
  * `json_object_object_foreach` is harder to optimize because it would need pointer-to-function optimization.
