#include <iostream>


namespace lsc {
    template <typename ...Ts>
    struct TypeList {
        using type = TypeList<Ts...>;
        constexpr static size_t size = sizeof...(Ts);

        template <typename ...T>
        using append = TypeList<Ts..., T...>;
    };


    template <typename T, T v>
    struct integral_constant {
        constexpr static T value = v;
    };


    

    using false_type = integral_constant<bool, false>;
    using true_type = integral_constant<bool, true>;

    using boolSet = TypeList<false_type, true_type>;
}


int main() {
    lsc::boolSet::type a;
    lsc::TypeList<int, char>::append<long, double>::type b;
}


