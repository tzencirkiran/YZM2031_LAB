/**
 * Problem 2: The Mars Rover Memory Constraint
 */

#include <iostream>
#include <vector>

using namespace std;

void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int l = 2 * i + 1; // Left Child
    int r = 2 * i + 2; // Right Child
    if (l < n && arr[l] > arr[largest]) 
        largest = l;
    if (r < n && arr[r] > arr[largest]) 
        largest = r;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }

}

void heapSort(vector<int>& arr) {
    // Implement this
    int n = arr.size();
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    // Extract element from heap one by one
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]); // Move root to end
        heapify(arr, i, 0);
    }
}

void printArray(vector<int>& arr) {
    for (int i : arr) cout << i << " ";
    cout << endl;
}

int main() {
    cout << "=== Mars Rover Sensor Data Sorting ===" << endl;
    
    vector<int> sensorData = {64, 25, 12, 22, 11, 90, 42, 7, 36};
    
    cout << "Raw sensor readings: ";
    printArray(sensorData);
    
    heapSort(sensorData);
    
    cout << "Sorted for transmission: ";
    printArray(sensorData);
    
    cout << "\n--- Test 2: Already sorted input ---" << endl;
    vector<int> sorted = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << "Input: ";
    printArray(sorted);
    heapSort(sorted);
    cout << "After Heap Sort: ";
    printArray(sorted);
    
    cout << "\n--- Test 3: Reverse sorted input ---" << endl;
    vector<int> reverse = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    cout << "Input: ";
    printArray(reverse);
    heapSort(reverse);
    cout << "After Heap Sort: ";
    printArray(reverse);

    return 0;
}
