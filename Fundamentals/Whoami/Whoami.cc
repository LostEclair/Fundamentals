// Copyright 2025 Tema
// SPDX-License-Identifier: Apache-2.0

/// @brief An implementation of the whoami(1) command
/// @file Fundamentals/Whoami/Whoami.cc

#include <pwd.h>
#include <unistd.h>

#include <Common.hh>
#include <iostream>

int main(void) {
  int userID;

  if ((userID = geteuid()) == -1)
    Fundamentals::Common::errorOut(Fundamentals::Common::ExitCodes::Failure,
                                   "Failed to obtain user id");

  std::cout << getpwuid(userID)->pw_name << '\n';

  return Fundamentals::Common::ExitCodes::Success;
}
