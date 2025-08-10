#!/bin/bash
# Local multi-platform Docker build script (builds locally without pushing)

set -e

IMAGE_NAME="cpp-meson-project"
TAG="${1:-latest}"

echo "🐳 Building Multi-Platform C++ Meson Docker Images Locally..."
echo "📋 Target platforms: linux/amd64, linux/arm64"
echo "🏷️  Tag: ${TAG}"

# Ensure buildx is available
echo "🔧 Setting up Docker buildx..."
docker buildx create --name multiplatform-builder --use 2>/dev/null || docker buildx use multiplatform-builder

# Enable experimental features
export DOCKER_CLI_EXPERIMENTAL=enabled

echo ""
echo "📦 Building development image for multiple platforms (local)..."
docker buildx build \
    --platform linux/amd64,linux/arm64 \
    --target builder \
    --tag "${IMAGE_NAME}:dev-${TAG}" \
    --load \
    .

echo ""
echo "🚀 Building runtime image for multiple platforms (local)..."
docker buildx build \
    --platform linux/amd64,linux/arm64 \
    --target runtime \
    --tag "${IMAGE_NAME}:${TAG}" \
    --tag "${IMAGE_NAME}:runtime-${TAG}" \
    --load \
    .

echo ""
echo "✅ Multi-platform Docker images built locally!"
echo ""
echo "📋 Available local images:"
docker images | grep "${IMAGE_NAME}" | head -10

echo ""
echo "🎯 Usage examples:"
echo "  Run native:            docker run --rm ${IMAGE_NAME}:${TAG}"
echo "  Run specific platform: docker run --rm --platform linux/amd64 ${IMAGE_NAME}:${TAG}"
echo "  Development:           docker run -it --rm -v \$(pwd):/app ${IMAGE_NAME}:dev-${TAG} bash"
echo ""
echo "📝 Note: Images are built locally. Use the other script to push to registry."
