/*
 * Created: 17-11-2018
 * Copyright (c) 2018 Jonas R. Glesaaen (jonas@glesaaen.com)
 */

#ifndef INTEGERS_HPP
#define INTEGERS_HPP

#include <cstdint>

namespace irubataru {
namespace tmp {

template <std::uint32_t N>
struct integer
{
  using type = integer;
  static constexpr std::uint32_t value = N;
};

template <std::uint64_t N>
struct integer_long
{
  using type = integer_long;
  static constexpr std::uint64_t value = N;
};

template <typename t>
struct to_integer : integer<std::uint32_t{t::value}>
{
};

struct integer_upper : integer_long<(std::uint64_t{1} << 32)>
{
};

template <typename a, typename b>
struct add;

template <std::uint32_t a, std::uint32_t b>
struct add<integer<a>, integer<b>> : integer<a + b>
{
};

template <std::uint64_t a, std::uint64_t b>
struct add<integer_long<a>, integer_long<b>> : integer_long<a + b>
{
};

template <typename a, typename b>
struct subtract;

template <std::uint32_t a, std::uint32_t b>
struct subtract<integer<a>, integer<b>> : integer<a - b>
{
};

template <std::uint64_t a, std::uint64_t b>
struct subtract<integer_long<a>, integer_long<b>> : integer_long<a - b>
{
};

template <typename a, typename b>
struct multiply;

template <std::uint32_t a, std::uint32_t b>
struct multiply<integer<a>, integer<b>> : integer<a * b>
{
};

template <std::uint64_t a, std::uint64_t b>
struct multiply<integer_long<a>, integer_long<b>> : integer_long<a * b>
{
};

template <typename a, typename b>
struct divide;

template <std::uint32_t a, std::uint32_t b>
struct divide<integer<a>, integer<b>> : integer<a / b>
{
};

template <std::uint64_t a, std::uint64_t b>
struct divide<integer_long<a>, integer_long<b>> : integer_long<a / b>
{
};

template <typename a, typename b>
struct modulus;

template <std::uint32_t a, std::uint32_t b>
struct modulus<integer<a>, integer<b>> : integer<a % b>
{
};

template <std::uint64_t a, std::uint64_t b>
struct modulus<integer_long<a>, integer_long<b>> : integer_long<a % b>
{
};

} // namespace tmp
} // namespace irubataru

#endif /* INTEGERS_HPP */
