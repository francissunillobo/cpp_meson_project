# Multi-stage Dockerfile for C++ Meson project (Multi-platform: x86_64, ARM64)
FROM ubuntu:22.04 as builder

# Set non-interactive frontend for apt
ARG DEBIAN_FRONTEND=noninteractive

# Get build arguments for platform info
ARG TARGETPLATFORM
ARG TARGETARCH
ARG TARGETOS

# Install build dependencies
RUN apt-get update && apt-get install -y \
    build-essential \
    g++ \
    cmake \
    ninja-build \
    python3 \
    python3-pip \
    git \
    pkg-config \
    && rm -rf /var/lib/apt/lists/*

# Install Meson
RUN pip3 install meson

# Print platform information for debugging
RUN echo "Building for platform: ${TARGETPLATFORM:-unknown}" && \
    echo "Target architecture: ${TARGETARCH:-unknown}" && \
    echo "Target OS: ${TARGETOS:-unknown}" && \
    uname -a

# Set working directory
WORKDIR /app

# Copy source code
COPY . .

# Create build directories
RUN mkdir -p build/debug build/release

# Configure and build debug version
RUN meson setup build/debug --buildtype=debug
RUN meson compile -C build/debug

# Configure and build release version  
RUN meson setup build/release --buildtype=release
RUN meson compile -C build/release

# Runtime stage (smaller image)
FROM ubuntu:22.04 as runtime

# Install runtime dependencies only
RUN apt-get update && apt-get install -y \
    libstdc++6 \
    && rm -rf /var/lib/apt/lists/*

# Create app directory
WORKDIR /app

# Copy built executables from builder stage
COPY --from=builder /app/build/debug/cpp_meson_demo ./debug/cpp_meson_demo
COPY --from=builder /app/build/release/cpp_meson_demo ./release/cpp_meson_demo

# Make executables runnable
RUN chmod +x debug/cpp_meson_demo release/cpp_meson_demo

# Default command runs the release version
CMD ["./release/cpp_meson_demo"]

# Expose any ports if needed (none for this console app)
# EXPOSE 8080

# Add labels for metadata
LABEL maintainer="your-email@example.com"
LABEL description="C++ Meson Multi-Module Demo Application"
LABEL version="1.0.0"
