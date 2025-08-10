project('cpp_meson_modules', 'cpp',
    version: '1.0.0',
    default_options: [
        'cpp_std=c++17',
        'warning_level=2',
        'debug=true',
        'optimization=0'
    ]
)

# Build type configuration
if get_option('buildtype') == 'debug'
    add_project_arguments('-DDEBUG', language: 'cpp')
    message('Building in DEBUG mode')
elif get_option('buildtype') == 'release'
    add_project_arguments('-DRELEASE', '-DNDEBUG', language: 'cpp')
    message('Building in RELEASE mode')
endif

# Add subdirectories for each module
# Each module exports its headers via dependency declarations
subdir('io')        # Provides: io_dep (includes io/headers/)
subdir('maths')     # Provides: maths_dep (includes maths/headers/)
subdir('stringm')   # Provides: stringm_dep (includes stringm/headers/)

# Main executable
main_sources = files('main.cpp')

# Main executable with all module dependencies
# This automatically includes all header directories:
# - io/headers/ (from io_dep)
# - maths/headers/ (from maths_dep)  
# - stringm/headers/ (from stringm_dep)
executable('cpp_meson_demo',
    main_sources,
    dependencies: [
        io_dep,      # Adds -I"io/headers" to compiler
        maths_dep,   # Adds -I"maths/headers" to compiler
        stringm_dep  # Adds -I"stringm/headers" to compiler
    ],
    cpp_args: ['-std=c++17']
)
