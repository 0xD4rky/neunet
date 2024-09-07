CXX = g++

# Compiler flags
CXXFLAGS = -std=c++11 -Wall

# Directories
SRC_DIR = .
NETWORK_DIR = ./network
OPTIMIZER_DIR = ./optimizer

# Source files
SRCS = $(SRC_DIR)/main.cpp \
       $(NETWORK_DIR)/net.cpp \
       $(NETWORK_DIR)/layer.cpp \
       $(NETWORK_DIR)/neuron.cpp \
       $(OPTIMIZER_DIR)/utils.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Executable file
EXEC = neunet

# Build target
all: $(EXEC)

# Rule to create the executable
$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJS)

# Rule to compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(OBJS) $(EXEC)