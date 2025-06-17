// Copyright 2025 Tema
// SPDX-License-Identifier: Apache-2.0

/// @brief An implementation of the mv(1) command
/// @file Fundamentals/Mv/Mv.cc

#include "Mv.hh"

#include <unistd.h>

#include <Common.hh>
#include <filesystem>

int main(int argc, char** argv) {
  bool confirm{false};  // TODO: Implement -i

  int option;
  while ((option = getopt(argc, argv, Fundamentals::Mv::ShortOpts.c_str())) !=
         -1) {
    switch (option) {
      case 'i':
        confirm = true;
        break;
      case 'f':
        confirm = false;
        break;
      case '#':
        Fundamentals::Common::tellVersion();
      default:
        Fundamentals::Common::usage(Fundamentals::Mv::ProgramName,
                                    Fundamentals::Mv::UsageString);
    }
  }

  const int fileCount = argc - optind;

  if (fileCount < 2)
    Fundamentals::Common::usage(Fundamentals::Mv::ProgramName,
                                Fundamentals::Mv::UsageString);

  const std::filesystem::path target{
      std::filesystem::weakly_canonical(argv[argc - 1])};

  for (int i{optind}; i < argc - 1; ++i) {
    const std::filesystem::path source{argv[i]};

    if (!std::filesystem::exists(source))
      Fundamentals::Common::errorOut(Fundamentals::Common::ExitCodes::Failure,
                                     "File \"{}\" does not exist",
                                     source.native());

    if (fileCount > 2 && !std::filesystem::is_directory(target))
      Fundamentals::Common::errorOut(Fundamentals::Common::ExitCodes::Failure,
                                     "File \"{}\" is not a directory",
                                     target.native());

    try {
      const std::filesystem::path destination{
          std::filesystem::is_directory(target) ? target / source.filename()
                                                : target};
      std::filesystem::rename(source, destination);
    } catch (const std::filesystem::filesystem_error& errorContext) {
      if (errorContext.code() == std::errc::cross_device_link)
        Fundamentals::Mv::moveByCopying(source, target);
      else
        Fundamentals::Common::warning("Failed to move \"{}\" ({})",
                                      source.native(), errorContext.what());
    }
  }

  return Fundamentals::Common::ExitCodes::Success;
}

void Fundamentals::Mv::moveByCopying(const std::filesystem::path& source,
                                     const std::filesystem::path& target) {
  const std::filesystem::path destination{std::filesystem::is_directory(target)
                                              ? target / source.filename()
                                              : target};

  try {
    std::filesystem::copy(source, destination);
    std::filesystem::remove_all(source);
  } catch (const std::filesystem::filesystem_error& errorContext) {
    Fundamentals::Common::warning(
        "Failed to copy (or remove) a file: From \"{}\" to \"{}\""
        "(Exception: {})",
        source.native(), destination.native(), errorContext.what());
  }
}
