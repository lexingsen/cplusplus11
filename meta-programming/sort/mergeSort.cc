#include <iostream>
#include <utility>
#include <iterator>
#include <algorithm>

template <int... valT> 
struct isSeq 
{};

template <int... valT> 
void print(isSeq<valT...>) 
{
    static constexpr int vals[] = {valT...};
    std::copy(std::begin(vals), std::end(vals), std::ostream_iterator<int>(std::cout, " "));
    std::endl(std::cout);
}

// divide

template <typename F, typename S>
struct  divide;


template <int... fT, int xT, int ...sT>
struct divide<isSeq<fT...>, isSeq<xT, sT...>> :
    std::conditional<(sizeof...(fT) < sizeof...(sT)+1), 
        divide<isSeq<fT..., xT>, isSeq<sT...>>, 
        std::pair<isSeq<fT...>, isSeq<xT, sT...>>>::type
{};

template <int...fT> 
struct divide<isSeq<fT...>, isSeq<>> : std::pair<isSeq<fT...>, isSeq<>>
{};


// merge
template <typename R, typename F, typename S>
struct merge {};


template <int...rT>
struct merge<isSeq<rT...>, isSeq<>, isSeq<>> : std::enable_if<1, isSeq<rT...>>
{};

template <int...rT, int xT, int... fT>
struct merge<isSeq<rT...>, isSeq<xT, fT...>, isSeq<>> : std::enable_if<1, isSeq<rT..., xT, fT...>>
{};

template <int...rT, int yT, int... sT>
struct merge<isSeq<rT...>, isSeq<>, isSeq<yT, sT...>> : std::enable_if<1, isSeq<rT..., yT, sT...>>
{};

template <int...rT, int xT, int... fT, int yT, int ...sT>
struct merge<isSeq<rT...>, isSeq<xT, fT...>, isSeq<yT, sT...>> : 
    std::conditional<(xT < yT), 
        merge<isSeq<rT..., xT>, isSeq<fT...>, isSeq<yT, sT...>>,
        merge<isSeq<rT..., yT>, isSeq<xT, fT...>, isSeq<sT...>>
    >::type
{};



// sort
template <typename S>
struct sort;

template <>
struct sort<isSeq<>> : std::enable_if<1, isSeq<>> 
{};

template <int xT>
struct sort<isSeq<xT>> : std::enable_if<1, isSeq<xT>>
{};

template <int xT, int yT>
struct sort<isSeq<xT, yT>> : std::conditional<(xT < yT), isSeq<xT, yT>, isSeq<yT, xT>>
{};

template <int ...xT>
struct sort<isSeq<xT...>>
{
    using D = divide<isSeq<>, isSeq<xT...>>;
    using M = merge<isSeq<>, typename sort<typename D::first_type>::type, typename sort<typename D::second_type>::type>;
    using type = typename M::type;
    
};


int main() {
    auto a = sort<isSeq<1,6,2,5,9,0,3,4,7,8>>::type();
    return 0;
}
