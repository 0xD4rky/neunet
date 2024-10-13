# Set the minimum required version of CMake
cmake_minimum_required(VERSION 3.10)

# Set the project name and C++ standard
project(NeuralNetProject)
set(CMAKE_CXX_STANDARD 11)

# Add compiler flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

# Specify the source files
set(SOURCES
    main.cpp
    network/net.cpp
    network/layer.cpp
    network/neuron.cpp
    optimizer/utils.cpp
)


