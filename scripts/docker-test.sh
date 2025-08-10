#!/bin/bash
# Test script for Docker builds

set -e

echo "🧪 Testing Docker builds..."

# Test build process
echo "📦 Testing build process..."
docker run --rm cpp-meson-project:dev sh -c "
    meson setup build/test-debug --buildtype=debug &&
    meson compile -C build/test-debug &&
    echo '✅ Debug build successful'
"

docker run --rm cpp-meson-project:dev sh -c "
    meson setup build/test-release --buildtype=release &&
    meson compile -C build/test-release &&
    echo '✅ Release build successful'
"

# Test runtime
echo "🚀 Testing runtime execution..."
echo "--- Debug Version ---"
docker run --rm cpp-meson-project:runtime ./debug/cpp_meson_demo

echo ""
echo "--- Release Version ---"
docker run --rm cpp-meson-project:runtime ./release/cpp_meson_demo

echo ""
echo "✅ All Docker tests passed!"
