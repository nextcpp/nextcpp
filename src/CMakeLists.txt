set(LIBRARY_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/utils.ixx"
    "${CMAKE_CURRENT_SOURCE_DIR}/partitions/utils-print.ixx"
    "${CMAKE_CURRENT_SOURCE_DIR}/partitions/utils-helloworld.ixx"
    "${CMAKE_CURRENT_SOURCE_DIR}/partitions/utils-mynumber.ixx")

add_library(${LIBRARY_NAME})
target_sources(${LIBRARY_NAME} PRIVATE
               FILE_SET cxx_modules
               TYPE CXX_MODULES
               FILES ${LIBRARY_SOURCES})
target_include_directories(${LIBRARY_NAME} PUBLIC ${LIBRARY_INCLUDES})

if (${ENABLE_WARNINGS})
    target_set_warnings(
        TARGET
        ${LIBRARY_NAME}
        ENABLE
        ${ENABLE_WARNINGS}
        AS_ERRORS
        ${ENABLE_WARNINGS_AS_ERRORS})
endif()

if(${ENABLE_LTO})
    target_enable_lto(
        TARGET
        ${LIBRARY_NAME}
        ENABLE
        ON)
endif()

if(${ENABLE_CLANG_TIDY})
    add_clang_tidy_to_target(${LIBRARY_NAME})
endif()
