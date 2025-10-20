# YZM2031 - Lab Assignment 1 Makefile
# This Makefile compiles all lab problems

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g

# Target executables
TARGETS = problem1 problem2 problem3 problem4 problem5

# Default target: build all
all: $(TARGETS)

# Individual targets
problem1: problem1_dynamic_array.cpp
	$(CXX) $(CXXFLAGS) -o problem1 problem1_dynamic_array.cpp

problem2: problem2_linked_list.cpp
	$(CXX) $(CXXFLAGS) -o problem2 problem2_linked_list.cpp

problem3: problem3_postfix_evaluator.cpp
	$(CXX) $(CXXFLAGS) -o problem3 problem3_postfix_evaluator.cpp

problem4: problem4_circular_queue.cpp
	$(CXX) $(CXXFLAGS) -o problem4 problem4_circular_queue.cpp

problem5: problem5_merge_lists.cpp
	$(CXX) $(CXXFLAGS) -o problem5 problem5_merge_lists.cpp

# Run all tests
test: all
	@echo "Running Problem 1..."
	./problem1
	@echo ""
	@echo "Running Problem 2..."
	./problem2
	@echo ""
	@echo "Running Problem 3..."
	./problem3
	@echo ""
	@echo "Running Problem 4..."
	./problem4
	@echo ""
	@echo "Running Problem 5..."
	./problem5
	@echo ""

# Clean build artifacts
clean:
	rm -f $(TARGETS)
	rm -f *.o

# Help
help:
	@echo "YZM2031 Lab Assignment 1 - Makefile Usage"
	@echo ""
	@echo "Available targets:"
	@echo "  make all      - Build all problems"
	@echo "  make problem1 - Build problem 1 only"
	@echo "  make problem2 - Build problem 2 only"
	@echo "  make problem3 - Build problem 3 only"
	@echo "  make problem4 - Build problem 4 only"
	@echo "  make problem5 - Build problem 5 only"
	@echo "  make test     - Build and run all tests"
	@echo "  make clean    - Remove all executables"
	@echo "  make help     - Show this help message"

.PHONY: all test clean help

