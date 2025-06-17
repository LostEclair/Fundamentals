// Copyright 2025 Tema
// SPDX-License-Identifier: Apache-2.0

/// @brief An implementation of the uname command
/// @file Fundamentals/Uname/Uname.cc

#include "Uname.hh"

#include <sys/utsname.h>
#include <unistd.h>

#include <Common.hh>
#include <cerrno>
#include <cstring>

int main(int argc, char **argv) {
  short parameters{};

  int option;
  while ((option = getopt(argc, argv,
                          Fundamentals::Uname::ShortOpts.c_str())) != -1) {
    switch (option) {
      case 'a':
        parameters = Fundamentals::Uname::ShowHardwareType |
                     Fundamentals::Uname::ShowNodeName |
                     Fundamentals::Uname::ShowOSRelease |
                     Fundamentals::Uname::ShowOSImplementationName |
                     Fundamentals::Uname::ShowOSVersion;
        break;
      case 'm':
        parameters |= Fundamentals::Uname::ShowHardwareType;
        break;
      case 'n':
        parameters |= Fundamentals::Uname::ShowNodeName;
        break;
      case 'r':
        parameters |= Fundamentals::Uname::ShowOSRelease;
        break;
      case 's':
        parameters |= Fundamentals::Uname::ShowOSImplementationName;
        break;
      case 'v':
        parameters |= Fundamentals::Uname::ShowOSVersion;
        break;
      case '#':
        Fundamentals::Common::tellVersion();
      case '?':
      default:
        Fundamentals::Common::usage(Fundamentals::Uname::ProgramName,
                                    Fundamentals::Uname::UsageString);
    }
  }

  if (optind != argc)
    Fundamentals::Common::usage(Fundamentals::Uname::ProgramName,
                                Fundamentals::Uname::UsageString);

  // Eqivalent to -s flag being passed.
  if (!parameters) parameters = Fundamentals::Uname::ShowOSImplementationName;

  utsname systemInformation;
  if (uname(&systemInformation))
    Fundamentals::Common::errorOut(
        Fundamentals::Common::ExitCodes::Failure,
        "The uname(2) function had returned an error: {}",
        std::strerror(errno));

  if (parameters & Fundamentals::Uname::ShowOSImplementationName)
    Fundamentals::Uname::showSpaced(systemInformation.sysname);
  if (parameters & Fundamentals::Uname::ShowNodeName)
    Fundamentals::Uname::showSpaced(systemInformation.nodename);
  if (parameters & Fundamentals::Uname::ShowOSRelease)
    Fundamentals::Uname::showSpaced(systemInformation.release);
  if (parameters & Fundamentals::Uname::ShowOSVersion)
    Fundamentals::Uname::showSpaced(systemInformation.version);
  if (parameters & Fundamentals::Uname::ShowHardwareType)
    Fundamentals::Uname::showSpaced(systemInformation.machine);

  std::cout << "\n";

  return Fundamentals::Common::ExitCodes::Success;
}

void Fundamentals::Uname::showSpaced(const std::string &text) {
  static bool wasUsedBefore = false;
  if (wasUsedBefore) std::cout << " ";
  wasUsedBefore = true;

  std::cout << text;
}
