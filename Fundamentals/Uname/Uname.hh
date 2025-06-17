// Copyright 2025 Tema
// SPDX-License-Identifier: Apache-2.0

#pragma once

#include <string>

namespace Fundamentals::Uname {

const std::string ProgramName{"uname"};
const std::string UsageString{"[-amnrsv]"};
const std::string ShortOpts{"#amnrsv"};

const short ShowHardwareType{1 << 0};
const short ShowNodeName{1 << 1};
const short ShowOSRelease{1 << 2};
const short ShowOSImplementationName{1 << 3};
const short ShowOSVersion{1 << 4};

/// @brief Show text, properly separated by spaces
void showSpaced(const std::string &text);

}  // namespace Fundamentals::Uname
