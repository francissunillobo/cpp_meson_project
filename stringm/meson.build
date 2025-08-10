# Stringm Module - String Utilities
# Explicit path to headers directory
stringm_headers_dir = include_directories('headers')
stringm_src_dir = 'src'

# Source files in the src directory
stringm_sources = files(
    stringm_src_dir / 'string_utils.cpp'
)

# Static library with explicit header path
stringm_lib = static_library('string_utils',
    stringm_sources,
    include_directories: stringm_headers_dir,
    cpp_args: ['-std=c++17']
)

# Dependency declaration with clear header path
stringm_dep = declare_dependency(
    link_with: stringm_lib,
    include_directories: stringm_headers_dir  # Exposes stringm/headers/ to main.cpp
)
