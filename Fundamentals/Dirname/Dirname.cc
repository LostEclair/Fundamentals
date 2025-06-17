// Copyright 2025 Tema
// SPDX-License-Identifier: Apache-2.0

/// @brief An implementation of the dirname(1) command
/// @file Fundamentals/Dirname/Dirname.cc

#include "Dirname.hh"

#include <libgen.h>

#include <Common.hh>
#include <iostream>

int main(int argc, char** argv) {
  if (argc <= 1)
    Fundamentals::Common::usage(Fundamentals::Dirname::ProgramName,
                                Fundamentals::Dirname::UsageString);

  for (int i = 1; i < argc; i++) std::cout << dirname(argv[i]) << '\n';

  return Fundamentals::Common::ExitCodes::Success;
}
