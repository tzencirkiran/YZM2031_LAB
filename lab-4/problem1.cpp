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

    int parent(int i) { return (i-1)/2; }
    int left(int i) { return 2*i+1; }
    int right(int i) { return 2*i+2; }

    void heapify(int i) {
        // i == 0, assumes min element removed and replaced with the last element
        if (i == 0) { // perculate down, i for tracking replaced last node (after deleteMin)
            int idx_max = heap.size() - 1;
            int temp;
            while (i < idx_max && (heap[i] > left(i) || heap[i] > right(i))) {
                if (right(i) < left(i)) {
                    temp = heap[i];
                    heap[right(i)] = temp;
                    heap[i] = right(i);
                    i = right(i);
                }
                else {
                    temp = heap[i];
                    heap[left(i)] = temp;
                    heap[i] = left(i);
                    i = left(i);
                }

            }
        }
        else {
            while (i > 0 && heap[parent(i)] > heap[i]) // i is not 0 (not root), i for tracking new value
            {
                int temp = heap[i];
                heap[i] = heap[parent(i)]; // changing inserted and parnt if new<parent
                i = parent(i); // i updated with its parent's idx due to replacement
            }
        }
    }

public:
    void insert(int val) {
        // Implement this
        heap.push_back(val);
        int i = heap.size() - 1; // i for keeping track of where new value is
        heapify(i);
    }

    int extractMin() {
        // Implement this
        int min = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapify(0);

        return min;
    }

    int getMin() {
        // Implement this
        return heap[0];
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
