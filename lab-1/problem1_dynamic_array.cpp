/**
 * YZM2031 - Lab Assignment 1
 * Problem 1: Dynamic Array Implementation
 * 
 * Student Name: Talha
 * Student ID: 25018603
 * 
 * Instructions: Implement the TODO sections below
 */

#include <iostream>
#include <stdexcept>
using namespace std;

class DynamicArray {
private:
    int* data;
    int size;        // Current number of elements
    int capacity;    // Current capacity of array

    // Helper function to resize the array when full
    void resize() {
        // TODO: Implement resize function
        int new_capacity = capacity * 2; // 1. Double the capacity
        int* new_array = new int[new_capacity]; // 2. Create a new array with new capacity
        for (int i = 0; i <= capacity-1; i++){ // 3. Copy all elements from old array to new array
            new_array[i] = data[i];
        }
        delete[] data; // 4. Delete old array
        data = new_array; // 5. Update data pointer to point to new array
        capacity = new_capacity;       
    }

public:
    // Constructor
    DynamicArray(int initialCapacity = 10) {
        // TODO: Initialize the array
        capacity = initialCapacity; // 1. Set capacity to initialCapacity
        size = 0; // 2. Set size to 0
        data = new int[capacity]; // 3. Allocate memory for data array 
    }

    // Destructor
    ~DynamicArray() {
        // TODO: Free allocated memory
        delete[] data;
    }

    // Add element to end
    void add(int value) {
        // TODO: Implement add function
        if (size >= capacity)// 1. Check if array is full (size >= capacity)
        {
            resize();
        }
        // 2. If full, call resize()
        data[size] = value;
        size++;
        // 3. Add value at index size
        // 4. Increment size
    }

    // Insert at specific position
    void insert(int index, int value) {
        // TODO: Implement insert function
        // 1. Validate index (0 <= index <= size)
        if (0 <= index && index <= size){
            if (size >= capacity){ // 2. Check if array is full, resize if needed
                resize();
            }
            for (int i = size; i >= index; i--){ // from the right side, shifts right one by one until and including                      
                data[i + 1] = data[i];          // index
            }
            data[index] = value;
            size++;
        }
        
        // 3. Shift elements from index to the right
        // 4. Insert value at index
        // 5. Increment size
        
    }

    // Remove element at index
    void remove(int index) {
        // TODO: Implement remove function
        // 1. Validate index (0 <= index < size)
        if (0 <= index && index <= size){
            for (int i = index; i <= size; i++){
                data[i] = data[i + 1];
            }
            size--;
        }
        // 2. Shift elements from index+1 to the left
        // 3. Decrement size
    }

    // Get element at index
    int get(int index) const {
        // TODO: Implement get function
        // 1. Validate index (0 <= index < size)
        int value;
        if (0 <= index && index < size){
            value = data[index]; // 2. Return element at index
        }
        return value;
    }

    // Return current size
    int getSize() const {
        return size;
    }

    // Return current capacity
    int getCapacity() const {
        return capacity;
    }

    // Print all elements
    void print() const {
        for (int i = 0; i < size; i++) {
            cout << data[i];
            if (i < size - 1) cout << " ";
        }
        cout << endl;
    }
};

// Test cases
int main() {
    cout << "=== Testing Dynamic Array ===" << endl << endl;

    DynamicArray arr(5);

    // Test 1: Add elements
    cout << "Test 1: Add elements" << endl;
    arr.add(10);
    arr.add(20);
    arr.add(30);
    arr.add(40);
    arr.add(50);
    cout << "Array: ";
    arr.print();  // Expected: 10 20 30 40 50
    cout << "Size: " << arr.getSize() << ", Capacity: " << arr.getCapacity() << endl;
    // Expected: Size: 5, Capacity: 5
    cout << endl;

    // Test 2: Trigger resize
    cout << "Test 2: Trigger resize by adding 6th element" << endl;
    arr.add(60);
    cout << "Array: ";
    arr.print();  // Expected: 10 20 30 40 50 60
    cout << "Size: " << arr.getSize() << ", Capacity: " << arr.getCapacity() << endl;
    // Expected: Size: 6, Capacity: 10
    cout << endl;

    // Test 3: Insert
    cout << "Test 3: Insert 25 at index 2" << endl;
    arr.insert(2, 25);
    cout << "Array: ";
    arr.print();  // Expected: 10 20 25 30 40 50 60
    cout << endl;

    // Test 4: Remove
    cout << "Test 4: Remove element at index 0" << endl;
    arr.remove(0);
    cout << "Array: ";
    arr.print();  // Expected: 20 25 30 40 50 60
    cout << endl;

    // Test 5: Get
    cout << "Test 5: Get element at index 2" << endl;
    cout << "Element at index 2: " << arr.get(2) << endl;  // Expected: 30
    cout << endl;

    cout << "=== All tests completed ===" << endl;

    return 0;
}

