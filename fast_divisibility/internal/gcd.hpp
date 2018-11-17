
/*
 * Created: 17-11-2018
 * Copyright (c) 2018 Jonas R. Glesaaen (jonas@glesaaen.com)
 */

#ifndef GCD_HPP
#define GCD_HPP

#include "integers.hpp"

namespace irubataru {
namespace tmp {

template <typename r, typename old_r, typename carry, typename old_carry>
struct extended_gcd
    : extended_gcd<
          typename subtract<old_r,
                            typename multiply<typename divide<old_r, r>::type,
                                              r>::type>::type,
          r,
          typename subtract<old_carry,
                            typename multiply<typename divide<old_r, r>::type,
                                              carry>::type>::type,
          carry>
{
};

template <typename old_r, typename carry, typename old_carry>
struct extended_gcd<integer_long<0>, old_r, carry, old_carry>
    : integer_long<old_carry::value>
{
};

template <std::uint64_t a, std::uint64_t b>
struct gcd : extended_gcd<integer_long<b>, integer_long<a>, integer_long<b>, integer_long<a>> {};

template <std::uint64_t a, std::uint64_t b>
struct gcd_s : extended_gcd<integer_long<b>, integer_long<a>, integer_long<0>, integer_long<1> > {};

} // namespace tmp
} // namespace irubataru

#endif /* GCD_HPP */
