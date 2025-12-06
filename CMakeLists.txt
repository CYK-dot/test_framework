cmake_minimum_required(VERSION 3.10)
project(easy_test
    VERSION 1.0.0
    DESCRIPTION "Unit tests for angle loop"
    LANGUAGES C CXX
)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# =====================================================================

set(GTEST_ROOT ${CMAKE_SOURCE_DIR}/lib)
set(GMOCK_ROOT ${CMAKE_SOURCE_DIR}/lib)
set(GTEST_HEADER ${CMAKE_SOURCE_DIR}/lib/headers)

# =====================================================================

# global defines
set(GLOBAL_DEFINES

)

# global includes
set(GLOBAL_INCLUDES
    "../minest_cli"
)

# =====================================================================

# code to test
add_library(CODE_SOURCES
    "../minest_cli/minest_cli.c"
)

# code of testcases
set(TEST_SOURCES
    "testcase/cli.cpp"
)

# =====================================================================

add_executable(${PROJECT_NAME} 
    ${CODE_SOURCES}
    ${TEST_SOURCES}
    "./main.cpp"
)
add_compile_definitions(
    ${GLOBAL_DEFINES}
)
target_include_directories(${PROJECT_NAME} PRIVATE
    ${GLOBAL_INCLUDES}
    ${GTEST_HEADER}
)
target_link_libraries(${PROJECT_NAME} PRIVATE
    "${GTEST_ROOT}/libgtest.a"
    "${GMOCK_ROOT}/libgmock.a"
    "${GMOCK_ROOT}/libgmock_main.a"
)

enable_testing()
add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})