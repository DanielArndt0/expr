#pragma once

#include <type_traits>

template <typename T>
typename std::add_rvalue_reference<T>::type expr() noexcept;
