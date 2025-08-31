# Use Ubuntu 22.04 LTS as base image
FROM ubuntu:22.04

# Avoid warnings by switching to noninteractive
ENV DEBIAN_FRONTEND=noninteractive

# Configure apt and install packages
RUN apt-get update \
    && apt-get -y install --no-install-recommends apt-utils dialog 2>&1 \
    # Install development tools
    && apt-get -y install \
        git \
        openssh-client \
        less \
        iproute2 \
        procps \
        lsb-release \
        ca-certificates \
        build-essential \
        cmake \
        # Install C/C++ development tools
        gcc \
        g++ \
        gdb \
        make \
        # Install clang tools
        clang \
        clang-format \
        clang-tidy \
        # Install Ruby and other useful tools
        ruby \
        ruby-dev \
        curl \
        wget \
        zip \
        unzip \
        nano \
        vim \
        # Clean up
    && apt-get autoremove -y \
    && apt-get clean -y \
    && rm -rf /var/lib/apt/lists/*

# Create a non-root user to use if preferred
ARG USERNAME=vscode
ARG USER_UID=1000
ARG USER_GID=$USER_UID

RUN groupadd --gid $USER_GID $USERNAME \
    && useradd --uid $USER_UID --gid $USER_GID -m $USERNAME \
    # Add sudo support for the non-root user
    && apt-get update \
    && apt-get install -y sudo \
    && echo $USERNAME ALL=\(root\) NOPASSWD:ALL > /etc/sudoers.d/$USERNAME\
    && chmod 0440 /etc/sudoers.d/$USERNAME \
    # Clean up
    && apt-get autoremove -y \
    && apt-get clean -y \
    && rm -rf /var/lib/apt/lists/*

# Switch back to dialog for any ad-hoc use of apt-get
ENV DEBIAN_FRONTEND=dialog

# Set the default user
USER $USERNAME


# Set working directory
WORKDIR /workspace