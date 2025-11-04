# Makefile for Lab 2

CXX = g++
CXXFLAGS = -std=c++17 -Wall -g

# Source files
PROBLEM1 = problem1_min_stack.cpp
PROBLEM2 = problem2_queue_using_stacks.cpp
PROBLEM3 = problem3_sliding_window_max.cpp
PROBLEM4 = problem4_string_compression.cpp
PROBLEM5 = problem5_remove_duplicates.cpp

# Executable names (without extension)
EXEC1 = problem1
EXEC2 = problem2
EXEC3 = problem3
EXEC4 = problem4
EXEC5 = problem5

# Default target: build all
all: $(EXEC1) $(EXEC2) $(EXEC3) $(EXEC4) $(EXEC5)

# Build individual problems
$(EXEC1): $(PROBLEM1)
	$(CXX) $(CXXFLAGS) -o $(EXEC1) $(PROBLEM1)

$(EXEC2): $(PROBLEM2)
	$(CXX) $(CXXFLAGS) -o $(EXEC2) $(PROBLEM2)

$(EXEC3): $(PROBLEM3)
	$(CXX) $(CXXFLAGS) -o $(EXEC3) $(PROBLEM3)

$(EXEC4): $(PROBLEM4)
	$(CXX) $(CXXFLAGS) -o $(EXEC4) $(PROBLEM4)

$(EXEC5): $(PROBLEM5)
	$(CXX) $(CXXFLAGS) -o $(EXEC5) $(PROBLEM5)

# Run all tests
test: all
	@echo "=== Running Problem 1 ==="
	./$(EXEC1)
	@echo ""
	@echo "=== Running Problem 2 ==="
	./$(EXEC2)
	@echo ""
	@echo "=== Running Problem 3 ==="
	./$(EXEC3)
	@echo ""
	@echo "=== Running Problem 4 ==="
	./$(EXEC4)
	@echo ""
	@echo "=== Running Problem 5 ==="
	./$(EXEC5)

# Run individual problems
test1: $(EXEC1)
	./$(EXEC1)

test2: $(EXEC2)
	./$(EXEC2)

test3: $(EXEC3)
	./$(EXEC3)

test4: $(EXEC4)
	./$(EXEC4)

test5: $(EXEC5)
	./$(EXEC5)

# Clean up
clean:
	rm -f $(EXEC1) $(EXEC2) $(EXEC3) $(EXEC4) $(EXEC5)
	rm -rf *.dSYM

.PHONY: all test test1 test2 test3 test4 test5 clean

