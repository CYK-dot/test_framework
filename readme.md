# CMake Google Test Framework

A comprehensive CMake-based testing framework that integrates Google Test with additional features like code coverage reporting and easy test discovery.

## Features

- **Easy Integration**: Simple integration with Google Test using CMake
- **Automatic Download**: Automatically downloads and builds Google Test
- **Code Coverage**: Built-in support for code coverage reports (XML, HTML, and text formats)
- **Test Discovery**: Automatic discovery and registration of Google Test tests
- **Cross-platform**: Works on Windows, Linux, and macOS
- **Customizable**: Configurable coverage filters and test output directories

## Components

- `test_framework.cmake`: Main CMake module providing testing utilities
- `test_ci_template.yml`: CI template for continuous integration
- `example/`: Sample project demonstrating usage

## Functions Provided

- `enable_test_framework()`: Downloads and configures Google Test
- `add_test_executable()`: Creates test executables with proper linking
- `add_coverage_target()`: Generates coverage reports for test targets

## Getting Started

See the `example/` directory for a complete example of how to use this framework.

## Prerequisites

- CMake 3.14 or higher
- A C++ compiler supporting C++14 or later
- gcovr (for coverage reports, optional)

## License

This project is licensed under the MIT License - see the LICENSE file for details.