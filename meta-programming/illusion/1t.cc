namespace std {
    typedef unsigned long size_t;
    typedef long ptrdiff_t;
    typedef decltype(nullptr) nullptr_t;
}
namespace std {
    inline namespace __cxx11 {
    }
}
namespace __gnu_cxx {
    inline namespace __cxx11 {
    }
}
namespace std {
    typedef unsigned short uint_least16_t;
    typedef unsigned int uint_least32_t;
}
namespace std {
    template <typename _Tp, _Tp __v> struct integral_constant {
        static constexpr _Tp value = __v;
        typedef _Tp value_type;
        typedef integral_constant<_Tp, __v> type;
        constexpr operator value_type() const noexcept         {
            return value;
        }
        constexpr std::integral_constant::value_type operator()() const noexcept         {
            return value;
        }
    };
template<> struct integral_constant<bool, true> {
        static constexpr bool value = true;
        typedef bool value_type;
        typedef integral_constant<bool, true> type;
        constexpr operator value_type() const noexcept;
        constexpr std::integral_constant<bool, true>::value_type operator()() const noexcept;
    };
template<> struct integral_constant<bool, false> {
        static constexpr bool value = false;
        typedef bool value_type;
        typedef integral_constant<bool, false> type;
        constexpr operator value_type() const noexcept;
        constexpr std::integral_constant<bool, false>::value_type operator()() const noexcept;
    };
template<> struct integral_constant<unsigned long, 0> {
        static constexpr unsigned long value = 0UL;
        typedef unsigned long value_type;
        typedef integral_constant<unsigned long, 0UL> type;
        constexpr operator value_type() const noexcept;
        constexpr std::integral_constant<unsigned long, 0>::value_type operator()() const noexcept;
    };
    constexpr _Tp value;
    typedef integral_constant<bool, true> true_type;
    typedef integral_constant<bool, false> false_type;
    template <bool __v> using __bool_constant = integral_constant<bool, __v>;
    template <bool, typename , typename > struct conditional;
    template <typename ...> struct __or_;
    template<> struct __or_<<>> : public std::false_type {
    };
    template <typename _B1> struct __or_<<type-parameter-0-0>> : public _B1 {
    };
    template <typename _B1, typename _B2> struct __or_<<type-parameter-0-0, type-parameter-0-1>> : public conditional<_B1::value, _B1, _B2>::type {
    };
    template <typename _B1, typename _B2, typename _B3, typename ..._Bn> struct __or_<<type-parameter-0-0, type-parameter-0-1, type-parameter-0-2, type-parameter-0-3...>> : public conditional<_B1::value, _B1, __or_<_B2, _B3, _Bn...> >::type {
    };
    template <typename ...> struct __and_;
    template<> struct __and_<<>> : public std::true_type {
    };
    template <typename _B1> struct __and_<<type-parameter-0-0>> : public _B1 {
    };
    template <typename _B1, typename _B2> struct __and_<<type-parameter-0-0, type-parameter-0-1>> : public conditional<_B1::value, _B2, _B1>::type {
    };
    template <typename _B1, typename _B2, typename _B3, typename ..._Bn> struct __and_<<type-parameter-0-0, type-parameter-0-1, type-parameter-0-2, type-parameter-0-3...>> : public conditional<_B1::value, __and_<_B2, _B3, _Bn...>, _B1>::type {
    };
    template <typename _Pp> struct __not_ : public __bool_constant<!bool(_Pp::value)> {
    };
    template <typename _Tp> struct __success_type {
        typedef _Tp type;
    };
    struct __failure_type {
    };
    template <typename > struct remove_cv;
    template <typename > struct __is_void_helper : public std::false_type {
    };
    template<> struct __is_void_helper<void> : public std::true_type {
    };
    template <typename _Tp> struct is_void : public __is_void_helper<typename remove_cv<_Tp>::type>::type {
    };
    template <typename > struct __is_integral_helper : public std::false_type {
    };
    template<> struct __is_integral_helper<bool> : public std::true_type {
    };
    template<> struct __is_integral_helper<char> : public std::true_type {
    };
    template<> struct __is_integral_helper<signed char> : public std::true_type {
    };
    template<> struct __is_integral_helper<unsigned char> : public std::true_type {
    };
    template<> struct __is_integral_helper<wchar_t> : public std::true_type {
    };
    template<> struct __is_integral_helper<char16_t> : public std::true_type {
    };
    template<> struct __is_integral_helper<char32_t> : public std::true_type {
    };
    template<> struct __is_integral_helper<short> : public std::true_type {
    };
    template<> struct __is_integral_helper<unsigned short> : public std::true_type {
    };
    template<> struct __is_integral_helper<int> : public std::true_type {
    };
    template<> struct __is_integral_helper<unsigned int> : public std::true_type {
    };
    template<> struct __is_integral_helper<long> : public std::true_type {
    };
    template<> struct __is_integral_helper<unsigned long> : public std::true_type {
    };
    template<> struct __is_integral_helper<long long> : public std::true_type {
    };
    template<> struct __is_integral_helper<unsigned long long> : public std::true_type {
    };
    template<> struct __is_integral_helper<__int128> : public std::true_type {
    };
    template<> struct __is_integral_helper<unsigned __int128> : public std::true_type {
    };
    template <typename _Tp> struct is_integral : public __is_integral_helper<typename remove_cv<_Tp>::type>::type {
    };
    template <typename > struct __is_floating_point_helper : public std::false_type {
    };
    template<> struct __is_floating_point_helper<float> : public std::true_type {
    };
    template<> struct __is_floating_point_helper<double> : public std::true_type {
    };
    template<> struct __is_floating_point_helper<long double> : public std::true_type {
    };
    template<> struct __is_floating_point_helper<__float128> : public std::true_type {
    };
    template <typename _Tp> struct is_floating_point : public __is_floating_point_helper<typename remove_cv<_Tp>::type>::type {
    };
    template <typename > struct is_array : public std::false_type {
    };
    template <typename _Tp, std::size_t _Size> struct is_array<type-parameter-0-0 [_Size]> : public std::true_type {
    };
    template <typename _Tp> struct is_array<type-parameter-0-0 []> : public std::true_type {
    };
    template <typename > struct __is_pointer_helper : public std::false_type {
    };
    template <typename _Tp> struct __is_pointer_helper<type-parameter-0-0 *> : public std::true_type {
    };
    template <typename _Tp> struct is_pointer : public __is_pointer_helper<typename remove_cv<_Tp>::type>::type {
    };
    template <typename > struct is_lvalue_reference : public std::false_type {
    };
    template <typename _Tp> struct is_lvalue_reference<type-parameter-0-0 &> : public std::true_type {
    };
    template <typename > struct is_rvalue_reference : public std::false_type {
    };
    template <typename _Tp> struct is_rvalue_reference<type-parameter-0-0 &&> : public std::true_type {
    };
    template <typename > struct is_function;
    template <typename > struct __is_member_object_pointer_helper : public std::false_type {
    };
    template <typename _Tp, typename _Cp> struct __is_member_object_pointer_helper<type-parameter-0-0 type-parameter-0-1::*> : public integral_constant<bool, !is_function<_Tp>::value> {
    };
    template <typename _Tp> struct is_member_object_pointer : public __is_member_object_pointer_helper<typename remove_cv<_Tp>::type>::type {
    };
    template <typename > struct __is_member_function_pointer_helper : public std::false_type {
    };
    template <typename _Tp, typename _Cp> struct __is_member_function_pointer_helper<type-parameter-0-0 type-parameter-0-1::*> : public integral_constant<bool, is_function<_Tp>::value> {
    };
    template <typename _Tp> struct is_member_function_pointer : public __is_member_function_pointer_helper<typename remove_cv<_Tp>::type>::type {
    };
    template <typename _Tp> struct is_enum : public integral_constant<bool, __is_enum(_Tp)> {
    };
    template <typename _Tp> struct is_union : public integral_constant<bool, __is_union(_Tp)> {
    };
    template <typename _Tp> struct is_class : public integral_constant<bool, __is_class(_Tp)> {
    };
    template <typename > struct is_function : public std::false_type {
    };
    template <typename _Res, typename ..._ArgTypes> struct is_function<type-parameter-0-0 (type-parameter-0-1...)> : public std::true_type {
    };
    template <typename _Res, typename ..._ArgTypes> struct is_function<type-parameter-0-0 (type-parameter-0-1...) &> : public std::true_type {
    };
    template <typename _Res, typename ..._ArgTypes> struct is_function<type-parameter-0-0 (type-parameter-0-1...) &&> : public std::true_type {
    };
    template <typename _Res, typename ..._ArgTypes> struct is_function<type-parameter-0-0 (type-parameter-0-1..., ...)> : public std::true_type {
    };
    template <typename _Res, typename ..._ArgTypes> struct is_function<type-parameter-0-0 (type-parameter-0-1..., ...) &> : public std::true_type {
    };
    template <typename _Res, typename ..._ArgTypes> struct is_function<type-parameter-0-0 (type-parameter-0-1..., ...) &&> : public std::true_type {
    };
    template <typename _Res, typename ..._ArgTypes> struct is_function<type-parameter-0-0 (type-parameter-0-1...) const> : public std::true_type {
    };
    template <typename _Res, typename ..._ArgTypes> struct is_function<type-parameter-0-0 (type-parameter-0-1...) const &> : public std::true_type {
    };
    template <typename _Res, typename ..._ArgTypes> struct is_function<type-parameter-0-0 (type-parameter-0-1...) const &&> : public std::true_type {
    };
    template <typename _Res, typename ..._ArgTypes> struct is_function<type-parameter-0-0 (type-parameter-0-1..., ...) const> : public std::true_type {
    };
    template <typename _Res, typename ..._ArgTypes> struct is_function<type-parameter-0-0 (type-parameter-0-1..., ...) const &> : public std::true_type {
    };
    template <typename _Res, typename ..._ArgTypes> struct is_function<type-parameter-0-0 (type-parameter-0-1..., ...) const &&> : public std::true_type {
    };
    template <typename _Res, typename ..._ArgTypes> struct is_function<type-parameter-0-0 (type-parameter-0-1...) volatile> : public std::true_type {
    };
    template <typename _Res, typename ..._ArgTypes> struct is_function<type-parameter-0-0 (type-parameter-0-1...) volatile &> : public std::true_type {
    };
    template <typename _Res, typename ..._ArgTypes> struct is_function<type-parameter-0-0 (type-parameter-0-1...) volatile &&> : public std::true_type {
    };
    template <typename _Res, typename ..._ArgTypes> struct is_function<type-parameter-0-0 (type-parameter-0-1..., ...) volatile> : public std::true_type {
    };
    template <typename _Res, typename ..._ArgTypes> struct is_function<type-parameter-0-0 (type-parameter-0-1..., ...) volatile &> : public std::true_type {
    };
    template <typename _Res, typename ..._ArgTypes> struct is_function<type-parameter-0-0 (type-parameter-0-1..., ...) volatile &&> : public std::true_type {
    };
    template <typename _Res, typename ..._ArgTypes> struct is_function<type-parameter-0-0 (type-parameter-0-1...) const volatile> : public std::true_type {
    };
    template <typename _Res, typename ..._ArgTypes> struct is_function<type-parameter-0-0 (type-parameter-0-1...) const volatile &> : public std::true_type {
    };
    template <typename _Res, typename ..._ArgTypes> struct is_function<type-parameter-0-0 (type-parameter-0-1...) const volatile &&> : public std::true_type {
    };
    template <typename _Res, typename ..._ArgTypes> struct is_function<type-parameter-0-0 (type-parameter-0-1..., ...) const volatile> : public std::true_type {
    };
    template <typename _Res, typename ..._ArgTypes> struct is_function<type-parameter-0-0 (type-parameter-0-1..., ...) const volatile &> : public std::true_type {
    };
    template <typename _Res, typename ..._ArgTypes> struct is_function<type-parameter-0-0 (type-parameter-0-1..., ...) const volatile &&> : public std::true_type {
    };
    template <typename > struct __is_null_pointer_helper : public std::false_type {
    };
    template<> struct __is_null_pointer_helper<nullptr_t> : public std::true_type {
    };
    template <typename _Tp> struct is_null_pointer : public __is_null_pointer_helper<typename remove_cv<_Tp>::type>::type {
    };
    template <typename _Tp> struct __is_nullptr_t : public is_null_pointer<_Tp> {
    };
    template <typename _Tp> struct is_reference : public __or_<is_lvalue_reference<_Tp>, is_rvalue_reference<_Tp> >::type {
    };
    template <typename _Tp> struct is_arithmetic : public __or_<is_integral<_Tp>, is_floating_point<_Tp> >::type {
    };
    template <typename _Tp> struct is_fundamental : public __or_<is_arithmetic<_Tp>, is_void<_Tp>, is_null_pointer<_Tp> >::type {
    };
    template <typename _Tp> struct is_object : public __not_<__or_<is_function<_Tp>, is_reference<_Tp>, is_void<_Tp> > >::type {
    };
    template <typename > struct is_member_pointer;
    template <typename _Tp> struct is_scalar : public __or_<is_arithmetic<_Tp>, is_enum<_Tp>, is_pointer<_Tp>, is_member_pointer<_Tp>, is_null_pointer<_Tp> >::type {
    };
    template <typename _Tp> struct is_compound : public integral_constant<bool, !is_fundamental<_Tp>::value> {
    };
    template <typename _Tp> struct __is_member_pointer_helper : public std::false_type {
    };
    template <typename _Tp, typename _Cp> struct __is_member_pointer_helper<type-parameter-0-0 type-parameter-0-1::*> : public std::true_type {
    };
    template <typename _Tp> struct is_member_pointer : public __is_member_pointer_helper<typename remove_cv<_Tp>::type>::type {
    };
    template <typename _Tp> struct __is_referenceable : public __or_<is_object<_Tp>, is_reference<_Tp> >::type {
    };
    template <typename _Res, typename ..._Args> struct __is_referenceable<type-parameter-0-0 (type-parameter-0-1...)> : public std::true_type {
    };
    template <typename _Res, typename ..._Args> struct __is_referenceable<type-parameter-0-0 (type-parameter-0-1..., ...)> : public std::true_type {
    };
    template <typename > struct is_const : public std::false_type {
    };
    template <typename _Tp> struct is_const<_Tp> : public std::true_type {
    };
    template <typename > struct is_volatile : public std::false_type {
    };
    template <typename _Tp> struct is_volatile<_Tp> : public std::true_type {
    };
    template <typename _Tp> struct is_trivial : public integral_constant<bool, __is_trivial(_Tp)> {
    };
    template <typename _Tp> struct is_trivially_copyable : public integral_constant<bool, __is_trivially_copyable(_Tp)> {
    };
    template <typename _Tp> struct is_standard_layout : public integral_constant<bool, __is_standard_layout(_Tp)> {
    };
    template <typename _Tp> struct is_pod : public integral_constant<bool, __is_pod(_Tp)> {
    };
    template <typename _Tp> struct is_literal_type : public integral_constant<bool, __is_literal(_Tp)> {
    };
    template <typename _Tp> struct is_empty : public integral_constant<bool, __is_empty(_Tp)> {
    };
    template <typename _Tp> struct is_polymorphic : public integral_constant<bool, __is_polymorphic(_Tp)> {
    };
    template <typename _Tp> struct is_final : public integral_constant<bool, __is_final(_Tp)> {
    };
    template <typename _Tp> struct is_abstract : public integral_constant<bool, __is_abstract(_Tp)> {
    };
    template <typename _Tp, bool = is_arithmetic<_Tp>::value> struct __is_signed_helper : public std::false_type {
    };
    template <typename _Tp> struct __is_signed_helper<_Tp, true> : public integral_constant<bool, _Tp(-1) < _Tp(0)> {
    };
    template <typename _Tp> struct is_signed : public __is_signed_helper<_Tp>::type {
    };
    template <typename _Tp> struct is_unsigned : public __and_<is_arithmetic<_Tp>, __not_<is_signed<_Tp> > > {
    };
    template <typename > struct add_rvalue_reference;
    template <typename _Tp> typename add_rvalue_reference<_Tp>::type declval() noexcept;
    template <typename , unsigned int = 0> struct extent;
    template <typename > struct remove_all_extents;
    template <typename _Tp> struct __is_array_known_bounds : public integral_constant<bool, (extent<_Tp>::value > 0)> {
    };
    template <typename _Tp> struct __is_array_unknown_bounds : public __and_<is_array<_Tp>, __not_<extent<_Tp> > > {
    };
    struct __do_is_destructible_impl {
        template <typename _Tp, typename  = decltype(declval<_Tp &>().~_Tp())> static std::true_type __test(int);
        template <typename > static std::false_type __test(...);
    };
    template <typename _Tp> struct __is_destructible_impl : public std::__do_is_destructible_impl {
        typedef decltype(__test<_Tp>(0)) type;
    };
    template <typename _Tp, bool = __or_<is_void<_Tp>, __is_array_unknown_bounds<_Tp>, is_function<_Tp> >::value, bool = __or_<is_reference<_Tp>, is_scalar<_Tp> >::value> struct __is_destructible_safe;
    template <typename _Tp> struct __is_destructible_safe<_Tp, false, false> : public __is_destructible_impl<typename remove_all_extents<_Tp>::type>::type {
    };
    template <typename _Tp> struct __is_destructible_safe<_Tp, true, false> : public std::false_type {
    };
    template <typename _Tp> struct __is_destructible_safe<_Tp, false, true> : public std::true_type {
    };
    template <typename _Tp> struct is_destructible : public __is_destructible_safe<_Tp>::type {
    };
    struct __do_is_nt_destructible_impl {
        template <typename _Tp> static integral_constant<bool, noexcept(declval<_Tp &>().~_Tp())> __test(int);
        template <typename > static std::false_type __test(...);
    };
    template <typename _Tp> struct __is_nt_destructible_impl : public std::__do_is_nt_destructible_impl {
        typedef decltype(__test<_Tp>(0)) type;
    };
    template <typename _Tp, bool = __or_<is_void<_Tp>, __is_array_unknown_bounds<_Tp>, is_function<_Tp> >::value, bool = __or_<is_reference<_Tp>, is_scalar<_Tp> >::value> struct __is_nt_destructible_safe;
    template <typename _Tp> struct __is_nt_destructible_safe<_Tp, false, false> : public __is_nt_destructible_impl<typename remove_all_extents<_Tp>::type>::type {
    };
    template <typename _Tp> struct __is_nt_destructible_safe<_Tp, true, false> : public std::false_type {
    };
    template <typename _Tp> struct __is_nt_destructible_safe<_Tp, false, true> : public std::true_type {
    };
    template <typename _Tp> struct is_nothrow_destructible : public __is_nt_destructible_safe<_Tp>::type {
    };
    struct __do_is_default_constructible_impl {
        template <typename _Tp, typename  = decltype(_Tp())> static std::true_type __test(int);
        template <typename > static std::false_type __test(...);
    };
    template <typename _Tp> struct __is_default_constructible_impl : public std::__do_is_default_constructible_impl {
        typedef decltype(__test<_Tp>(0)) type;
    };
    template <typename _Tp> struct __is_default_constructible_atom : public __and_<__not_<is_void<_Tp> >, __is_default_constructible_impl<_Tp> > {
    };
    template <typename _Tp, bool = is_array<_Tp>::value> struct __is_default_constructible_safe;
    template <typename _Tp> struct __is_default_constructible_safe<_Tp, true> : public __and_<__is_array_known_bounds<_Tp>, __is_default_constructible_atom<typename remove_all_extents<_Tp>::type> > {
    };
    template <typename _Tp> struct __is_default_constructible_safe<_Tp, false> : public __is_default_constructible_atom<_Tp>::type {
    };
    template <typename _Tp> struct is_default_constructible : public __is_default_constructible_safe<_Tp>::type {
    };
    struct __do_is_static_castable_impl {
        template <typename _From, typename _To, typename  = decltype(static_cast<_To>(declval<_From>()))> static std::true_type __test(int);
        template <typename , typename > static std::false_type __test(...);
    };
    template <typename _From, typename _To> struct __is_static_castable_impl : public std::__do_is_static_castable_impl {
        typedef decltype(__test<_From, _To>(0)) type;
    };
    template <typename _From, typename _To> struct __is_static_castable_safe : public __is_static_castable_impl<_From, _To>::type {
    };
    template <typename _From, typename _To> struct __is_static_castable : public integral_constant<bool, (__is_static_castable_safe<_From, _To>::value)> {
    };
    struct __do_is_direct_constructible_impl {
        template <typename _Tp, typename _Arg, typename  = decltype(::new _Tp((declval<_Arg>())))> static std::true_type __test(int);
        template <typename , typename > static std::false_type __test(...);
    };
    template <typename _Tp, typename _Arg> struct __is_direct_constructible_impl : public std::__do_is_direct_constructible_impl {
        typedef decltype(__test<_Tp, _Arg>(0)) type;
    };
    template <typename _Tp, typename _Arg> struct __is_direct_constructible_new_safe : public __and_<is_destructible<_Tp>, __is_direct_constructible_impl<_Tp, _Arg> > {
    };
    template <typename , typename > struct is_same;
    template <typename , typename > struct is_base_of;
    template <typename > struct remove_reference;
    template <typename _From, typename _To, bool = __not_<__or_<is_void<_From>, is_function<_From> > >::value> struct __is_base_to_derived_ref;
    template <typename _Tp, typename ..._Args> struct is_constructible;
    template <typename _From, typename _To> struct __is_base_to_derived_ref<_From, _To, true> {
        typedef typename remove_cv<typename remove_reference<_From>::type>::type __src_t;
        typedef typename remove_cv<typename remove_reference<_To>::type>::type __dst_t;
        typedef __and_<__not_<is_same<std::__is_base_to_derived_ref<type-parameter-0-0, type-parameter-0-1, true>::__src_t, std::__is_base_to_derived_ref<type-parameter-0-0, type-parameter-0-1, true>::__dst_t> >, is_base_of<std::__is_base_to_derived_ref<type-parameter-0-0, type-parameter-0-1, true>::__src_t, std::__is_base_to_derived_ref<type-parameter-0-0, type-parameter-0-1, true>::__dst_t>, __not_<is_constructible<std::__is_base_to_derived_ref<type-parameter-0-0, type-parameter-0-1, true>::__dst_t, _From> > > type;
        static constexpr bool value = type::value;
    };
    template <typename _From, typename _To> struct __is_base_to_derived_ref<_From, _To, false> : public std::false_type {
    };
    template <typename _From, typename _To, bool = __and_<is_lvalue_reference<_From>, is_rvalue_reference<_To> >::value> struct __is_lvalue_to_rvalue_ref;
    template <typename _From, typename _To> struct __is_lvalue_to_rvalue_ref<_From, _To, true> {
        typedef typename remove_cv<typename remove_reference<_From>::type>::type __src_t;
        typedef typename remove_cv<typename remove_reference<_To>::type>::type __dst_t;
        typedef __and_<__not_<is_function<std::__is_lvalue_to_rvalue_ref<type-parameter-0-0, type-parameter-0-1, true>::__src_t> >, __or_<is_same<std::__is_lvalue_to_rvalue_ref<type-parameter-0-0, type-parameter-0-1, true>::__src_t, std::__is_lvalue_to_rvalue_ref<type-parameter-0-0, type-parameter-0-1, true>::__dst_t>, is_base_of<std::__is_lvalue_to_rvalue_ref<type-parameter-0-0, type-parameter-0-1, true>::__dst_t, std::__is_lvalue_to_rvalue_ref<type-parameter-0-0, type-parameter-0-1, true>::__src_t> > > type;
        static constexpr bool value = type::value;
    };
    template <typename _From, typename _To> struct __is_lvalue_to_rvalue_ref<_From, _To, false> : public std::false_type {
    };
    template <typename _Tp, typename _Arg> struct __is_direct_constructible_ref_cast : public __and_<__is_static_castable<_Arg, _Tp>, __not_<__or_<__is_base_to_derived_ref<_Arg, _Tp>, __is_lvalue_to_rvalue_ref<_Arg, _Tp> > > > {
    };
    template <typename _Tp, typename _Arg> struct __is_direct_constructible_new : public conditional<is_reference<_Tp>::value, __is_direct_constructible_ref_cast<_Tp, _Arg>, __is_direct_constructible_new_safe<_Tp, _Arg> >::type {
    };
    template <typename _Tp, typename _Arg> struct __is_direct_constructible : public __is_direct_constructible_new<_Tp, _Arg>::type {
    };
    struct __do_is_nary_constructible_impl {
        template <typename _Tp, typename ..._Args, typename  = decltype(_Tp(declval<_Args>()...))> static std::true_type __test(int);
        template <typename , typename ...> static std::false_type __test(...);
    };
    template <typename _Tp, typename ..._Args> struct __is_nary_constructible_impl : public std::__do_is_nary_constructible_impl {
        typedef decltype(__test<_Tp, _Args...>(0)) type;
    };
    template <typename _Tp, typename ..._Args> struct __is_nary_constructible : public __is_nary_constructible_impl<_Tp, _Args...>::type {
        static_assert(sizeof...(_Args) > 1, "Only useful for > 1 arguments");
    };
    template <typename _Tp, typename ..._Args> struct __is_constructible_impl : public __is_nary_constructible<_Tp, _Args...> {
    };
    template <typename _Tp, typename _Arg> struct __is_constructible_impl<_Tp, <type-parameter-0-1>> : public __is_direct_constructible<_Tp, _Arg> {
    };
    template <typename _Tp> struct __is_constructible_impl<_Tp, <>> : public is_default_constructible<_Tp> {
    };
    template <typename _Tp, typename ..._Args> struct is_constructible : public __is_constructible_impl<_Tp, _Args...>::type {
    };
    template <typename _Tp, bool = __is_referenceable<_Tp>::value> struct __is_copy_constructible_impl;
    template <typename _Tp> struct __is_copy_constructible_impl<_Tp, false> : public std::false_type {
    };
    template <typename _Tp> struct __is_copy_constructible_impl<_Tp, true> : public is_constructible<_Tp, const _Tp &> {
    };
    template <typename _Tp> struct is_copy_constructible : public __is_copy_constructible_impl<_Tp> {
    };
    template <typename _Tp, bool = __is_referenceable<_Tp>::value> struct __is_move_constructible_impl;
    template <typename _Tp> struct __is_move_constructible_impl<_Tp, false> : public std::false_type {
    };
    template <typename _Tp> struct __is_move_constructible_impl<_Tp, true> : public is_constructible<_Tp, _Tp &&> {
    };
    template <typename _Tp> struct is_move_constructible : public __is_move_constructible_impl<_Tp> {
    };
    template <typename _Tp> struct __is_nt_default_constructible_atom : public integral_constant<bool, noexcept(_Tp())> {
    };
    template <typename _Tp, bool = is_array<_Tp>::value> struct __is_nt_default_constructible_impl;
    template <typename _Tp> struct __is_nt_default_constructible_impl<_Tp, true> : public __and_<__is_array_known_bounds<_Tp>, __is_nt_default_constructible_atom<typename remove_all_extents<_Tp>::type> > {
    };
    template <typename _Tp> struct __is_nt_default_constructible_impl<_Tp, false> : public __is_nt_default_constructible_atom<_Tp> {
    };
    template <typename _Tp> struct is_nothrow_default_constructible : public __and_<is_default_constructible<_Tp>, __is_nt_default_constructible_impl<_Tp> > {
    };
    template <typename _Tp, typename ..._Args> struct __is_nt_constructible_impl : public integral_constant<bool, noexcept(_Tp(declval<_Args>()...))> {
    };
    template <typename _Tp, typename _Arg> struct __is_nt_constructible_impl<_Tp, <type-parameter-0-1>> : public integral_constant<bool, noexcept(static_cast<_Tp>(declval<_Arg>()))> {
    };
    template <typename _Tp> struct __is_nt_constructible_impl<_Tp, <>> : public is_nothrow_default_constructible<_Tp> {
    };
    template <typename _Tp, typename ..._Args> struct is_nothrow_constructible : public __and_<is_constructible<_Tp, _Args...>, __is_nt_constructible_impl<_Tp, _Args...> > {
    };
    template <typename _Tp, bool = __is_referenceable<_Tp>::value> struct __is_nothrow_copy_constructible_impl;
    template <typename _Tp> struct __is_nothrow_copy_constructible_impl<_Tp, false> : public std::false_type {
    };
    template <typename _Tp> struct __is_nothrow_copy_constructible_impl<_Tp, true> : public is_nothrow_constructible<_Tp, const _Tp &> {
    };
    template <typename _Tp> struct is_nothrow_copy_constructible : public __is_nothrow_copy_constructible_impl<_Tp> {
    };
    template <typename _Tp, bool = __is_referenceable<_Tp>::value> struct __is_nothrow_move_constructible_impl;
    template <typename _Tp> struct __is_nothrow_move_constructible_impl<_Tp, false> : public std::false_type {
    };
    template <typename _Tp> struct __is_nothrow_move_constructible_impl<_Tp, true> : public is_nothrow_constructible<_Tp, _Tp &&> {
    };
    template <typename _Tp> struct is_nothrow_move_constructible : public __is_nothrow_move_constructible_impl<_Tp> {
    };
    template <typename _Tp, typename _Up> class __is_assignable_helper {
        template <typename _Tp1, typename _Up1, typename  = decltype(declval<_Tp1>() = declval<_Up1>())> static std::true_type __test(int);
        template <typename , typename > static std::false_type __test(...);
    public:
        typedef decltype(__test<_Tp, _Up>(0)) type;
    };
    template <typename _Tp, typename _Up> struct is_assignable : public __is_assignable_helper<_Tp, _Up>::type {
    };
    template <typename _Tp, bool = __is_referenceable<_Tp>::value> struct __is_copy_assignable_impl;
    template <typename _Tp> struct __is_copy_assignable_impl<_Tp, false> : public std::false_type {
    };
    template <typename _Tp> struct __is_copy_assignable_impl<_Tp, true> : public is_assignable<_Tp &, const _Tp &> {
    };
    template <typename _Tp> struct is_copy_assignable : public __is_copy_assignable_impl<_Tp> {
    };
    template <typename _Tp, bool = __is_referenceable<_Tp>::value> struct __is_move_assignable_impl;
    template <typename _Tp> struct __is_move_assignable_impl<_Tp, false> : public std::false_type {
    };
    template <typename _Tp> struct __is_move_assignable_impl<_Tp, true> : public is_assignable<_Tp &, _Tp &&> {
    };
    template <typename _Tp> struct is_move_assignable : public __is_move_assignable_impl<_Tp> {
    };
    template <typename _Tp, typename _Up> struct __is_nt_assignable_impl : public integral_constant<bool, noexcept(declval<_Tp>() = declval<_Up>())> {
    };
    template <typename _Tp, typename _Up> struct is_nothrow_assignable : public __and_<is_assignable<_Tp, _Up>, __is_nt_assignable_impl<_Tp, _Up> > {
    };
    template <typename _Tp, bool = __is_referenceable<_Tp>::value> struct __is_nt_copy_assignable_impl;
    template <typename _Tp> struct __is_nt_copy_assignable_impl<_Tp, false> : public std::false_type {
    };
    template <typename _Tp> struct __is_nt_copy_assignable_impl<_Tp, true> : public is_nothrow_assignable<_Tp &, const _Tp &> {
    };
    template <typename _Tp> struct is_nothrow_copy_assignable : public __is_nt_copy_assignable_impl<_Tp> {
    };
    template <typename _Tp, bool = __is_referenceable<_Tp>::value> struct __is_nt_move_assignable_impl;
    template <typename _Tp> struct __is_nt_move_assignable_impl<_Tp, false> : public std::false_type {
    };
    template <typename _Tp> struct __is_nt_move_assignable_impl<_Tp, true> : public is_nothrow_assignable<_Tp &, _Tp &&> {
    };
    template <typename _Tp> struct is_nothrow_move_assignable : public __is_nt_move_assignable_impl<_Tp> {
    };
    template <typename _Tp, typename ..._Args> struct is_trivially_constructible : public __and_<is_constructible<_Tp, _Args...>, integral_constant<bool, __is_trivially_constructible(_Tp, _Args...)> > {
    };
    template <typename _Tp> struct is_trivially_default_constructible : public is_trivially_constructible<_Tp>::type {
    };
    struct __do_is_implicitly_default_constructible_impl {
        template <typename _Tp> static void __helper(const _Tp &);
        template <typename _Tp> static std::true_type __test(const _Tp &, decltype(__helper<const _Tp &>({})) * = 0);
        static std::false_type __test(...);
    };
    template <typename _Tp> struct __is_implicitly_default_constructible_impl : public std::__do_is_implicitly_default_constructible_impl {
        typedef decltype(__test(declval<_Tp>())) type;
    };
    template <typename _Tp> struct __is_implicitly_default_constructible_safe : public __is_implicitly_default_constructible_impl<_Tp>::type {
    };
    template <typename _Tp> struct __is_implicitly_default_constructible : public __and_<is_default_constructible<_Tp>, __is_implicitly_default_constructible_safe<_Tp> > {
    };
    template <typename _Tp> struct is_trivially_copy_constructible : public __and_<is_copy_constructible<_Tp>, integral_constant<bool, __is_trivially_constructible(_Tp, const _Tp &)> > {
    };
    template <typename _Tp> struct is_trivially_move_constructible : public __and_<is_move_constructible<_Tp>, integral_constant<bool, __is_trivially_constructible(_Tp, _Tp &&)> > {
    };
    template <typename _Tp, typename _Up> struct is_trivially_assignable : public __and_<is_assignable<_Tp, _Up>, integral_constant<bool, __is_trivially_assignable(_Tp, _Up)> > {
    };
    template <typename _Tp> struct is_trivially_copy_assignable : public __and_<is_copy_assignable<_Tp>, integral_constant<bool, __is_trivially_assignable(_Tp &, const _Tp &)> > {
    };
    template <typename _Tp> struct is_trivially_move_assignable : public __and_<is_move_assignable<_Tp>, integral_constant<bool, __is_trivially_assignable(_Tp &, _Tp &&)> > {
    };
    template <typename _Tp> struct is_trivially_destructible : public __and_<is_destructible<_Tp>, integral_constant<bool, __has_trivial_destructor(_Tp)> > {
    };
    template <typename _Tp> struct has_virtual_destructor : public integral_constant<bool, __has_virtual_destructor(_Tp)> {
    };
    template <typename _Tp> struct alignment_of : public integral_constant<std::size_t, alignof(_Tp)> {
    };
    template <typename > struct rank : public integral_constant<std::size_t, 0> {
    };
    template <typename _Tp, std::size_t _Size> struct rank<type-parameter-0-0 [_Size]> : public integral_constant<std::size_t, 1 + rank<_Tp>::value> {
    };
    template <typename _Tp> struct rank<type-parameter-0-0 []> : public integral_constant<std::size_t, 1 + rank<_Tp>::value> {
    };
    template <typename , unsigned int _Uint = 0> struct extent : public integral_constant<std::size_t, 0> {
    };
    template <typename _Tp, unsigned int _Uint, std::size_t _Size> struct extent<type-parameter-0-0 [_Size], _Uint> : public integral_constant<std::size_t, _Uint == 0 ? _Size : extent<_Tp, _Uint - 1>::value> {
    };
    template <typename _Tp, unsigned int _Uint> struct extent<type-parameter-0-0 [], _Uint> : public integral_constant<std::size_t, _Uint == 0 ? 0 : extent<_Tp, _Uint - 1>::value> {
    };
    template <typename , typename > struct is_same : public std::false_type {
    };
    template <typename _Tp> struct is_same<_Tp, _Tp> : public std::true_type {
    };
    template <typename _Base, typename _Derived> struct is_base_of : public integral_constant<bool, __is_base_of(_Base, _Derived)> {
    };
    template <typename _From, typename _To, bool = __or_<is_void<_From>, is_function<_To>, is_array<_To> >::value> struct __is_convertible_helper {
        typedef typename is_void<_To>::type type;
    };
    template <typename _From, typename _To> class __is_convertible_helper<_From, _To, false> {
        template <typename _To1> static void __test_aux(_To1);
        template <typename _From1, typename _To1, typename  = decltype(__test_aux<_To1>(std::declval<_From1>()))> static std::true_type __test(int);
        template <typename , typename > static std::false_type __test(...);
    public:
        typedef decltype(__test<_From, _To>(0)) type;
    };
    template <typename _From, typename _To> struct is_convertible : public __is_convertible_helper<_From, _To>::type {
    };
    template <typename _Tp> struct remove_const {
        typedef _Tp type;
    };
    template <typename _Tp> struct remove_const<_Tp> {
        typedef _Tp type;
    };
    template <typename _Tp> struct remove_volatile {
        typedef _Tp type;
    };
    template <typename _Tp> struct remove_volatile<_Tp> {
        typedef _Tp type;
    };
    template <typename _Tp> struct remove_cv {
        typedef typename remove_const<typename remove_volatile<_Tp>::type>::type type;
    };
    template <typename _Tp> struct add_const {
        typedef const _Tp type;
    };
    template <typename _Tp> struct add_volatile {
        typedef volatile _Tp type;
    };
    template <typename _Tp> struct add_cv {
        typedef typename add_const<typename add_volatile<_Tp>::type>::type type;
    };
    template <typename _Tp> using remove_const_t = typename remove_const<_Tp>::type;
    template <typename _Tp> using remove_volatile_t = typename remove_volatile<_Tp>::type;
    template <typename _Tp> using remove_cv_t = typename remove_cv<_Tp>::type;
    template <typename _Tp> using add_const_t = typename add_const<_Tp>::type;
    template <typename _Tp> using add_volatile_t = typename add_volatile<_Tp>::type;
    template <typename _Tp> using add_cv_t = typename add_cv<_Tp>::type;
    template <typename _Tp> struct remove_reference {
        typedef _Tp type;
    };
    template <typename _Tp> struct remove_reference<type-parameter-0-0 &> {
        typedef _Tp type;
    };
    template <typename _Tp> struct remove_reference<type-parameter-0-0 &&> {
        typedef _Tp type;
    };
    template <typename _Tp, bool = __is_referenceable<_Tp>::value> struct __add_lvalue_reference_helper {
        typedef _Tp type;
    };
    template <typename _Tp> struct __add_lvalue_reference_helper<_Tp, true> {
        typedef _Tp &type;
    };
    template <typename _Tp> struct add_lvalue_reference : public __add_lvalue_reference_helper<_Tp> {
    };
    template <typename _Tp, bool = __is_referenceable<_Tp>::value> struct __add_rvalue_reference_helper {
        typedef _Tp type;
    };
    template <typename _Tp> struct __add_rvalue_reference_helper<_Tp, true> {
        typedef _Tp &&type;
    };
    template <typename _Tp> struct add_rvalue_reference : public __add_rvalue_reference_helper<_Tp> {
    };
    template <typename _Tp> using remove_reference_t = typename remove_reference<_Tp>::type;
    template <typename _Tp> using add_lvalue_reference_t = typename add_lvalue_reference<_Tp>::type;
    template <typename _Tp> using add_rvalue_reference_t = typename add_rvalue_reference<_Tp>::type;
    template <typename _Unqualified, bool _IsConst, bool _IsVol> struct __cv_selector;
    template <typename _Unqualified> struct __cv_selector<_Unqualified, false, false> {
        typedef _Unqualified __type;
    };
    template <typename _Unqualified> struct __cv_selector<_Unqualified, false, true> {
        typedef volatile _Unqualified __type;
    };
    template <typename _Unqualified> struct __cv_selector<_Unqualified, true, false> {
        typedef const _Unqualified __type;
    };
    template <typename _Unqualified> struct __cv_selector<_Unqualified, true, true> {
        typedef const volatile _Unqualified __type;
    };
    template <typename _Qualified, typename _Unqualified, bool _IsConst = is_const<_Qualified>::value, bool _IsVol = is_volatile<_Qualified>::value> class __match_cv_qualifiers {
        typedef __cv_selector<_Unqualified, _IsConst, _IsVol> __match;
    public:
        typedef typename __match::__type __type;
    };
    template <typename _Tp> struct __make_unsigned {
        typedef _Tp __type;
    };
    template<> struct __make_unsigned<char> {
        typedef unsigned char __type;
    };
    template<> struct __make_unsigned<signed char> {
        typedef unsigned char __type;
    };
    template<> struct __make_unsigned<short> {
        typedef unsigned short __type;
    };
    template<> struct __make_unsigned<int> {
        typedef unsigned int __type;
    };
    template<> struct __make_unsigned<long> {
        typedef unsigned long __type;
    };
    template<> struct __make_unsigned<long long> {
        typedef unsigned long long __type;
    };
    template<> struct __make_unsigned<wchar_t> : __make_unsigned<int> {
    };
    template<> struct __make_unsigned<__int128> {
        typedef unsigned __int128 __type;
    };
    template <typename _Tp, bool _IsInt = is_integral<_Tp>::value, bool _IsEnum = is_enum<_Tp>::value> class __make_unsigned_selector;
    template <typename _Tp> class __make_unsigned_selector<_Tp, true, false> {
        typedef __make_unsigned<typename remove_cv<_Tp>::type> __unsignedt;
        typedef typename __unsignedt::__type __unsigned_type;
        typedef __match_cv_qualifiers<_Tp, std::__make_unsigned_selector<type-parameter-0-0, true, false>::__unsigned_type> __cv_unsigned;
    public:
        typedef typename __cv_unsigned::__type __type;
    };
    template <typename _Tp> class __make_unsigned_selector<_Tp, false, true> {
        typedef unsigned char __smallest;
        static const bool __b0 = sizeof(_Tp) <= sizeof(std::__make_unsigned_selector<type-parameter-0-0, false, true>::__smallest);
        static const bool __b1 = sizeof(_Tp) <= sizeof(unsigned short);
        static const bool __b2 = sizeof(_Tp) <= sizeof(unsigned int);
        static const bool __b3 = sizeof(_Tp) <= sizeof(unsigned long);
        typedef conditional<__b3, unsigned long, unsigned long long> __cond3;
        typedef typename __cond3::type __cond3_type;
        typedef conditional<__b2, unsigned int, std::__make_unsigned_selector<type-parameter-0-0, false, true>::__cond3_type> __cond2;
        typedef typename __cond2::type __cond2_type;
        typedef conditional<__b1, unsigned short, std::__make_unsigned_selector<type-parameter-0-0, false, true>::__cond2_type> __cond1;
        typedef typename __cond1::type __cond1_type;
        typedef typename conditional<__b0, __smallest, __cond1_type>::type __unsigned_type;
        typedef __match_cv_qualifiers<_Tp, std::__make_unsigned_selector<type-parameter-0-0, false, true>::__unsigned_type> __cv_unsigned;
    public:
        typedef typename __cv_unsigned::__type __type;
    };
    template <typename _Tp> struct make_unsigned {
        typedef typename __make_unsigned_selector<_Tp>::__type type;
    };
    template<> struct make_unsigned<bool>;
    template <typename _Tp> struct __make_signed {
        typedef _Tp __type;
    };
    template<> struct __make_signed<char> {
        typedef signed char __type;
    };
    template<> struct __make_signed<unsigned char> {
        typedef signed char __type;
    };
    template<> struct __make_signed<unsigned short> {
        typedef short __type;
    };
    template<> struct __make_signed<unsigned int> {
        typedef int __type;
    };
    template<> struct __make_signed<unsigned long> {
        typedef long __type;
    };
    template<> struct __make_signed<unsigned long long> {
        typedef long long __type;
    };
    template<> struct __make_signed<char16_t> : __make_signed<std::uint_least16_t> {
    };
    template<> struct __make_signed<char32_t> : __make_signed<std::uint_least32_t> {
    };
    template<> struct __make_signed<unsigned __int128> {
        typedef __int128 __type;
    };
    template <typename _Tp, bool _IsInt = is_integral<_Tp>::value, bool _IsEnum = is_enum<_Tp>::value> class __make_signed_selector;
    template <typename _Tp> class __make_signed_selector<_Tp, true, false> {
        typedef __make_signed<typename remove_cv<_Tp>::type> __signedt;
        typedef typename __signedt::__type __signed_type;
        typedef __match_cv_qualifiers<_Tp, std::__make_signed_selector<type-parameter-0-0, true, false>::__signed_type> __cv_signed;
    public:
        typedef typename __cv_signed::__type __type;
    };
    template <typename _Tp> class __make_signed_selector<_Tp, false, true> {
        typedef typename __make_unsigned_selector<_Tp>::__type __unsigned_type;
    public:
        typedef typename __make_signed_selector<__unsigned_type>::__type __type;
    };
    template <typename _Tp> struct make_signed {
        typedef typename __make_signed_selector<_Tp>::__type type;
    };
    template<> struct make_signed<bool>;
    template <typename _Tp> using make_signed_t = typename make_signed<_Tp>::type;
    template <typename _Tp> using make_unsigned_t = typename make_unsigned<_Tp>::type;
    template <typename _Tp> struct remove_extent {
        typedef _Tp type;
    };
    template <typename _Tp, std::size_t _Size> struct remove_extent<type-parameter-0-0 [_Size]> {
        typedef _Tp type;
    };
    template <typename _Tp> struct remove_extent<type-parameter-0-0 []> {
        typedef _Tp type;
    };
    template <typename _Tp> struct remove_all_extents {
        typedef _Tp type;
    };
    template <typename _Tp, std::size_t _Size> struct remove_all_extents<type-parameter-0-0 [_Size]> {
        typedef typename remove_all_extents<_Tp>::type type;
    };
    template <typename _Tp> struct remove_all_extents<type-parameter-0-0 []> {
        typedef typename remove_all_extents<_Tp>::type type;
    };
    template <typename _Tp> using remove_extent_t = typename remove_extent<_Tp>::type;
    template <typename _Tp> using remove_all_extents_t = typename remove_all_extents<_Tp>::type;
    template <typename _Tp, typename > struct __remove_pointer_helper {
        typedef _Tp type;
    };
    template <typename _Tp, typename _Up> struct __remove_pointer_helper<_Tp, type-parameter-0-1 *> {
        typedef _Up type;
    };
    template <typename _Tp> struct remove_pointer : public __remove_pointer_helper<_Tp, typename remove_cv<_Tp>::type> {
    };
    template <typename _Tp, bool = __or_<__is_referenceable<_Tp>, is_void<_Tp> >::value> struct __add_pointer_helper {
        typedef _Tp type;
    };
    template <typename _Tp> struct __add_pointer_helper<_Tp, true> {
        typedef typename remove_reference<_Tp>::type *type;
    };
    template <typename _Tp> struct add_pointer : public __add_pointer_helper<_Tp> {
    };
    template <typename _Tp> using remove_pointer_t = typename remove_pointer<_Tp>::type;
    template <typename _Tp> using add_pointer_t = typename add_pointer<_Tp>::type;
    template <std::size_t _Len> struct __aligned_storage_msa {
        union __type {
            unsigned char __data[_Len];
            struct __attribute__((aligned())) {
            } __align;
        };
    };
    template <std::size_t _Len, std::size_t _Align = alignof(typename __aligned_storage_msa<_Len>::__type)> struct aligned_storage {
        union type {
            unsigned char __data[_Len];
            struct __attribute__((aligned((_Align)))) {
            } __align;
        };
    };
    template <typename ..._Types> struct __strictest_alignment {
        static const std::size_t _S_alignment = 0;
        static const std::size_t _S_size = 0;
    };
    template <typename _Tp, typename ..._Types> struct __strictest_alignment<<type-parameter-0-0, type-parameter-0-1...>> {
        static const std::size_t _S_alignment = alignof(_Tp) > __strictest_alignment<_Types...>::_S_alignment ? alignof(_Tp) : __strictest_alignment<_Types...>::_S_alignment;
        static const std::size_t _S_size = sizeof(_Tp) > __strictest_alignment<_Types...>::_S_size ? sizeof(_Tp) : __strictest_alignment<_Types...>::_S_size;
    };
    template <std::size_t _Len, typename ..._Types> struct aligned_union {
    private:
        static_assert(sizeof...(_Types) != 0, "At least one type is required");
        using __strictest = __strictest_alignment<_Types...>;
        static const std::size_t _S_len = _Len > __strictest::_S_size ? _Len : __strictest::_S_size;
    public:
        static const std::size_t alignment_value = __strictest::_S_alignment;
        typedef typename aligned_storage<_S_len, alignment_value>::type type;
    };
    const std::size_t alignment_value;
    template <typename _Up, bool _IsArray = is_array<_Up>::value, bool _IsFunction = is_function<_Up>::value> struct __decay_selector;
    template <typename _Up> struct __decay_selector<_Up, false, false> {
        typedef typename remove_cv<_Up>::type __type;
    };
    template <typename _Up> struct __decay_selector<_Up, true, false> {
        typedef typename remove_extent<_Up>::type *__type;
    };
    template <typename _Up> struct __decay_selector<_Up, false, true> {
        typedef typename add_pointer<_Up>::type __type;
    };
    template <typename _Tp> class decay {
        typedef typename remove_reference<_Tp>::type __remove_type;
    public:
        typedef typename __decay_selector<__remove_type>::__type type;
    };
    template <typename _Tp> class reference_wrapper;
    template <typename _Tp> struct __strip_reference_wrapper {
        typedef _Tp __type;
    };
    template <typename _Tp> struct __strip_reference_wrapper<reference_wrapper<type-parameter-0-0>> {
        typedef _Tp &__type;
    };
    template <typename _Tp> struct __decay_and_strip {
        typedef typename __strip_reference_wrapper<typename decay<_Tp>::type>::__type __type;
    };
    template <bool, typename _Tp = void> struct enable_if {
    };
    template <typename _Tp> struct enable_if<true, _Tp> {
        typedef _Tp type;
    };
    template <typename ..._Cond> using _Require = typename enable_if<__and_<_Cond...>::value>::type;
    template <bool _Cond, typename _Iftrue, typename _Iffalse> struct conditional {
        typedef _Iftrue type;
    };
    template <typename _Iftrue, typename _Iffalse> struct conditional<false, _Iftrue, _Iffalse> {
        typedef _Iffalse type;
    };
    template <typename ..._Tp> struct common_type;
    struct __do_common_type_impl {
        template <typename _Tp, typename _Up> static __success_type<typename decay<decltype(true ? std::declval<_Tp>() : std::declval<_Up>())>::type> _S_test(int);
        template <typename , typename > static std::__failure_type _S_test(...);
    };
    template <typename _Tp, typename _Up> struct __common_type_impl : private std::__do_common_type_impl {
        typedef decltype(_S_test<_Tp, _Up>(0)) type;
    };
    struct __do_member_type_wrapper {
        template <typename _Tp> static __success_type<typename _Tp::type> _S_test(int);
        template <typename > static std::__failure_type _S_test(...);
    };
    template <typename _Tp> struct __member_type_wrapper : private std::__do_member_type_wrapper {
        typedef decltype(_S_test<_Tp>(0)) type;
    };
    template <typename _CTp, typename ..._Args> struct __expanded_common_type_wrapper {
        typedef common_type<typename _CTp::type, _Args...> type;
    };
    template <typename ..._Args> struct __expanded_common_type_wrapper<std::__failure_type, <type-parameter-0-0...>> {
        typedef std::__failure_type type;
    };
    template <typename _Tp> struct common_type<<type-parameter-0-0>> {
        typedef typename decay<_Tp>::type type;
    };
    template <typename _Tp, typename _Up> struct common_type<<type-parameter-0-0, type-parameter-0-1>> : public __common_type_impl<_Tp, _Up>::type {
    };
    template <typename _Tp, typename _Up, typename ..._Vp> struct common_type<<type-parameter-0-0, type-parameter-0-1, type-parameter-0-2...>> : public __expanded_common_type_wrapper<typename __member_type_wrapper<common_type<_Tp, _Up> >::type, _Vp...>::type {
    };
    template <typename _Tp> struct underlying_type {
        typedef __underlying_type(_Tp) type;
    };
    template <typename _Tp> struct __declval_protector {
        static const bool __stop = false;
        static typename add_rvalue_reference<_Tp>::type __delegate();
    };
    template <typename _Tp> inline typename add_rvalue_reference<_Tp>::type declval() noexcept     {
        static_assert(__declval_protector<_Tp>::__stop, "declval() must not be used!");
        return __declval_protector<_Tp>::__delegate();
    }
    template <typename _Signature> class result_of;
    struct __invoke_memfun_ref {
    };
    struct __invoke_memfun_deref {
    };
    struct __invoke_memobj_ref {
    };
    struct __invoke_memobj_deref {
    };
    struct __invoke_other {
    };
    template <typename _Tp, typename _Tag> struct __result_of_success : __success_type<_Tp> {
        using __invoke_type = _Tag;
    };
    struct __result_of_memfun_ref_impl {
        template <typename _Fp, typename _Tp1, typename ..._Args> static __result_of_success<decltype((std::declval<_Tp1>() .* std::declval<_Fp>())(std::declval<_Args>()...)), std::__invoke_memfun_ref> _S_test(int);
        template <typename ...> static std::__failure_type _S_test(...);
    };
    template <typename _MemPtr, typename _Arg, typename ..._Args> struct __result_of_memfun_ref : private std::__result_of_memfun_ref_impl {
        typedef decltype(_S_test<_MemPtr, _Arg, _Args...>(0)) type;
    };
    struct __result_of_memfun_deref_impl {
        template <typename _Fp, typename _Tp1, typename ..._Args> static __result_of_success<decltype(((*std::declval<_Tp1>()) .* std::declval<_Fp>())(std::declval<_Args>()...)), std::__invoke_memfun_deref> _S_test(int);
        template <typename ...> static std::__failure_type _S_test(...);
    };
    template <typename _MemPtr, typename _Arg, typename ..._Args> struct __result_of_memfun_deref : private std::__result_of_memfun_deref_impl {
        typedef decltype(_S_test<_MemPtr, _Arg, _Args...>(0)) type;
    };
    struct __result_of_memobj_ref_impl {
        template <typename _Fp, typename _Tp1> static __result_of_success<decltype(std::declval<_Tp1>() .* std::declval<_Fp>()), std::__invoke_memobj_ref> _S_test(int);
        template <typename , typename > static std::__failure_type _S_test(...);
    };
    template <typename _MemPtr, typename _Arg> struct __result_of_memobj_ref : private std::__result_of_memobj_ref_impl {
        typedef decltype(_S_test<_MemPtr, _Arg>(0)) type;
    };
    struct __result_of_memobj_deref_impl {
        template <typename _Fp, typename _Tp1> static __result_of_success<decltype((*std::declval<_Tp1>()) .* std::declval<_Fp>()), std::__invoke_memobj_deref> _S_test(int);
        template <typename , typename > static std::__failure_type _S_test(...);
    };
    template <typename _MemPtr, typename _Arg> struct __result_of_memobj_deref : private std::__result_of_memobj_deref_impl {
        typedef decltype(_S_test<_MemPtr, _Arg>(0)) type;
    };
    template <typename _MemPtr, typename _Arg> struct __result_of_memobj;
    template <typename _Res, typename _Class, typename _Arg> struct __result_of_memobj<type-parameter-0-0 type-parameter-0-1::*, _Arg> {
        typedef typename remove_cv<typename remove_reference<_Arg>::type>::type _Argval;
        typedef _Res _Class::*_MemPtr;
        typedef typename conditional<__or_<is_same<_Argval, _Class>, is_base_of<_Class, _Argval> >::value, __result_of_memobj_ref<_MemPtr, _Arg>, __result_of_memobj_deref<_MemPtr, _Arg> >::type::type type;
    };
    template <typename _MemPtr, typename _Arg, typename ..._Args> struct __result_of_memfun;
    template <typename _Res, typename _Class, typename _Arg, typename ..._Args> struct __result_of_memfun<type-parameter-0-0 type-parameter-0-1::*, _Arg, <type-parameter-0-3...>> {
        typedef typename remove_cv<typename remove_reference<_Arg>::type>::type _Argval;
        typedef _Res _Class::*_MemPtr;
        typedef typename conditional<__or_<is_same<_Argval, _Class>, is_base_of<_Class, _Argval> >::value, __result_of_memfun_ref<_MemPtr, _Arg, _Args...>, __result_of_memfun_deref<_MemPtr, _Arg, _Args...> >::type::type type;
    };
    template <typename _Tp, typename _Up = typename decay<_Tp>::type> struct __inv_unwrap {
        using type = _Tp;
    };
    template <typename _Tp, typename _Up> struct __inv_unwrap<_Tp, reference_wrapper<type-parameter-0-1>> {
        using type = _Up &;
    };
    template <bool, bool, typename _Functor, typename ..._ArgTypes> struct __result_of_impl {
        typedef std::__failure_type type;
    };
    template <typename _MemPtr, typename _Arg> struct __result_of_impl<true, false, _MemPtr, <type-parameter-0-1>> : public __result_of_memobj<typename decay<_MemPtr>::type, typename __inv_unwrap<_Arg>::type> {
    };
    template <typename _MemPtr, typename _Arg, typename ..._Args> struct __result_of_impl<false, true, _MemPtr, <type-parameter-0-1, type-parameter-0-2...>> : public __result_of_memfun<typename decay<_MemPtr>::type, typename __inv_unwrap<_Arg>::type, _Args...> {
    };
    struct __result_of_other_impl {
        template <typename _Fn, typename ..._Args> static __result_of_success<decltype(std::declval<_Fn>()(std::declval<_Args>()...)), std::__invoke_other> _S_test(int);
        template <typename ...> static std::__failure_type _S_test(...);
    };
    template <typename _Functor, typename ..._ArgTypes> struct __result_of_impl<false, false, _Functor, <type-parameter-0-1...>> : private std::__result_of_other_impl {
        typedef decltype(_S_test<_Functor, _ArgTypes...>(0)) type;
    };
    template <typename _Functor, typename ..._ArgTypes> struct __invoke_result : public __result_of_impl<is_member_object_pointer<typename remove_reference<_Functor>::type>::value, is_member_function_pointer<typename remove_reference<_Functor>::type>::value, _Functor, _ArgTypes...>::type {
    };
    template <typename _Functor, typename ..._ArgTypes> struct result_of<type-parameter-0-0 (type-parameter-0-1...)> : public __invoke_result<_Functor, _ArgTypes...> {
    };
    template <std::size_t _Len, std::size_t _Align = alignof(typename __aligned_storage_msa<_Len>::__type)> using aligned_storage_t = typename aligned_storage<_Len, _Align>::type;
    template <std::size_t _Len, typename ..._Types> using aligned_union_t = typename aligned_union<_Len, _Types...>::type;
    template <typename _Tp> using decay_t = typename decay<_Tp>::type;
    template <bool _Cond, typename _Tp = void> using enable_if_t = typename enable_if<_Cond, _Tp>::type;
    template <bool _Cond, typename _Iftrue, typename _Iffalse> using conditional_t = typename conditional<_Cond, _Iftrue, _Iffalse>::type;
    template <typename ..._Tp> using common_type_t = typename common_type<_Tp...>::type;
    template <typename _Tp> using underlying_type_t = typename underlying_type<_Tp>::type;
    template <typename _Tp> using result_of_t = typename result_of<_Tp>::type;
    template <bool _Cond, typename _Tp = void> using __enable_if_t = typename enable_if<_Cond, _Tp>::type;
    template <typename ...> using __void_t = void;
    template <typename ...> using void_t = void;
    template <typename _Default, typename _AlwaysVoid, template <typename ...> class _Op, typename ..._Args> struct __detector {
        using value_t = std::false_type;
        using type = _Default;
    };
    template <typename _Default, template <typename ...> class _Op, typename ..._Args> struct __detector<_Default, void, _Op, <type-parameter-0-2...>> {
        using value_t = std::true_type;
        using type = _Op<_Args...>;
    };
    template <typename _Default, template <typename ...> class _Op, typename ..._Args> using __detected_or = __detector<_Default, void, _Op, _Args...>;
    template <typename _Default, template <typename ...> class _Op, typename ..._Args> using __detected_or_t = typename __detected_or<_Default, _Op, _Args...>::type;
    template <typename _Tp> struct __is_swappable;
    template <typename _Tp> struct __is_nothrow_swappable;
    template <typename ..._Elements> class tuple;
    template <typename > struct __is_tuple_like_impl : std::false_type {
    };
    template <typename ..._Tps> struct __is_tuple_like_impl<tuple<type-parameter-0-0...>> : std::true_type {
    };
    template <typename _Tp> struct __is_tuple_like : public __is_tuple_like_impl<typename remove_cv<typename remove_reference<_Tp>::type>::type>::type {
    };
    template <typename _Tp> inline typename enable_if<__and_<__not_<__is_tuple_like<_Tp> >, is_move_constructible<_Tp>, is_move_assignable<_Tp> >::value>::type swap(_Tp &, _Tp &) noexcept(__and_<is_nothrow_move_constructible<_Tp>, is_nothrow_move_assignable<_Tp> >::valueswap(_Tp &, _Tp &) noexcept(__and_<is_nothrow_move_constructible<_Tp>, is_nothrow_move_assignable<_Tp> >::value);
    template <typename _Tp, std::size_t _Nm> inline typename enable_if<__is_swappable<_Tp>::value>::type swap(_Tp (&__a)[_Nm], _Tp (&__b)[_Nm]) noexcept(__is_nothrow_swappable<_Tp>::valueswap(_Tp (&__a)[_Nm], _Tp (&__b)[_Nm]) noexcept(__is_nothrow_swappable<_Tp>::value);
    namespace __swappable_details {
        using std::swap;
        struct __do_is_swappable_impl {
            template <typename _Tp, typename  = decltype(swap(std::declval<_Tp &>(), std::declval<_Tp &>()))> static std::true_type __test(int);
            template <typename > static std::false_type __test(...);
        };
        struct __do_is_nothrow_swappable_impl {
            template <typename _Tp> static __bool_constant<noexcept(swap(std::declval<_Tp &>(), std::declval<_Tp &>()))> __test(int);
            template <typename > static std::false_type __test(...);
        };
    }
    template <typename _Tp> struct __is_swappable_impl : public __swappable_details::__do_is_swappable_impl {
        typedef decltype(__test<_Tp>(0)) type;
    };
    template <typename _Tp> struct __is_nothrow_swappable_impl : public __swappable_details::__do_is_nothrow_swappable_impl {
        typedef decltype(__test<_Tp>(0)) type;
    };
    template <typename _Tp> struct __is_swappable : public __is_swappable_impl<_Tp>::type {
    };
    template <typename _Tp> struct __is_nothrow_swappable : public __is_nothrow_swappable_impl<_Tp>::type {
    };
    template <typename _Tp> struct is_swappable : public __is_swappable_impl<_Tp>::type {
    };
    template <typename _Tp> struct is_nothrow_swappable : public __is_nothrow_swappable_impl<_Tp>::type {
    };
    template <typename _Tp> constexpr bool is_swappable_v = is_swappable<_Tp>::value;
    template <typename _Tp> constexpr bool is_nothrow_swappable_v = is_nothrow_swappable<_Tp>::value;
    namespace __swappable_with_details {
        using std::swap;
        struct __do_is_swappable_with_impl {
            template <typename _Tp, typename _Up, typename  = decltype(swap(std::declval<_Tp>(), std::declval<_Up>())), typename  = decltype(swap(std::declval<_Up>(), std::declval<_Tp>()))> static std::true_type __test(int);
            template <typename , typename > static std::false_type __test(...);
        };
        struct __do_is_nothrow_swappable_with_impl {
            template <typename _Tp, typename _Up> static __bool_constant<noexcept(swap(std::declval<_Tp>(), std::declval<_Up>())) && noexcept(swap(std::declval<_Up>(), std::declval<_Tp>()))> __test(int);
            template <typename , typename > static std::false_type __test(...);
        };
    }
    template <typename _Tp, typename _Up> struct __is_swappable_with_impl : public __swappable_with_details::__do_is_swappable_with_impl {
        typedef decltype(__test<_Tp, _Up>(0)) type;
    };
    template <typename _Tp> struct __is_swappable_with_impl<type-parameter-0-0 &, type-parameter-0-0 &> : public __swappable_details::__do_is_swappable_impl {
        typedef decltype(__test<_Tp &>(0)) type;
    };
    template <typename _Tp, typename _Up> struct __is_nothrow_swappable_with_impl : public __swappable_with_details::__do_is_nothrow_swappable_with_impl {
        typedef decltype(__test<_Tp, _Up>(0)) type;
    };
    template <typename _Tp> struct __is_nothrow_swappable_with_impl<type-parameter-0-0 &, type-parameter-0-0 &> : public __swappable_details::__do_is_nothrow_swappable_impl {
        typedef decltype(__test<_Tp &>(0)) type;
    };
    template <typename _Tp, typename _Up> struct is_swappable_with : public __is_swappable_with_impl<_Tp, _Up>::type {
    };
    template <typename _Tp, typename _Up> struct is_nothrow_swappable_with : public __is_nothrow_swappable_with_impl<_Tp, _Up>::type {
    };
    template <typename _Tp, typename _Up> constexpr bool is_swappable_with_v = is_swappable_with<_Tp, _Up>::value;
    template <typename _Tp, typename _Up> constexpr bool is_nothrow_swappable_with_v = is_nothrow_swappable_with<_Tp, _Up>::value;
    template <typename _Result, typename _Ret, typename  = void> struct __is_invocable_impl : std::false_type {
    };
    template <typename _Result, typename _Ret> struct __is_invocable_impl<_Result, _Ret, void> : __or_<is_void<_Ret>, is_convertible<typename _Result::type, _Ret> >::type {
    };
    template <typename _Fn, typename ..._ArgTypes> struct __is_invocable : __is_invocable_impl<__invoke_result<_Fn, _ArgTypes...>, void>::type {
    };
    template <typename _Fn, typename _Tp, typename ..._Args> constexpr bool __call_is_nt(std::__invoke_memfun_ref)     {
        using _Up = typename __inv_unwrap<_Tp>::type;
        return noexcept((std::declval<_Up>() .* std::declval<_Fn>())(std::declval<_Args>()...));
    }
    template <typename _Fn, typename _Tp, typename ..._Args> constexpr bool __call_is_nt(std::__invoke_memfun_deref)     {
        return noexcept(((*std::declval<_Tp>()) .* std::declval<_Fn>())(std::declval<_Args>()...));
    }
    template <typename _Fn, typename _Tp> constexpr bool __call_is_nt(std::__invoke_memobj_ref)     {
        using _Up = typename __inv_unwrap<_Tp>::type;
        return noexcept(std::declval<_Up>() .* std::declval<_Fn>());
    }
    template <typename _Fn, typename _Tp> constexpr bool __call_is_nt(std::__invoke_memobj_deref)     {
        return noexcept((*std::declval<_Tp>()) .* std::declval<_Fn>());
    }
    template <typename _Fn, typename ..._Args> constexpr bool __call_is_nt(std::__invoke_other)     {
        return noexcept(std::declval<_Fn>()(std::declval<_Args>()...));
    }
    template <typename _Result, typename _Fn, typename ..._Args> struct __call_is_nothrow : __bool_constant<std::__call_is_nt<_Fn, _Args...>(typename _Result::__invoke_type({}))> {
    };
    template <typename _Fn, typename ..._Args> using __call_is_nothrow_ = __call_is_nothrow<__invoke_result<_Fn, _Args...>, _Fn, _Args...>;
    template <typename _Fn, typename ..._Args> struct __is_nothrow_invocable : __and_<__is_invocable<_Fn, _Args...>, __call_is_nothrow_<_Fn, _Args...> >::type {
    };
    struct __nonesuch {
        __nonesuch() = delete
        ~__nonesuch() = delete
        __nonesuch(const std::__nonesuch &) = delete
        void operator=(const std::__nonesuch &) = delete
    };
}
namespace lsc {
    template <int x> struct number {
        using value = number<x>;
        static constexpr int instance = x;
    };
    template <bool x> struct boolean {
        using value = boolean<x>;
        static constexpr bool instance = x;
    };
    template <typename a, typename b> struct add {
        using value = number<a::value::instance + b::value::instance>;
    };
    template <typename x> struct test {
        using value = typename x::p;
    };
    struct a {
    };
}
using namespace lsc;
int main() {
    using temp = test<lsc::a>;
}
