// Copyright 2025 Tema
// SPDX-License-Identifier: Apache-2.0

/// @brief An implementation of the echo(1) command
/// @file Fundamentals/Echo/Echo.cc

#include <Common.hh>
#include <iostream>

int main(int argc, char **argv) {
  (void)argc;
  argv++;

  while (*argv) {
    std::cout << *argv;
    if (*argv++) std::cout << ' ';
  }
  std::cout << '\n';

  return Fundamentals::Common::ExitCodes::Success;
}
