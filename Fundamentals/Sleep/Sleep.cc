// Copyright 2025 Tema
// SPDX-License-Identifier: Apache-2.0

/// @brief An implementation of the sleep(1) command
/// @file Fundamentals/Sleep/Sleep.cc

#include "Sleep.hh"

#include <Common.hh>
#include <chrono>
#include <climits>
#include <csignal>
#include <stdexcept>
#include <string>
#include <thread>

int main(int argc, char **argv) {
  if (argc != 2)
    Fundamentals::Common::usage(Fundamentals::Sleep::ProgramName,
                                Fundamentals::Sleep::UsageString);

  signal(SIGALRM, [](int) noexcept {
    std::exit(Fundamentals::Common::ExitCodes::Success);
  });

  const std::string userInput{argv[1]};

  try {
    size_t stofLastPosition;
    const unsigned long seconds{std::stoul(userInput, &stofLastPosition, 10)};
    if (stofLastPosition != userInput.size())
      Fundamentals::Common::errorOut(
          Fundamentals::Common::ExitCodes::Failure,
          "String \"{}\" contains non-numerical characters", userInput);

    const std::chrono::seconds sleepDuration(seconds);
    std::this_thread::sleep_for(sleepDuration);
  } catch (const std::invalid_argument &_) {
    Fundamentals::Common::errorOut(
        Fundamentals::Common::ExitCodes::Failure,
        "String \"{}\" does not contain any integers.", userInput);
  } catch (const std::out_of_range &_) {
    Fundamentals::Common::errorOut(
        Fundamentals::Common::ExitCodes::Failure,
        "Value {} is not in the range of an unsigned long integer (From 0 to {})",
        userInput, ULONG_MAX);
  }

  std::signal(SIGALRM, SIG_DFL);
  return Fundamentals::Common::ExitCodes::Success;
}
