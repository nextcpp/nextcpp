# >> CMAKE PROJECT
cmake_minimum_required(VERSION 3.26.3)

# >> VCPKG MANIFEST FEATURES SETUP
if(BUILD_SAMPLES)
  list(APPEND VCPKG_MANIFEST_FEATURES "samples")
endif()
# --
if(ENABLE_TESTING)
  list(APPEND VCPKG_MANIFEST_FEATURES "tests")
endif()

# >> CMAKE C++ PROJECT
project("nextcpp" VERSION 1.0.0 LANGUAGES CXX)


# GLOBAL PROJECT VARIABLES
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


# PROJECT NAME IDs
set(LIBRARY_NAME "utils_module")
set(UNIT_TEST_NAME "utils_tests")
set(EXECUTABLE_NAME "utils_app")


# CMAKE-MODULES | EXTRA TOOLING CONTROL
list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake/)
include(modules_dependency_scan_enabler)
include(Docs)
include(Tools)
include(ConfigSafeGuards)

# Warnings Control
if(ENABLE_WARNINGS)
    include(Warnings)
endif()

# Code Formatters
add_cmake_format_target()
add_clang_format_target()

# Sanitizer - UNIX-only for now
if(ENABLE_SANITIZE_ADDR OR ENABLE_SANITIZE_UNDEF)
    include(Sanitizer)
    add_sanitizer_flags()
endif()

# Code coverage and report gen with gcov and lcov - UNIX-only for now
option(ENABLE_COVERAGE "Enable a Code Coverage build." OFF)
if(ENABLE_COVERAGE)
    include(CodeCoverage)
    append_coverage_compiler_flags()
endif()

# Enables Interprocedural Optimisation
if(ENABLE_LTO)
    include(LTO)
endif()


# TESTING RELATED
## Google Test - see ./tests
include(CTest)


# CODE SUB DIRECTORIES
add_subdirectory(external)
add_subdirectory(src)
add_subdirectory(app)
add_subdirectory(tests)


# INSTALLDIR|INSTALL TARGET CONTROL
install(
    TARGETS ${EXECUTABLE_NAME}
    EXPORT ${LIBRARY_NAME}
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin)

install(
    TARGETS ${LIBRARY_NAME}
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib)
