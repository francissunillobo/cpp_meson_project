# Build Instructions for Windows

This document explains how to build the C++ Meson project locally and through GitHub Actions.

## Local Build

### Prerequisites

- Windows 10/11
- Visual Studio 2019 or later (or Build Tools for Visual Studio)
- Python 3.x
- Meson (`pip install meson`)
- Ninja (`pip install ninja`)

### Debug Build

```powershell
# Setup debug build
meson setup build/debug --buildtype=debug

# Compile debug version
meson compile -C build/debug

# Run debug executable
.\build\debug\cpp_meson_demo.exe
```

### Release Build

```powershell
# Setup release build
meson setup build/release --buildtype=release

# Compile release version
meson compile -C build/release

# Run release executable
.\build\release\cpp_meson_demo.exe
```

## GitHub Actions CI/CD

### Automatic Building

The project is configured with GitHub Actions that will:

1. **On Push/PR** (`.github/workflows/build.yml`):

   - Build both debug and release versions
   - Test the executables
   - Upload artifacts for download

2. **On Release Tag** (`.github/workflows/release.yml`):
   - Build release version
   - Attach executable to GitHub release

### Build Artifacts

After each push, you can download the built executables from:

- **Debug build**: `debug-build-windows` artifact (includes .pdb debug symbols)
- **Release build**: `release-build-windows` artifact

These artifacts are available for 30 days and contain:

- `cpp_meson_demo.exe` - The main executable
- `*.pdb` files (debug builds only) - Debug symbols

Build artifacts are created from the `build/debug` and `build/release` directories.

### Triggering a Release

To create a release with attached binaries:

1. **Using Git Tags:**

   ```bash
   git tag v1.0.0
   git push origin v1.0.0
   ```

2. **Manual Trigger:**
   - Go to Actions tab in GitHub
   - Select "Create Release" workflow
   - Click "Run workflow"
   - Enter version (e.g., v1.0.0)

## Build Configuration

### Debug vs Release

- **Debug**: Includes debug symbols, no optimization, defines `DEBUG`
- **Release**: Optimized, no debug info, defines `RELEASE` and `NDEBUG`

### Meson Options

The build system supports various options:

```bash
# View all options
meson setup builddir --help

# Custom options
meson setup builddir --buildtype=release --optimization=3
```

## Project Structure

```
cpp_meson_project/
├── .github/workflows/          # GitHub Actions
│   ├── build.yml              # CI build workflow
│   └── release.yml            # Release workflow
├── build/                     # Build output directory
│   ├── debug/                 # Debug build output
│   └── release/               # Release build output
├── io/                        # IO Utilities Module
├── stringm/                   # String Utilities Module
├── maths/                     # Math Utilities Module
├── main.cpp                   # Main application
├── meson.build               # Build configuration
└── README.md                 # Project documentation
```

## Troubleshooting

### Common Issues

1. **MSVC not found**: Install Visual Studio Build Tools
2. **Meson/Ninja not found**: Install via `pip install meson ninja`
3. **Build fails**: Check Visual Studio version compatibility

### Clean Build

```powershell
# Clean compiled files only
meson compile -C build/debug --clean
meson compile -C build/release --clean

# Wipe and reconfigure
meson setup build/debug --wipe --buildtype=debug
meson setup build/release --wipe --buildtype=release

# Manual removal (if needed)
Remove-Item -Recurse -Force build
```
