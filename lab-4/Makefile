CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

# Student template targets (in lab-4 directory)
STUDENT_TARGETS = problem1_min_heap problem2_heap_sort problem3_kth_largest problem4_sorting_analysis

# Solution targets (in solutions directory)
SOLUTION_TARGETS = sol_problem1 sol_problem2 sol_problem3 sol_problem4

all: $(STUDENT_TARGETS)

solutions: $(SOLUTION_TARGETS)

# Compile student templates
problem1_min_heap: problem1_min_heap.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

problem2_heap_sort: problem2_heap_sort.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

problem3_kth_largest: problem3_kth_largest.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

problem4_sorting_analysis: problem4_sorting_analysis.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

# Compile solutions (for instructor verification)
sol_problem1: solutions/problem1_min_heap.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

sol_problem2: solutions/problem2_heap_sort.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

sol_problem3: solutions/problem3_kth_largest.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

sol_problem4: solutions/problem4_sorting_analysis.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

clean:
	rm -f $(STUDENT_TARGETS) $(SOLUTION_TARGETS)

.PHONY: all solutions clean
