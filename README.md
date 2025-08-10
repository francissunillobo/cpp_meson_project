# C++ Meson Multi-Module Project

This project demonstrates a C++ application built with Meson build system, featuring three separate utility modules:

## Project Structure

```
cpp_meson_project/
├── main.cpp                    # Main application
├── meson.build                 # Main build configuration
├── README.md                   # This file
├── build/                      # Build output directory
│   ├── debug/                  # Debug build outputs
│   └── release/                # Release build outputs
├── io/                         # IO Utilities Module
│   ├── headers/
│   │   └── io_utils.hpp
│   ├── src/
│   │   └── io_utils.cpp
│   └── meson.build
├── stringm/                    # String Utilities Module
│   ├── headers/
│   │   └── string_utils.hpp
│   ├── src/
│   │   └── string_utils.cpp
│   └── meson.build
└── maths/                      # Math Utilities Module
    ├── headers/
    │   └── math_utils.hpp
    ├── src/
    │   └── math_utils.cpp
    └── meson.build
```

## Modules

### IO Module - IO Utilities

- File operations (read, write, exists)
- Directory operations (list files, create directories)
- Console operations (print messages, get user input)

### Stringm Module - String Utilities

- String manipulation (uppercase, lowercase, trim, reverse)
- String analysis (starts with, ends with, contains, count occurrences)
- String operations (split, join, replace)

### Maths Module - Math Utilities

- Basic operations (power, square root, absolute value)
- Trigonometric functions (sine, cosine, tangent)
- Statistical functions (mean, median, standard deviation)
- Utility functions (prime check, factorial, fibonacci)

## Building the Project

### Prerequisites

- C++17 compatible compiler (GCC, Clang, or MSVC)
- Meson build system
- Ninja build backend (recommended)

### Build Commands

#### Debug Build

```powershell
meson setup build/debug --buildtype=debug
meson compile -C build/debug
.\build\debug\cpp_meson_demo.exe
```

#### Release Build

```powershell
meson setup build/release --buildtype=release
meson compile -C build/release
.\build\release\cpp_meson_demo.exe
```

#### Clean Builds

```powershell
# Clean compiled files only
meson compile -C build/debug --clean
meson compile -C build/release --clean

# Wipe and reconfigure
meson setup build/debug --wipe --buildtype=debug
meson setup build/release --wipe --buildtype=release
```

### GitHub Actions CI/CD

This project includes Windows-only GitHub Actions workflows:

- **Continuous Integration**: Builds both debug and release on every push to `main`/`master`/`develop`
- **Release Pipeline**: Creates releases with attached Windows executables on version tags
- **Artifacts**: Debug and release builds available for download (30 days retention)
- **Build Structure**: Uses `build/debug` and `build/release` directories

See `BUILD_INSTRUCTIONS.md` for detailed build information.

## Features Demonstrated

- Modular C++ project structure
- Meson build system with multiple modules
- Static library creation and linking
- Include directory management (simplified header includes)
- C++17 standard usage
- Windows-focused build pipeline
- Debug and Release configurations
- Comprehensive utility functions

## Code Structure

### Header Includes

The project uses simplified header includes:

```cpp
#include "io_utils.hpp"      // Instead of "io/headers/io_utils.hpp"
#include "string_utils.hpp"  // Instead of "stringm/headers/string_utils.hpp"
#include "math_utils.hpp"    // Instead of "maths/headers/math_utils.hpp"
```

This is made possible by Meson's dependency system that automatically adds the module header directories to the include path.

## Example Output

The demo application will showcase all three modules by:

- Creating and reading a test file (IO Utils)
- Performing various string operations (String Utils)
- Calculating mathematical operations and statistics (Math Utils)
