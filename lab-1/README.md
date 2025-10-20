# YZM2031 - Data Structures and Algorithms

## Lab Assignment 1: C++ Fundamentals, Lists, Stacks & Queues

**Duration:** 2 hours  
**Total Points:** 100  
**Covers:** Week 1, Week 2, Week 3  

---

## Instructions

- **Open Book:** You may use course materials, notes, and the internet.
- **AI Tools Allowed:** ChatGPT, Claude, GitHub Copilot, etc. are permitted AS HELPERS; NOT SOLUTION PROVIDERS!
- **Submission:** Zip the folder and submit it (<name_studentId>_lab1.zip)
- **Compilation:** Your code must compile without errors using C++17 or later.
- **Testing:** Test your code with the provided examples before submission.

---

## Problem 1: Dynamic Array Implementation (25 points)

### Description

Implement a `DynamicArray` class that automatically resizes when needed. The class should support basic operations like add, insert, remove, and access by index.

### Requirements

```cpp
class DynamicArray {
private:
    int* data;
    int size;        // Current number of elements
    int capacity;    // Current capacity of array

public:
    DynamicArray(int initialCapacity = 10);
    ~DynamicArray();
    
    void add(int value);                    // Add element to end
    void insert(int index, int value);      // Insert at specific position
    void remove(int index);                 // Remove element at index
    int get(int index) const;               // Get element at index
    int getSize() const;                    // Return current size
    int getCapacity() const;                // Return current capacity
    void print() const;                     // Print all elements
    
private:
    void resize();  // Double capacity when full
};
```

### Test Cases

```cpp
int main() {
    DynamicArray arr(5);
    
    // Test 1: Add elements
    arr.add(10);
    arr.add(20);
    arr.add(30);
    arr.add(40);
    arr.add(50);
    arr.print();  // Expected: 10 20 30 40 50
    cout << "Size: " << arr.getSize() << ", Capacity: " << arr.getCapacity() << endl;
    // Expected: Size: 5, Capacity: 5
    
    // Test 2: Trigger resize
    arr.add(60);
    arr.print();  // Expected: 10 20 30 40 50 60
    cout << "Size: " << arr.getSize() << ", Capacity: " << arr.getCapacity() << endl;
    // Expected: Size: 6, Capacity: 10
    
    // Test 3: Insert
    arr.insert(2, 25);
    arr.print();  // Expected: 10 20 25 30 40 50 60
    
    // Test 4: Remove
    arr.remove(0);
    arr.print();  // Expected: 20 25 30 40 50 60
    
    return 0;
}
```

---

## Problem 2: Singly Linked List Implementation (25 points)

### Description

Implement a `LinkedList` class with basic operations. The list should maintain a head pointer and support insertion, deletion, and traversal operations.

### Requirements

```cpp
class LinkedList {
private:
    struct Node {
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr) {}
    };
    
    Node* head;
    int size;

public:
    LinkedList();
    ~LinkedList();
    
    void insertFront(int value);           // Insert at beginning
    void insertBack(int value);            // Insert at end
    void insertAt(int index, int value);   // Insert at specific position
    void deleteFront();                    // Delete first element
    void deleteBack();                     // Delete last element
    int search(int value);                 // Return index of value (-1 if not found)
    void reverse();                        // Reverse the list
    void print() const;                    // Print all elements
    int getSize() const;                   // Return size
};
```

### Test Cases

```cpp
int main() {
    LinkedList list;
    
    // Test 1: Insert operations
    list.insertFront(10);
    list.insertFront(5);
    list.insertBack(20);
    list.insertBack(25);
    list.print();  // Expected: 5 → 10 → 20 → 25 → nullptr
    
    // Test 2: Insert at position
    list.insertAt(2, 15);
    list.print();  // Expected: 5 → 10 → 15 → 20 → 25 → nullptr
    
    // Test 3: Search
    cout << "Index of 15: " << list.search(15) << endl;  // Expected: 2
    cout << "Index of 100: " << list.search(100) << endl;  // Expected: -1
    
    // Test 4: Delete operations
    list.deleteFront();
    list.print();  // Expected: 10 → 15 → 20 → 25 → nullptr
    
    list.deleteBack();
    list.print();  // Expected: 10 → 15 → 20 → nullptr
    
    // Test 5: Reverse
    list.reverse();
    list.print();  // Expected: 20 → 15 → 10 → nullptr
    
    return 0;
}
```

---

## Problem 3: Stack-Based Expression Evaluator (20 points)

### Description

Implement a function that evaluates postfix expressions using a stack. Postfix notation (also called Reverse Polish Notation) places operators after operands.

**Examples:**
- `3 4 +` → `7` (equivalent to `3 + 4`)
- `3 4 + 2 *` → `14` (equivalent to `(3 + 4) * 2`)
- `5 1 2 + 4 * + 3 -` → `14` (equivalent to `5 + ((1 + 2) * 4) - 3`)

### Requirements

