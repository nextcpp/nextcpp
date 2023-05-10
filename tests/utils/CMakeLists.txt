set(UNITTEST_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/tests_utils.cpp")

add_executable(${UNIT_TEST_NAME} ${UNITTEST_SOURCES})
target_link_libraries(${UNIT_TEST_NAME} PRIVATE
                      GTest::gtest
                      GTest::gtest_main
                      GTest::gmock
                      GTest::gmock_main
                      ${LIBRARY_NAME})
gtest_discover_tests(${UNIT_TEST_NAME})

target_set_warnings(
        TARGET
        ${UNIT_TEST_NAME}
        ENABLE
        ${ENABLE_WARNINGS}
        AS_ERRORS
        ${ENABLE_WARNINGS_AS_ERRORS})


# Unix Only
# Creates a coverage folder in the BINARY_DIR with some html info on the coverage
if(ENABLE_COVERAGE)
    set(COVERAGE_MAIN "coverage")
    set(COVERAGE_EXCLUDES
        "${PROJECT_SOURCE_DIR}/app/*"
        "${PROJECT_SOURCE_DIR}/cmake/*"
        "${PROJECT_SOURCE_DIR}/docs/*"
        "${PROJECT_SOURCE_DIR}/external/*"
        "${PROJECT_SOURCE_DIR}/tests/*"
        "${PROJECT_SOURCE_DIR}/build/*"
        "/usr/include/*")
    setup_target_for_coverage_lcov(
        NAME
        ${COVERAGE_MAIN}
        EXECUTABLE
        ${UNIT_TEST_NAME}
        DEPENDENCIES
        ${UNIT_TEST_NAME})
endif()
