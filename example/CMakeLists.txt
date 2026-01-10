### project configuration ===========================================================
cmake_minimum_required(VERSION 3.14)
project(math_util_tests)
include(${CMAKE_CURRENT_LIST_DIR}/../test_framework.cmake)

### build configuration =============================================================
enable_test_framework()
enable_code_coverage()

### product code ====================================================================
add_library(math_util STATIC
    product/math_util.cpp
)
target_include_directories(math_util
    PUBLIC product/
)

### testcase code ===================================================================
add_test_executable(
    TARGET math_util_test
    TESTCASE_SOURCES testcase/testcase.cpp
    PRODUCT_LIBS math_util
)

### testcase coverage ===============================================================
add_coverage_target(
    TARGET cov
    TEST_TARGET math_util_test
    REPORT_DIR ${CMAKE_BINARY_DIR}/coverage
    INCLUDE_PATTERNS "product/*"
    EXCLUDE_PATTERNS "testcase/*"
)