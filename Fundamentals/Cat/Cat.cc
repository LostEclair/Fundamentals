// Copyright 2025 Tema
// SPDX-License-Identifier: Apache-2.0

/// @brief An implementation of the cat(1) command
/// @file Fundamentals/Cat/Cat.cc

#include "Cat.hh"

#include <unistd.h>

#include <Common.hh>
#include <fstream>

int main(int argc, char** argv) {
  bool hasFailed{};

  std::ios::sync_with_stdio(false);

  int option;
  while ((option = getopt(argc, argv, Fundamentals::Cat::ShortOpts.c_str())) !=
         -1) {
    switch (option) {
      case 'u':
        // Unbuffered by default.
        break;
      case '#':
        Fundamentals::Common::tellVersion();
      default:
        Fundamentals::Common::usage(Fundamentals::Cat::ProgramName,
                                    Fundamentals::Cat::UsageString);
    }
  }

  if (argc - optind == 0) {
    Fundamentals::Cat::writeToStdout(std::cin);
    return Fundamentals::Common::ExitCodes::Success;
  }

  for (int i{optind}; i < argc; ++i) {
    if (!Fundamentals::Cat::UseStdinCharacter.compare(argv[i])) {
      Fundamentals::Cat::writeToStdout(std::cin);
      continue;
    }

    std::ifstream stream;
    stream.exceptions(std::ifstream::failbit | std::ifstream::badbit);

    try {
      stream.open(argv[i]);
      Fundamentals::Cat::writeToStdout(stream);
    } catch (const std::system_error& errorContext) {
      hasFailed = true;

      // FIXME: Figure out how to make a better error message for this one
      Fundamentals::Common::warning("Failed to open \"{}\": {}", argv[i],
                                    errorContext.what());
    }
  }

  return hasFailed;
}

void Fundamentals::Cat::writeToStdout(std::istream& stream) {
  if (stream.bad()) return;
  stream.clear();
  std::cout << stream.rdbuf();
}
