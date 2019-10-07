/**
 * Test harness for other files.
 *
 * Usage:
 * First argument is the executable to test. Tries exe then exe.exe.
 * Then exe is called as such:
 * exe
 * This exe should read from exe.in and output to exe.out. If exe.out is not
 * the same as exe.expected, a diff will be created and printed to STDERR.
 * The program will exit with an error.
 *
 * exe.in and exe.expected are expected to be in $PWD/exe.
 *
 * Some notes:
 *  - The program is written for portable C++17 (not C++11 like the task
 *  solutions, as we are not bound by those constraints). So, sometimes it
 *  may be reimplementing a solution from a popular library (e.g. Boost).
 *  - This is a _test harness_. As such, it does not have multi-test support,
 *  and that is expected to be provided by a higher-level system (e.g. CMake).
 *  - Windows support is still a little spotty. Standard libraries are used
 *  where available, and POSIX otherwise, so we accept contributors to add
 *  Windows support!
 */

/* Setup platform. */
#if defined(_WIN32) && defined(_POSIX)
#    undef _POSIX
#else
#    define _POSIX
#endif

#include <random>

#if !defined(MACOS_CATALINA) && defined(__APPLE__)
#    include "ghc/filesystem.hpp"
namespace fs = ghc::filesystem;
#else
#    include <filesystem>
namespace fs = std::filesystem;
#endif

namespace util
{
    /**
     * Create a temporary directory and change location to it.
     */
    void chdtemp()
    {
        // We only generate one random number, so no need to create a PRNG
        std::random_device dev;
        std::uniform_int_distribution distribution(1, 10000);
        std::string random_path_suffix = std::to_string(distribution(dev));
        fs::path tmpdir = fs::temp_directory_path();
        tmpdir /= random_path_suffix;
        fs::create_directories(tmpdir);
        fs::current_path(tmpdir);
    }
}; // namespace util

int main(int argc, char** argv) { util::chdtemp(); }