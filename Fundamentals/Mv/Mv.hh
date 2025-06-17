// Copyright 2025 Tema
// SPDX-License-Identifier: Apache-2.0

#pragma once

#include <filesystem>
#include <string>

namespace Fundamentals::Mv {

const std::string ProgramName{"mv"};
const std::string UsageString{"[-fi]"};
const std::string ShortOpts{"#fi"};

/// @brief Copies a file to given place and removes an original file.
void moveByCopying(const std::filesystem::path& source,
                   const std::filesystem::path& target);

}  // namespace Fundamentals::Mv
