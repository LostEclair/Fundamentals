// Copyright 2025 Tema
// SPDX-License-Identifier: Apache-2.0

/// @brief Fundamentals common code interface
/// @file Fundamentals/CommonCode/Common.hh

#pragma once

#include <cstdlib>
#include <format>
#include <iostream>

namespace Fundamentals::Common {

namespace ExitCodes {

/// @brief Is 0
constexpr int Success{EXIT_SUCCESS};

/// @brief Is 1
constexpr int Failure{EXIT_FAILURE};

}  // namespace ExitCodes

/// @brief Show usage message and then, quit (with exit code 1)
[[noreturn]] void usage(const std::string &programName,
                        const std::string &usageString);

/// @brief Error out with formatted message
/// The newline is automatically printed.
template <typename... TArguments>
[[noreturn]] void errorOut(const int exitCode,
                           const std::string_view &formatting,
                           TArguments &&...arguments) {
  std::cerr << "Error: "
            << std::vformat(formatting, std::make_format_args(arguments...))
            << "\n";

  std::exit(exitCode);
}

/// @brief Print a formatted warning message
/// Unlike the Fundamentals::Common::errorOut, it won't exit.
/// The newline is automatically printed.
template <typename... TArguments>
void warning(const std::string_view &formatting, TArguments &&...arguments) {
  std::cerr << "Warning: "
            << std::vformat(formatting, std::make_format_args(arguments...))
            << "\n";
}

/// @brief Tell the Fundamentals version and then, quit (with exit code 1)
[[noreturn]] void tellVersion();

}  // namespace Fundamentals::Common
