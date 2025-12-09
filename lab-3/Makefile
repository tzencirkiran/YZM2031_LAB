# YZM2031 - Lab Assignment 3 Makefile
# This Makefile compiles all lab problems

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g

# Target executables
TARGETS = problem1 problem2 problem3 problem4

# Default target: build all
all: $(TARGETS)

# Individual targets
problem1: problem1_tree_properties.cpp
	$(CXX) $(CXXFLAGS) -o problem1 problem1_tree_properties.cpp

problem2: problem2_bst_applications.cpp
	$(CXX) $(CXXFLAGS) -o problem2 problem2_bst_applications.cpp

problem3: problem3_avl_verification.cpp
	$(CXX) $(CXXFLAGS) -o problem3 problem3_avl_verification.cpp

problem4: problem4_advanced_trees.cpp
	$(CXX) $(CXXFLAGS) -o problem4 problem4_advanced_trees.cpp

# Run all tests
test: all
	@echo "Running Problem 1: Tree Properties..."
	./problem1
	@echo ""
	@echo "Running Problem 2: BST Applications..."
	./problem2
	@echo ""
	@echo "Running Problem 3: AVL Verification..."
	./problem3
	@echo ""
	@echo "Running Problem 4: Advanced Challenges..."
	./problem4
	@echo ""

# Clean build artifacts
clean:
	rm -f $(TARGETS)
	rm -f *.o

# Help
help:
	@echo "YZM2031 Lab Assignment 3 - Makefile Usage"
	@echo ""
	@echo "Available targets:"
	@echo "  make all      - Build all problems"
	@echo "  make problem1 - Build problem 1 only"
	@echo "  make problem2 - Build problem 2 only"
	@echo "  make problem3 - Build problem 3 only"
	@echo "  make problem4 - Build problem 4 only"
	@echo "  make test     - Build and run all tests"
	@echo "  make clean    - Remove all executables"
	@echo "  make help     - Show this help message"

.PHONY: all test clean help

