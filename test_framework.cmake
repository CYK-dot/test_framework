## ==================================================================================
## @function 
##      enable_test_framework
## @brief 
##      Download gtest framework and build it
## ==================================================================================
function(enable_test_framework)
    if(NOT TARGET GTest::GTest)
        include(FetchContent)
        FetchContent_Declare(
            googletest
            URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.tar.gz
            DOWNLOAD_EXTRACT_TIMESTAMP TRUE
        )
        set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
        FetchContent_MakeAvailable(googletest)
    endif()
    
    enable_testing()
    include(GoogleTest)
endfunction()

## ==================================================================================
## @function 
##      add_test_executable
## @brief 
##      Create an executable target with gtest/gmock framework
## @param 
##      TARGET
##      TESTCASE_SOURCES
##      PRODUCT_LIBS
## ==================================================================================
function(add_test_executable)
    #### function args ####
    set(options "")
    set(oneValueArgs TARGET)
    set(multiValueArgs TESTCASE_SOURCES PRODUCT_LIBS)
    cmake_parse_arguments(ARG "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})
    
    # Validate arguments
    if(NOT ARG_TARGET)
        message(FATAL_ERROR "TARGET argument is required for add_test_executable")
    endif()
    
    if(NOT ARG_TESTCASE_SOURCES)
        message(FATAL_ERROR "TESTCASE_SOURCES argument is required for add_test_executable")
    endif()
    
    #### create executable ####
    add_executable(${ARG_TARGET} ${ARG_TESTCASE_SOURCES})
    
    #### link libraries ####
    target_link_libraries(${ARG_TARGET}
        PRIVATE
        GTest::gtest
        GTest::gtest_main
        ${ARG_PRODUCT_LIBS}
    )
    
    #### enable code coverage instrumentation ####
    if(CODE_COVERAGE)
        target_compile_options(${ARG_TARGET} PRIVATE --coverage)
        target_link_options(${ARG_TARGET} PRIVATE --coverage)
    endif()
    
    #### discover gtest tests ####
    # Ensure test results directory exists
    file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/test_results)
    
    gtest_discover_tests(${ARG_TARGET}
        TEST_PREFIX "${ARG_TARGET}."
        XML_OUTPUT_DIR ${CMAKE_BINARY_DIR}/test_results
    )
    
    message(STATUS "Added test executable: ${ARG_TARGET}")
endfunction()

