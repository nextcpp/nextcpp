function(target_enable_lto)
    set(oneValueArgs TARGET ENABLE)
    cmake_parse_arguments(
        LTO
        "${options}"
        "${oneValueArgs}"
        "${multiValueArgs}"
        ${ARGN})

    include(CheckIPOSupported)
    check_ipo_supported(RESULT result OUTPUT output)
    if(result)
        message(STATUS "IPO/LTO is supported: ${LTO_TARGET}")
        set_property(TARGET ${LTO_TARGET} PROPERTY INTERPROCEDURAL_OPTIMIZATION
                                                   TRUE)
        if(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
            target_link_options(${LTO_TARGET} INTERFACE /INCREMENTAL:NO /LTCG)
        endif()
    else()
        message(WARNING "IPO/LTO is not supported. Target: ${LTO_TARGET}. ERROR: ${output}")
    endif()
endfunction()
