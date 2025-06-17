// Copyright 2025 Tema
// SPDX-License-Identifier: Apache-2.0

/// @brief An implementation of the sleep(1) command
/// @file Fundamentals/Sleep/Sleep.cc

#include "Sleep.hh"

#include <Common.hh>
#include <chrono>
#include <thread>

int main(int argc, char **argv) {
  if (argc != 2)
    Fundamentals::Common::usage(Fundamentals::Sleep::ProgramName,
                                Fundamentals::Sleep::UsageString);

  const std::string providedDuration{argv[1]};
  try {
    const std::chrono::duration<float> sleepDuration{
        std::stof(providedDuration)};

    if (sleepDuration.count() < 0)
      Fundamentals::Common::errorOut(Fundamentals::Common::ExitCodes::Failure,
                                     "Looks like the value {} is negative",
                                     providedDuration);

    std::this_thread::sleep_for(sleepDuration);
  } catch (const std::invalid_argument &_) {
    Fundamentals::Common::errorOut(
        Fundamentals::Common::ExitCodes::Failure,
        "Looks like the value \"{}\" is not a number or float",
        providedDuration);
  } catch (const std::out_of_range &_) {
    Fundamentals::Common::errorOut(
        Fundamentals::Common::ExitCodes::Failure,
        "Looks like the value {} is too big (or small)", providedDuration);
  }

  return Fundamentals::Common::ExitCodes::Success;
}
