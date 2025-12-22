CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

STUDENT_TARGETS = problem1 problem2 problem3 problem4 problem5

all: $(STUDENT_TARGETS)

# Compile student templates
problem1: problem1.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

problem2: problem2.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

problem3: problem3.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

problem4: problem4.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

problem5: problem5.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<


clean:
	rm -f $(STUDENT_TARGETS)

.PHONY: all clean
