# Makefile

# Project name
PROJ_NAME = lib_RNG.a

# Compiler
CXX = g++

# Compilation flags
CXXFLAGS = -std=c++17 -o3
DEBUGFLAGS = -Wall -DDEBUG -g

# .cpp files
CPP_SOURCE=$(wildcard ./src/*.cpp)
 
# Object files
OBJ_SOURSCE=$(CPP_SOURCE:.cpp=.o)

# Rule to build everything
all: $(PROJ_NAME)
all: clean

# Rule to build the test
debug: CXXFLAGS += $(DEBUGFLAGS)
debug: all

# Rule to build the main project
$(PROJ_NAME): $(OBJ_SOURSCE)
	@ar rcs $(PROJ_NAME) $(OBJ_SOURSCE)

# Rule to clean object files
clean:
	@rm -rf ./src/*.o

# Rule to display available options
help:
	@echo "Available options:"
	@echo "  make all      - Compile the main library (clean afterwards)"
	@echo "  make debug    - Compile the main library with debug verifications (clean afterwards)"
	@echo "  make clean    - Clean object files"
