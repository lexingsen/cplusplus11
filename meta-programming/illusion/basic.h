#pragma once
#include <type_traits>


namespace lsc {
    template <int x>
    struct number {using value = number<x>; constexpr static int instance = x;};

    template <bool x>
    struct boolean {using value = boolean<x>; constexpr static bool instance = x;};

    /*
    为什么要用number和boolean来使用int和bool,而不直接去使用他的字面量？
    答：是因为在模板元编程中，所有用到的值，包括函数参数，函数返回值，都必须是class，而int和bool是不能够作为template typename的参数的

    函数和函数的结果是两个概念
    */

    template <typename a, typename b>
    struct add {using value = number<a::value::instance + b::value::instance>;};

    template <typename x> 
    struct test {using value = typename x::p;};

    struct a{};
}