FROM ubuntu:20.04

ARG UID=1000
ARG GID=1000
ARG USER=user

RUN apt-get update && export DEBIAN_FRONTEND=noninteractive \
    && apt-get -y install --no-install-recommends \
    ca-certificates \
    clang \
    clang-format \
    clang-tidy \
    cppcheck \
    cmake \
    g++ \
    gcc \
    git \
    libssl-dev \
    make \
    sudo

RUN groupadd -g $GID -o $USER
RUN useradd -u $UID -m -g $USER $USER && \
    echo "$USER ALL = NOPASSWD: ALL" > /etc/sudoers.d/$USER && \
    chmod 0440 /etc/sudoers.d/$USER

USER $USER
