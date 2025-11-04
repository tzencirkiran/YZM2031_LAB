#include <iostream>
#include <stack>
#include <climits>

using namespace std;

class MinStack {
private:
    // TODO: Add your data members here
    stack<int> values;
    stack<int> mins; // values and mins are pairs for given moment
    // Hint: You might need two stacks or a modified node structure

public:
    MinStack() {
        // TODO: Initialize your data structures
        mins.push(INT_MAX);
    }
    
    void push(int val) {
        // TODO: Implement push operation
        int current_min = getMin();
        if (val < current_min) {
            mins.push(val);
        }
        else {
            mins.push(current_min);
        }
        values.push(val);
        // Remember to maintain the minimum!      
    }
    
    void pop() {
        // TODO: Implement pop operation
        values.pop();
        mins.pop();
        // Don't forget to update the minimum if needed
    }
    
    int top() {
        // TODO: Return the top element
        return values.top();
    }
    
    int getMin() {
        // TODO: Return the minimum element in O(1) time
        return mins.top();
    }
    
    bool isEmpty() {
        // TODO: Check if stack is empty
        return values.empty();
    }
};

int main() {
    cout << "=== Problem 1: Min Stack ===" << endl;
    
    MinStack stack;
    
    // Test 1: Basic operations
    cout << "\nTest 1 - Basic operations:" << endl;
    stack.push(5);
    stack.push(3);
    stack.push(7);
    stack.push(1);
    
    cout << "After pushing 5, 3, 7, 1:" << endl;
    cout << "  Min: " << stack.getMin() << endl;        // Expected: 1
    cout << "  Top: " << stack.top() << endl;           // Expected: 1
    
    // Test 2: After popping minimum
    cout << "\nTest 2 - After popping minimum:" << endl;
    stack.pop();
    cout << "  Min: " << stack.getMin() << endl;  // Expected: 3
    cout << "  Top: " << stack.top() << endl;     // Expected: 7
    
    // Test 3: More pops
    cout << "\nTest 3 - After another pop:" << endl;
    stack.pop();
    cout << "  Min: " << stack.getMin() << endl;  // Expected: 3
    
    stack.push(2);
    cout << "\nAfter push(2):" << endl;
    cout << "  Min: " << stack.getMin() << endl;  // Expected: 2
    
    // Test 4: Edge case with duplicates
    cout << "\nTest 4 - Duplicate minimums:" << endl;
    MinStack stack2;
    stack2.push(2);
    stack2.push(0);
    stack2.push(3);
    stack2.push(0);
    
    cout << "After pushing 2, 0, 3, 0:" << endl;
    cout << "  Min: " << stack2.getMin() << endl;  // Expected: 0
    
    stack2.pop();
    cout << "After one pop:" << endl;
    cout << "  Min: " << stack2.getMin() << endl;  // Expected: 0 (still)
    
    stack2.pop();
    cout << "After another pop:" << endl;
    cout << "  Min: " << stack2.getMin() << endl;  // Expected: 0 (still)
    
    stack2.pop();
    cout << "After third pop:" << endl;
    cout << "  Min: " << stack2.getMin() << endl;  // Expected: 2
    
    return 0;
}
