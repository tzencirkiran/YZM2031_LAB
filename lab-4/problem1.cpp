/**
 * Problem 1: The Emergency Room Triage
 */

#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

class MinHeap {
private:
    vector<int> heap;

    int parent(int i) { return -1; }
    int left(int i) { return -1; }
    int right(int i) { return -1; }

    void heapify(int i) {
        // Implement this
    }

public:
    void insert(int val) {
        // Implement this
    }

    int extractMin() {
        // Implement this
        return -1;
    }

    int getMin() {
        // Implement this
        return -1;
    }

    bool isEmpty() {
        return heap.empty();
    }
    
    void printHeap() {
        for (int i : heap) cout << i << " ";
        cout << endl;
    }
};

int main() {
    MinHeap h;
    
    cout << "=== Emergency Room Triage System ===" << endl;
    cout << "Inserting patients with severity scores: 10, 5, 30, 2, 8" << endl;
    
    h.insert(10);
    h.insert(5);
    h.insert(30);
    h.insert(2);
    h.insert(8);
    
    cout << "Heap state: ";
    h.printHeap();
    
    cout << "Most critical patient (Min): " << h.getMin() << endl;
    
    cout << "Treating patient: " << h.extractMin() << endl;
    cout << "Heap after extraction: ";
    h.printHeap();
    
    cout << "Treating next patient: " << h.extractMin() << endl;
    cout << "Heap after extraction: ";
    h.printHeap();

    return 0;
}
