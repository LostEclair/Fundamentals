// Copyright 2025 Tema
// SPDX-License-Identifier: Apache-2.0

#pragma once

#include <fstream>
#include <string>

namespace Fundamentals::Cat {

void writeToStdout(std::istream&);

constexpr std::string UseStdinCharacter{"-"};

const std::string ProgramName{"cat"};
const std::string UsageString{"[-u] [file...]"};
const std::string ShortOpts{"#u"};

}  // namespace Fundamentals::Cat