## ==================================================================================
## @function 
##      add_coverage_target
## @brief 
##      Create a custom target to collect coverage and generate xml/html reports
## @param 
##      TARGET - name of the coverage target
##      TEST_TARGET - name of the test executable target
##      REPORT_DIR - directory for coverage reports
##      INCLUDE_PATTERNS - patterns to include in coverage
##      EXCLUDE_PATTERNS - patterns to exclude from coverage
## ==================================================================================
function(add_coverage_target)
    set(options "")
    set(oneValueArgs TARGET TEST_TARGET REPORT_DIR)
    set(multiValueArgs INCLUDE_PATTERNS EXCLUDE_PATTERNS)
    cmake_parse_arguments(ARG "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    # Validate required arguments
    if(NOT ARG_TARGET)
        message(FATAL_ERROR "TARGET argument is required for add_coverage_target")
    endif()
    
    if(NOT ARG_TEST_TARGET)
        message(FATAL_ERROR "TEST_TARGET argument is required for add_coverage_target")
    endif()
    
    # Ensure test target exists
    if(NOT TARGET ${ARG_TEST_TARGET})
        message(FATAL_ERROR "Test target '${ARG_TEST_TARGET}' does not exist")
    endif()
    
    # Set default report directory if not provided
    if(NOT ARG_REPORT_DIR)
        set(ARG_REPORT_DIR "${CMAKE_BINARY_DIR}/coverage")
    endif()
    
    # Create directory for coverage reports
    file(MAKE_DIRECTORY ${ARG_REPORT_DIR})
    
    # Set default exclude patterns if not provided
    if(NOT ARG_EXCLUDE_PATTERNS)
        set(ARG_EXCLUDE_PATTERNS
            ".*/_deps/.*"
            ".*/googletest/.*"
            ".*/gtest/.*"
            ".*/gmock/.*"
            ".*/test/.*"
            ".*/tests/.*"
            ".*/usr/include/.*"
            ".*/usr/local/include/.*"
            "/opt/.*"
            ".*[Tt]est.*"
            ".*[Mm]ock.*"
        )
    endif()
    
    # Set default include patterns if not provided
    if(NOT ARG_INCLUDE_PATTERNS)
        set(ARG_INCLUDE_PATTERNS "${CMAKE_SOURCE_DIR}/src/*")
    endif()
    
    # Find gcovr
    find_program(GCOVR_PATH gcovr)
    if(NOT GCOVR_PATH)
        message(WARNING "gcovr not found. Coverage reports will not be generated.")
        return()
    endif()
    
    # Build gcovr arguments
    set(GCOVR_ARGS "")
    
    # Add include patterns
    foreach(PATTERN ${ARG_INCLUDE_PATTERNS})
        string(REPLACE "\\" "/" PATTERN "${PATTERN}")
        if(NOT IS_ABSOLUTE "${PATTERN}")
            set(PATTERN "${CMAKE_SOURCE_DIR}/${PATTERN}")
        endif()
        list(APPEND GCOVR_ARGS "--filter" "${PATTERN}")
    endforeach()
    
    # Add exclude patterns
    foreach(PATTERN ${ARG_EXCLUDE_PATTERNS})
        string(REPLACE "\\" "/" PATTERN "${PATTERN}")
        list(APPEND GCOVR_ARGS "--exclude" "${PATTERN}")
    endforeach()
    
    # Add custom target to generate coverage report
    add_custom_target(${ARG_TARGET}
        # Run tests to generate coverage data
        COMMAND $<TARGET_FILE:${ARG_TEST_TARGET}> --gtest_output=xml:${CMAKE_BINARY_DIR}/test_results/${ARG_TEST_TARGET}.xml
        
        # Generate coverage reports
        COMMAND ${GCOVR_PATH}
            --root ${CMAKE_SOURCE_DIR}
            --object-directory ${CMAKE_BINARY_DIR}
            --xml ${ARG_REPORT_DIR}/coverage.xml
            --html ${ARG_REPORT_DIR}/coverage.html
            --html-details
            --print-summary
            ${GCOVR_ARGS}
        
        # Generate additional text report
        COMMAND ${GCOVR_PATH}
            --root ${CMAKE_SOURCE_DIR}
            --object-directory ${CMAKE_BINARY_DIR}
            --txt ${ARG_REPORT_DIR}/coverage.txt
            ${GCOVR_ARGS}
        
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
        COMMENT "Generating coverage reports for ${ARG_TEST_TARGET}"
    )
    
    # Add dependency on the test target
    add_dependencies(${ARG_TARGET} ${ARG_TEST_TARGET})
    
    # Ensure code coverage is enabled for the test target
    if(NOT CODE_COVERAGE)
        message(WARNING "Code coverage is not enabled. Set CODE_COVERAGE=ON when configuring CMake.")
    endif()
    
    message(STATUS "Added coverage target: ${ARG_TARGET}")
    message(STATUS "  Test target: ${ARG_TEST_TARGET}")
    message(STATUS "  Report directory: ${ARG_REPORT_DIR}")
endfunction()

## ==================================================================================
## @function 
##      enable_code_coverage
## @brief 
##      Enable code coverage instrumentation globally
## ==================================================================================
function(enable_code_coverage)
    set(CODE_COVERAGE ON CACHE BOOL "Enable code coverage instrumentation")
    
    if(CODE_COVERAGE)
        # Add coverage flags for all targets
        add_compile_options(--coverage)
        add_link_options(--coverage)
        
        message(STATUS "Code coverage instrumentation enabled")
    endif()
endfunction()

## ==================================================================================
## @function 
##      setup_test_infrastructure
## @brief 
##      Setup complete test infrastructure with one call
## @param 
##      TEST_TARGET - name of the test executable target
##      SOURCES - test source files
##      LIBS - libraries to link with
##      COVERAGE_TARGET - name of the coverage target (optional)
## ==================================================================================
function(setup_test_infrastructure)
    set(options "")
    set(oneValueArgs TEST_TARGET COVERAGE_TARGET)
    set(multiValueArgs SOURCES LIBS)
    cmake_parse_arguments(ARG "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})
    
    # Validate arguments
    if(NOT ARG_TEST_TARGET)
        message(FATAL_ERROR "TEST_TARGET argument is required for setup_test_infrastructure")
    endif()
    
    # Enable test framework
    enable_test_framework()
    
    # Add test executable
    add_test_executable(
        TARGET ${ARG_TEST_TARGET}
        TESTCASE_SOURCES ${ARG_SOURCES}
        PRODUCT_LIBS ${ARG_LIBS}
    )
    
    # Add coverage target if requested
    if(ARG_COVERAGE_TARGET AND CODE_COVERAGE)
        add_coverage_target(
            TARGET ${ARG_COVERAGE_TARGET}
            TEST_TARGET ${ARG_TEST_TARGET}
        )
    endif()
    
    message(STATUS "Test infrastructure setup complete for ${ARG_TEST_TARGET}")
endfunction()