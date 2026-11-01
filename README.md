# expr

A lightweight, header-only utility for unevaluated C++11 expressions.

expr allows type inspection with decltype without constructing an object.

## Requirements

- C++11 or later
- CMake 3.16 or later for CMake integration

## Usage

```cpp
#include "expr.h"

struct Widget { int value() const; };

using Result = decltype(expr<Widget>().value());
```

For more examples and API documentation, see [Usage Documentation](docs/usage.md).

## Manual Integration

Download [expr.h](https://github.com/DanielArndt0/expr/blob/main/include/expr.h) from the repository and add it to your project's include directory.

Include the header using `#include "expr.h"`. No separate compilation is required.

## CMake Integration

expr can be integrated directly from GitHub using CMake's `FetchContent` module.

Add the following to your project's `CMakeLists.txt`:

```cmake
include(FetchContent)

FetchContent_Declare(
    expr
    GIT_REPOSITORY https://github.com/DanielArndt0/expr.git
    GIT_TAG v1.0.0
)

FetchContent_MakeAvailable(expr)

target_link_libraries(my_target PRIVATE expr::expr)
```

Replace `my_target` with your application's CMake target.

If you already have the expr source directory inside your CMake project, you can add it instead:

```cmake
add_subdirectory(path/to/expr)
target_link_libraries(my_target PRIVATE expr::expr)
```

expr is header-only and does not require a separately compiled binary.

## Compatibility

expr requires C++11 or later and uses the standard <type_traits> header. It must only be used in unevaluated contexts.

## Disclaimer

expr is developed for educational purposes and experimentation with type deduction. It is not intended to replace std::declval.
