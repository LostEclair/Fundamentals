// Copyright 2025 Tema
// SPDX-License-Identifier: Apache-2.0

/// @brief An implementation of the Fundamentals common code interface
/// @file Fundamentals/CommonCode/Common.cc

#include "Common.hh"

#include <BuildConfig.h>

#include <iostream>

[[noreturn]] void Fundamentals::Common::usage(const std::string &programName,
                                              const std::string &usageString) {
  const std::string errorFormatting{
      "Incorrect use of the {0} command.\n"
      "Usage: {0} {1}"
#if MFundamentalsWereCompiledWithManPages
      "\n"
      "Tip: You can also run \"man {0}\" for more information."
#endif
  };

  Fundamentals::Common::errorOut(Fundamentals::Common::ExitCodes::Failure,
                                 errorFormatting, programName, usageString);
}

[[noreturn]] void Fundamentals::Common::tellVersion() {
  std::cerr << "This is Fundamentals/" << MFundamentalsVersion << ". "
            << "This build was compiled at " << __DATE__ << " " << __TIME__
            << "\n\n"
            << "Licensed under the Apache License 2.0"
            << "\n"
            << "See <http://www.apache.org/licenses/LICENSE-2.0> for more "
               "information."
            << "\n";

  std::exit(Fundamentals::Common::ExitCodes::Failure);
}
