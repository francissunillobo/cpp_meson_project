#!/bin/bash
# Docker build script for local development

set -e

echo "🐳 Building C++ Meson Docker Images..."

# Build the development image
echo "📦 Building development image..."
docker build --target builder -t cpp-meson-project:dev .

# Build the runtime image
echo "🚀 Building runtime image..."
docker build --target runtime -t cpp-meson-project:runtime .

echo "✅ Docker images built successfully!"
echo ""
echo "Available images:"
docker images | grep cpp-meson-project

echo ""
echo "🎯 Usage examples:"
echo "  Development:  docker run -it --rm -v \$(pwd):/app cpp-meson-project:dev bash"
echo "  Run Release:  docker run --rm cpp-meson-project:runtime"
echo "  Run Debug:    docker run --rm cpp-meson-project:runtime ./debug/cpp_meson_demo"
echo "  With Compose: docker-compose up app"
