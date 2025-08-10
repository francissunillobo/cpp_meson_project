# Maths Module - Math Utilities
# Explicit path to headers directory
maths_headers_dir = include_directories('headers')
maths_src_dir = 'src'

# Source files in the src directory
maths_sources = files(
    maths_src_dir / 'math_utils.cpp'
)

# Static library with explicit header path
maths_lib = static_library('math_utils',
    maths_sources,
    include_directories: maths_headers_dir,
    cpp_args: ['-std=c++17']
)

# Dependency declaration with clear header path
maths_dep = declare_dependency(
    link_with: maths_lib,
    include_directories: maths_headers_dir  # Exposes maths/headers/ to main.cpp
)
