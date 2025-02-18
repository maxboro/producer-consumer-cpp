# Compiler and flags
CC = g++
CFLAGS = -Wall -g -Iinclude -Iexternal -O3 -std=c++20 # Add -Iexternal for Catch2

# Directories
INC_DIR = include
BIN_DIR = bin

# Directory for test files
TEST_DIR = unit_tests

# Source files and output
SRC = main.cpp
TARGET = $(BIN_DIR)/game

# Test files
TEST_SRC = $(wildcard $(TEST_DIR)/*.cpp) external/catch2/catch_amalgamated.cpp  # All .cpp files in the tests directory
TEST_TARGET = $(BIN_DIR)/tests

# Rule to build the final program
$(TARGET): $(SRC) $(INC_DIR)/*.hpp
	mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

# Rule to build the test executable
$(TEST_TARGET): $(TEST_SRC)
	mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -o $(TEST_TARGET) $(TEST_SRC)

# Run tests
test: $(TEST_TARGET)
	./$(TEST_TARGET)

# Clean up build files
clean:
	rm -rf $(BIN_DIR)

# Phony targets
.PHONY: clean test
