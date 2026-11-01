#include "expr.h"

#include <type_traits>

struct Widget
{
    int value() const;
};

static_assert(std::is_same<decltype(expr<Widget>().value()), int>::value, "member return type");
static_assert(std::is_same<decltype(expr<int &>()), int &>::value, "reference preservation");

int main()
{
    return 0;
}
