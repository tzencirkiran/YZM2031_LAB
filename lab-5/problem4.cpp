/**
 * Problem 4: The Database Index Builder
 * 
 * Implement and compare linear-time sorting algorithms:
 * - Counting Sort: O(N + K) for small range K
 * - Radix Sort: O(d * (N + K)) for larger integers
 * 
 * Compare with Quick Sort O(N log N)
 */

#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

using namespace std;
using namespace std::chrono;

// Counting Sort
// Works well when range of values (max - min) is small
// Time: O(N + K) where K is the range
// Space: O(K) for the count array
void countingSort(vector<int>& arr, int maxVal) {
    // Implement this
}

// Counting Sort for a specific digit (used by Radix Sort)
// This version is stable - preserves relative order of equal elements
void countingSortByDigit(vector<int>& arr, int exp) {
    // Implement this
}

// Radix Sort (LSD - Least Significant Digit first)
// Sorts integers digit by digit from least to most significant
// Time: O(d * (N + 10)) where d is number of digits
void radixSort(vector<int>& arr) {
    // Implement this
}

// Quick Sort for comparison
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Helper function to generate random data
vector<int> generateRandomData(int size, int maxVal) {
    vector<int> data(size);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, maxVal);
    
    for (int i = 0; i < size; i++) {
        data[i] = dis(gen);
    }
    return data;
}

// Helper function to verify sorting
bool isSorted(const vector<int>& arr) {
    for (size_t i = 1; i < arr.size(); i++) {
        if (arr[i] < arr[i-1]) return false;
    }
    return true;
}

int main() {
    cout << "=== Database Index Builder Benchmark ===" << endl;
    
    const int SIZE = 100000;
    
    // Test 1: Counting Sort for small range (ages: 0-150)
    cout << "\n--- Test 1: Sorting Ages (Range 0-150) ---" << endl;
    const int MAX_AGE = 150;
    
    vector<int> ages1 = generateRandomData(SIZE, MAX_AGE);
    vector<int> ages2 = ages1;  // Copy for Quick Sort comparison
    
    cout << "Data size: " << SIZE << " records" << endl;
    
    auto start = high_resolution_clock::now();
    countingSort(ages1, MAX_AGE);
    auto end = high_resolution_clock::now();
    auto countingTime = duration_cast<milliseconds>(end - start);
    
    start = high_resolution_clock::now();
    quickSort(ages2, 0, ages2.size() - 1);
    end = high_resolution_clock::now();
    auto quickTime1 = duration_cast<milliseconds>(end - start);
    
    cout << "Counting Sort: " << countingTime.count() << " ms" << endl;
    cout << "Quick Sort:    " << quickTime1.count() << " ms" << endl;
    cout << "Counting Sort correct: " << (isSorted(ages1) ? "YES" : "NO") << endl;
    
    // Test 2: Radix Sort for larger range (IDs: 0-999999)
    cout << "\n--- Test 2: Sorting IDs (Range 0-999,999) ---" << endl;
    const int MAX_ID = 999999;
    
    vector<int> ids1 = generateRandomData(SIZE, MAX_ID);
    vector<int> ids2 = ids1;  // Copy for Quick Sort comparison
    
    start = high_resolution_clock::now();
    radixSort(ids1);
    end = high_resolution_clock::now();
    auto radixTime = duration_cast<milliseconds>(end - start);
    
    start = high_resolution_clock::now();
    quickSort(ids2, 0, ids2.size() - 1);
    end = high_resolution_clock::now();
    auto quickTime2 = duration_cast<milliseconds>(end - start);
    
    cout << "Radix Sort: " << radixTime.count() << " ms" << endl;
    cout << "Quick Sort: " << quickTime2.count() << " ms" << endl;
    cout << "Radix Sort correct: " << (isSorted(ids1) ? "YES" : "NO") << endl;
    
    // Test 3: Verify correctness with small example
    cout << "\n--- Test 3: Correctness Check ---" << endl;
    vector<int> small = {170, 45, 75, 90, 802, 24, 2, 66};
    
    cout << "Original: ";
    for (int x : small) cout << x << " ";
    cout << endl;
    
    radixSort(small);
    
    cout << "After Radix Sort: ";
    for (int x : small) cout << x << " ";
    cout << endl;
    cout << "Expected: 2 24 45 66 75 90 170 802" << endl;
    
    // Test 4: Edge cases
    cout << "\n--- Test 4: Edge Cases ---" << endl;
    
    vector<int> empty = {};
    countingSort(empty, 100);
    cout << "Empty array: " << (empty.empty() ? "PASS" : "FAIL") << endl;
    
    vector<int> single = {42};
    countingSort(single, 100);
    cout << "Single element: " << (single[0] == 42 ? "PASS" : "FAIL") << endl;
    
    vector<int> duplicates = {5, 5, 5, 5, 5};
    countingSort(duplicates, 10);
    cout << "All duplicates: " << (isSorted(duplicates) ? "PASS" : "FAIL") << endl;

    return 0;
}
