# expr Usage

`expr<T>()` provides an expression of type `T` for compile-time type deduction without constructing an object.

It is declared only and must never be called at runtime.

## Inspect a Member's Return Type

```cpp
#include "expr.h"

#include <type_traits>

struct Widget
{
    double value() const;
};

static_assert(std::is_same<decltype(expr<Widget>().value()), double>::value, "return type");
```

## Preserve References

```cpp
static_assert(std::is_same<decltype(expr<int&>()), int&>::value, "lvalue reference");
static_assert(std::is_same<decltype(expr<int>()), int&&>::value, "rvalue reference");
```

Use `expr<T>()` only in unevaluated contexts such as `decltype` and `sizeof`. The library uses the C++11 standard type transformation facilities and does not depend on the separate `rref` library.