```cpp
#include <stack>
#include <string>
#include <sstream>

int evaluatePostfix(const string& expression);
```

### Algorithm Tip

1. Create an empty stack
2. Scan the expression from left to right:
   - If the element is a number, push it to the stack
   - If the element is an operator:
     - Pop two operands from stack
     - Perform the operation
     - Push result back to stack
3. The final result is the only element left in the stack

### Test Cases

```cpp
int main() {
    cout << evaluatePostfix("3 4 +") << endl;              // Expected: 7
    cout << evaluatePostfix("3 4 + 2 *") << endl;          // Expected: 14
    cout << evaluatePostfix("5 1 2 + 4 * + 3 -") << endl;  // Expected: 14
    cout << evaluatePostfix("15 7 1 1 + - / 3 * 2 1 1 + + -") << endl;  // Expected: 5
    
    return 0;
}
```

---

## Problem 4: Circular Queue for Task Scheduling (15 points)

### Description

Implement a `CircularQueue` class to simulate a simple task scheduler. The scheduler should process tasks in FIFO order and support a fixed maximum number of pending tasks.

### Requirements

```cpp
class CircularQueue {
private:
    string* tasks;
    int capacity;
    int frontIndex;
    int rearIndex;
    int count;

public:
    CircularQueue(int cap);
    ~CircularQueue();
    
    bool enqueue(const string& task);    // Add task, return false if full
    string dequeue();                     // Remove and return task
    string front() const;                 // View next task
    bool isEmpty() const;
    bool isFull() const;
    int size() const;
    void display() const;                 // Print all pending tasks
};
```

### Test Cases

```cpp
int main() {
    CircularQueue scheduler(5);
    
    // Test 1: Enqueue tasks
    scheduler.enqueue("Task1");
    scheduler.enqueue("Task2");
    scheduler.enqueue("Task3");
    scheduler.display();  // Expected: Task1, Task2, Task3
    
    // Test 2: Process (dequeue) some tasks
    cout << "Processing: " << scheduler.dequeue() << endl;  // Task1
    cout << "Processing: " << scheduler.dequeue() << endl;  // Task2
    scheduler.display();  // Expected: Task3
    
    // Test 3: Add more tasks (wrap around)
    scheduler.enqueue("Task4");
    scheduler.enqueue("Task5");
    scheduler.enqueue("Task6");
    scheduler.enqueue("Task7");
    scheduler.display();  // Expected: Task3, Task4, Task5, Task6, Task7
    
    // Test 4: Check if full
    cout << "Queue full? " << (scheduler.isFull() ? "Yes" : "No") << endl;  // Yes
    cout << "Can add Task8? " << (scheduler.enqueue("Task8") ? "Yes" : "No") << endl;  // No
    
    return 0;
}
```

---

## Problem 5: Merge Two Sorted Linked Lists (15 points)

### Description

Write a function that merges two sorted linked lists into a single sorted linked list. You should manipulate the pointers rather than creating new nodes.

### Requirements

```cpp
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* mergeSortedLists(Node* list1, Node* list2);

// Helper functions (provided)
void printList(Node* head);
void deleteList(Node* head);
Node* createList(vector<int> values);  // Creates a linked list from vector
```

### Test Cases

```cpp
int main() {
    // Test 1: Normal case
    Node* list1 = createList({1, 3, 5, 7});
    Node* list2 = createList({2, 4, 6, 8});
    Node* merged = mergeSortedLists(list1, list2);
    printList(merged);  // Expected: 1 → 2 → 3 → 4 → 5 → 6 → 7 → 8 → nullptr
    deleteList(merged);
    
    // Test 2: One empty list
    list1 = createList({1, 2, 3});
    list2 = nullptr;
    merged = mergeSortedLists(list1, list2);
    printList(merged);  // Expected: 1 → 2 → 3 → nullptr
    deleteList(merged);
    
    // Test 3: Lists with different lengths
    list1 = createList({1, 5, 9});
    list2 = createList({2, 3, 4, 6, 7, 8});
    merged = mergeSortedLists(list1, list2);
    printList(merged);  // Expected: 1 → 2 → 3 → 4 → 5 → 6 → 7 → 8 → 9 → nullptr
    deleteList(merged);
    
    return 0;
}
```

---

## Grading Summary

| Problem | Points | Topic |
|---------|--------|-------|
| Problem 1: Dynamic Array | 25 | Week 1-2: Memory management, Arrays |
| Problem 2: Linked List | 25 | Week 2: Linked Lists |
| Problem 3: Postfix Evaluator | 20 | Week 3: Stack Applications |
| Problem 4: Circular Queue | 15 | Week 3: Queue Implementation |
| Problem 5: Merge Lists | 15 | Week 2: Linked List Manipulation |
| **Total** | **100** | |

---

## Academic Integrity

- You may use AI tools and resources, but you must understand your code. Randomly selected solution will be evaluated verbally.
- All submitted code must be your own work.
- Plagiarism will result in zero points and potential disciplinary action.


