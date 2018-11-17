/*
 * Created: 17-11-2018
 * Copyright (c) 2018 Jonas R. Glesaaen (jonas@glesaaen.com)
 */

#include <algorithm>
#include <array>
#include <chrono>
#include <iostream>
#include <random>
#include <sstream>

#include "fast_divisibility/fast_divisibility.hpp"

using namespace irubataru::tmp;

constexpr std::uint32_t TEST_EVERY_NUMBER_TO = 1000;
constexpr std::uint32_t RANDOM_TESTS = 1000;

constexpr std::uint32_t VALUE = 17;

void test_divisibility(std::uint32_t a)
{
  bool test = a * quotient_p<VALUE>::value <= quotient_q<VALUE>::value;
  bool expected = a % VALUE == 0;

  if (test != expected) {
    std::ostringstream error_message;
    error_message << "Test failed for " << a << " divisible by " << VALUE;
    throw std::runtime_error{error_message.str()};
  }
}

int main(int, char **)
{
  try {
    for (auto i = 3; i <= TEST_EVERY_NUMBER_TO; ++i) {
      test_divisibility(i);
    }

    std::random_device rd{};
    std::mt19937 rng{rd()};
    std::uniform_int_distribution<std::uint32_t> dist{
        0, std::numeric_limits<std::uint32_t>::max()};

    for (auto i = 0; i <= RANDOM_TESTS; ++i) {
      test_divisibility(dist(rng));
    }
  } catch (std::runtime_error &err) {
    std::cout << err.what() << "\n";
    return 1;
  }

  std::cout << "Test succeeded\n";
  return 0;
}
