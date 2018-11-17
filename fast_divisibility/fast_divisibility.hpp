/*
 * Created: 17-11-2018
 * Copyright (c) 2018 Jonas R. Glesaaen (jonas@glesaaen.com)
 */

#ifndef FAST_DIVISIBILITY_HPP
#define FAST_DIVISIBILITY_HPP

#include "internal/gcd.hpp"
#include "internal/integers.hpp"

namespace irubataru {
namespace tmp {

template <std::uint32_t N>
struct quotient_q : to_integer<divide<integer_upper::type, integer_long<N>>>
{
};

template <std::uint32_t N>
struct quotient_p
    : to_integer<modulus<typename gcd_s<N, integer_upper::value>::type,
                         integer_upper::type>>
{
};

template <std::uint32_t N>
inline bool is_divisible(std::uint32_t m)
{
  return m * quotient_p<N>::value <= quotient_q<N>::value;
}

} // namespace tmp
} // namespace irubataru

#endif /* FAST_DIVISIBILITY_HPP */
