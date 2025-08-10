#!/bin/bash
# Multi-platform Docker build script for x86_64 and ARM64

set -e

IMAGE_NAME="cpp-meson-project"
TAG="${1:-latest}"

echo "🐳 Building Multi-Platform C++ Meson Docker Images..."
echo "📋 Target platforms: linux/amd64, linux/arm64"
echo "🏷️  Tag: ${TAG}"

# Ensure buildx is available
echo "🔧 Setting up Docker buildx..."
docker buildx create --name multiplatform-builder --use 2>/dev/null || docker buildx use multiplatform-builder

# Enable experimental features
export DOCKER_CLI_EXPERIMENTAL=enabled

echo ""
echo "📦 Building development image for multiple platforms..."
docker buildx build \
    --platform linux/amd64,linux/arm64 \
    --target builder \
    --tag "${IMAGE_NAME}:dev-${TAG}" \
    --push \
    .

echo ""
echo "🚀 Building runtime image for multiple platforms..."
docker buildx build \
    --platform linux/amd64,linux/arm64 \
    --target runtime \
    --tag "${IMAGE_NAME}:${TAG}" \
    --tag "${IMAGE_NAME}:runtime-${TAG}" \
    --push \
    .

echo ""
echo "✅ Multi-platform Docker images built and pushed successfully!"
echo ""
echo "📋 Built images:"
echo "  Development: ${IMAGE_NAME}:dev-${TAG}"
echo "  Runtime:     ${IMAGE_NAME}:${TAG}"
echo "  Runtime:     ${IMAGE_NAME}:runtime-${TAG}"
echo ""
echo "🎯 Usage examples:"
echo "  Pull and run (AMD64): docker run --rm --platform linux/amd64 ${IMAGE_NAME}:${TAG}"
echo "  Pull and run (ARM64): docker run --rm --platform linux/arm64 ${IMAGE_NAME}:${TAG}"
echo "  Development (AMD64):   docker run -it --rm --platform linux/amd64 -v \$(pwd):/app ${IMAGE_NAME}:dev-${TAG} bash"
echo "  Development (ARM64):   docker run -it --rm --platform linux/arm64 -v \$(pwd):/app ${IMAGE_NAME}:dev-${TAG} bash"
echo ""
echo "📝 Note: Images are pushed to registry. Use --load instead of --push for local builds only."
