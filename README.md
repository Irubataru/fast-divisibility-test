# Fast divisibility testing

This is an implementation of [this]() wonderful article about fast divisibilit
testing for fixed length integers using template metaprogramming in C++. It is
one of those WIP projects that might never actually be finished, so at the
moment it only works for 32-bit odd unsigned integers.

It is coded in a "traditional" template metaprogramming style, i.e. without
`constexpr` and without using any TMP libraries. A port to a more modern
metaprogramming style should be fairly straight forward.

## Testing

The code basically implements a single function:

```cpp
template <std::uint32_t N>
bool is_divisible(std::uint32_t m)
```

that returns whether `m` is divisible by the template argument `N`. There are
two main functions. One that runs random tests and sees if it behaves the same
as the more traditional `m % N == 0`, and another for benchmarking. The code is
fairly crude.

## License and copyright

Copyright 2018 Jonas R. Glesaaen. Licensed under the MIT license.
