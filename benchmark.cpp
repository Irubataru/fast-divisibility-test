/*
 * Created: 17-11-2018
 * Copyright (c) 2018 Jonas R. Glesaaen (jonas@glesaaen.com)
 */

#include <algorithm>
#include <array>
#include <chrono>
#include <iostream>
#include <random>

#include "fast_divisibility/fast_divisibility.hpp"

using namespace irubataru::tmp;
using namespace std::chrono;

#define FASTALG

constexpr std::size_t TEST_CASES{1000000};
constexpr std::uint32_t VALUE = 17;

int main(int, char **)
{
  std::random_device rd{};
  std::mt19937 rng{rd()};
  std::uniform_int_distribution<std::uint32_t> dist{
      5, std::numeric_limits<std::uint32_t>::max()};

  std::array<std::uint32_t, TEST_CASES> tests;
  std::array<char, TEST_CASES> results;

  for (auto &test : tests) {
    test = dist(rng);
  }

  auto start_time = high_resolution_clock::now();

  for (auto i = 0; i < tests.size(); ++i) {
#ifdef FASTALG
    results[i] = is_divisible<VALUE>(tests[i]);
#else
    results[i] = tests[i] % VALUE == 0;
#endif
  }

  auto end_time = high_resolution_clock::now();

#ifdef FASTALG
  std::cout << "Fast:        "
#else
  std::cout << "Traditional: "
#endif
            << duration_cast<microseconds>(end_time - start_time).count()
            << "ms\n";

  // Make sure that -O3 cannot cut the function short in any way
  std::shuffle(results.begin(), results.end(), rng);
  return results[0];
}
