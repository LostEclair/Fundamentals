// Copyright 2025 Tema
// SPDX-License-Identifier: Apache-2.0

/// @brief An implementation of the basename(1) command
/// @file Fundamentals/Basename/Basename.cc

#include "Basename.hh"

#include <libgen.h>

#include <Common.hh>
#include <iostream>
#include <string_view>

int main(int argc, char** argv) {
  if (argc <= 1 || argc >= 4)
    Fundamentals::Common::usage(Fundamentals::Basename::ProgramName,
                                Fundamentals::Basename::UsageString);

  std::string_view fileName = basename(argv[1]);
  const std::string suffix = argc == 3 ? argv[2] : "";

  if (!suffix.empty() && fileName.length() > suffix.length() &&
      fileName.ends_with(suffix))
    fileName.remove_suffix(suffix.length());

  std::cout << fileName << '\n';

  return Fundamentals::Common::ExitCodes::Success;
}
