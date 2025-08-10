# IO Module - IO Utilities
# Explicit path to headers directory
io_headers_dir = include_directories('headers')
io_src_dir = 'src'

# Source files in the src directory
io_sources = files(
    io_src_dir / 'io_utils.cpp'
)

# Static library with explicit header path
io_lib = static_library('io_utils',
    io_sources,
    include_directories: io_headers_dir,
    cpp_args: ['-std=c++17']
)

# Dependency declaration with clear header path
io_dep = declare_dependency(
    link_with: io_lib,
    include_directories: io_headers_dir  # Exposes io/headers/ to main.cpp
)
