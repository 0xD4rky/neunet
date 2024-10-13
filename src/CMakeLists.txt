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


add_executable(neural_net ${SOURCES})

# Custom target for building
add_custom_target(build_all ALL
    COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR}
    COMMENT "Building the neural_net executable"
)

# Check if compilation was successful
add_custom_command(TARGET neural_net
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E echo "Compilation successful."
)
add_executable(neural_net ${SOURCES})

# Custom target for building
add_custom_target(build_all ALL
    COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR}
    COMMENT "Building the neural_net executable"
)

# Check if compilation was successful
add_custom_command(TARGET neural_net
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E echo "Compilation successful."
)
