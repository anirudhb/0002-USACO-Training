cmake_minimum_required(VERSION 3.12)
project(0002_USACO_Training)

set(CMAKE_CXX_STANDARD 11)

# I'm not renaming the test target for this :/
if (POLICY CMP0037)
    cmake_policy(SET CMP0037 OLD)
endif ()

add_executable(test_harness test_harness.cc)
set_property(TARGET test_harness PROPERTY CXX_STANDARD 17)
# Link with homebrew-provided libc++ on macOS
# comment this out if you are not using homebrew-provided clang/clang++
if (APPLE)
    target_link_directories(test_harness PRIVATE /usr/local/opt/llvm/lib)
    target_link_options(test_harness PRIVATE -Wl,-rpath,/usr/local/opt/llvm/lib)

    execute_process(COMMAND sw_vers -productVersion OUTPUT_VARIABLE swversion)
    string(REGEX MATCH "\\d+\\.\\d+" macosversion swversion)
    if (macosversion GREATER_EQUAL 10.15)
        set(iscatalina TRUE)
    endif ()
endif ()

add_executable(test test.cc)
add_executable(ride ride.cc)
add_executable(gift1 gift1.cc)
add_executable(friday friday.cc)

enable_testing()

add_test(test_test test_harness test)

target_include_directories(test_harness PRIVATE filesystem/include)

if (iscatalina)
    target_compile_definitions(test_harness PRIVATE MACOS_CATALINA)
endif ()