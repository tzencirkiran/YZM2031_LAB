/**
 * YZM2031 - Lab Assignment 1
 * Problem 4: Circular Queue for Task Scheduling
 * 
 * Student Name: Talha
 * Student ID: 25018603
 * 
 * Instructions: Implement the TODO sections below
 */

#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class CircularQueue {
private:
    string* tasks;
    int capacity;
    int frontIndex;
    int rearIndex;
    int count;

public:
    // Constructor
    CircularQueue(int cap) : capacity(cap), frontIndex(0), rearIndex(-1), count(0) {
        tasks = new string[capacity];
    }

    // Destructor
    ~CircularQueue() {
        delete[] tasks;
    }

    // Add task to queue (returns false if full)
    bool enqueue(const string& task) {
        // TODO: Implement enqueue
        // 1. Check if queue is full // 2. If full, return false
        if (count == capacity) {
            return false;
        }
        rearIndex = (rearIndex + 1) % capacity;
        tasks[rearIndex] = task;
        count++;
        // 3. Update rearIndex using circular logic: (rearIndex + 1) % capacity
        // 4. Add task at rearIndex
        // 5. Increment count
        // 6. Return true
        return true;
    }

    // Remove and return task from front
    string dequeue() {
        // TODO: Implement dequeue
        // 1. Check if queue is empty, throw exception if empty
        if (count == 0) {
            throw underflow_error("circular queue is empty!");
        }
        string task = tasks[frontIndex];
        frontIndex = (frontIndex + 1) % capacity;
        count--;
        // 2. Get task at frontIndex
        // 3. Update frontIndex using circular logic: (frontIndex + 1) % capacity
        // 4. Decrement count
        // 5. Return the task
        
        return task;  // Placeholder
    }

    // View next task without removing
    string front() const {
        // TODO: Implement front 
        if (count == 0) {
            throw underflow_error("circular queue is empty!");
        }
        // 1. Check if queue is empty, throw exception if empty
        string task = tasks[frontIndex];
        // 2. Return task at frontIndex
        
        return task;  // Placeholder
    }

    // Check if empty
    bool isEmpty() const {
        return count == 0;
    }

    // Check if full
    bool isFull() const {
        return count == capacity;
    }

    // Return current size
    int size() const {
        return count;
    }

    // Display all pending tasks
    void display() const {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }

        cout << "Pending tasks: ";
        int index = frontIndex;
        for (int i = 0; i < count; i++) {
            cout << tasks[index];
            if (i < count - 1) cout << ", ";
            index = (index + 1) % capacity;
        }
        cout << endl;
    }
};

// Test cases
int main() {
    cout << "=== Testing Circular Queue Task Scheduler ===" << endl << endl;

    CircularQueue scheduler(5);

    // Test 1: Enqueue tasks
    cout << "Test 1: Enqueue tasks" << endl;
    scheduler.enqueue("Task1");
    scheduler.enqueue("Task2");
    scheduler.enqueue("Task3");
    scheduler.display();  // Expected: Task1, Task2, Task3
    cout << "Size: " << scheduler.size() << endl;
    cout << endl;

    // Test 2: Process (dequeue) some tasks
    cout << "Test 2: Process some tasks" << endl;
    cout << "Processing: " << scheduler.dequeue() << endl;  // Task1
    cout << "Processing: " << scheduler.dequeue() << endl;  // Task2
    scheduler.display();  // Expected: Task3
    cout << endl;

    // Test 3: Add more tasks (wrap around)
    cout << "Test 3: Add more tasks (testing wrap-around)" << endl;
    scheduler.enqueue("Task4");
    scheduler.enqueue("Task5");
    scheduler.enqueue("Task6");
    scheduler.enqueue("Task7");
    scheduler.display();  // Expected: Task3, Task4, Task5, Task6, Task7
    cout << "Size: " << scheduler.size() << endl;
    cout << endl;

    // Test 4: Check if full
    cout << "Test 4: Check if full" << endl;
    cout << "Queue full? " << (scheduler.isFull() ? "Yes" : "No") << endl;  // Yes
    cout << "Can add Task8? " << (scheduler.enqueue("Task8") ? "Yes" : "No") << endl;  // No
    cout << endl;

    // Test 5: View front without removing
    cout << "Test 5: View front task" << endl;
    cout << "Next task: " << scheduler.front() << endl;  // Task3
    cout << "Size after front(): " << scheduler.size() << endl;  // Still 5
    cout << endl;

    // Test 6: Process all remaining tasks
    cout << "Test 6: Process all remaining tasks" << endl;
    while (!scheduler.isEmpty()) {
        cout << "Processing: " << scheduler.dequeue() << endl;
    }
    cout << "Queue empty? " << (scheduler.isEmpty() ? "Yes" : "No") << endl;
    cout << endl;

    cout << "=== All tests completed ===" << endl;

    return 0;
}

