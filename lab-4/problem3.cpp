/**
 * Problem 3: The High-Frequency Trading Monitor
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int findKthLargest(vector<int>& nums, int k) {
    // Implement this
    return -1;
}

int main() {
    cout << "=== High-Frequency Trading Monitor ===" << endl;
    
    vector<int> transactions1 = {100, 20, 500, 10, 300, 400, 250};
    int k1 = 3;
    cout << "Transactions: ";
    for (int t : transactions1) cout << t << " ";
    cout << endl;
    cout << "The " << k1 << "-rd largest transaction: " << findKthLargest(transactions1, k1) << endl;
    cout << "(Expected: 300)" << endl;
    
    cout << "\n--- Test 2 ---" << endl;
    vector<int> transactions2 = {3, 2, 1, 5, 6, 4};
    int k2 = 2;
    cout << "Transactions: ";
    for (int t : transactions2) cout << t << " ";
    cout << endl;
    cout << "The " << k2 << "-nd largest: " << findKthLargest(transactions2, k2) << endl;
    cout << "(Expected: 5)" << endl;
    
    cout << "\n--- Test 3 ---" << endl;
    vector<int> transactions3 = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    int k3 = 4;
    cout << "The " << k3 << "-th largest: " << findKthLargest(transactions3, k3) << endl;
    cout << "(Expected: 4)" << endl;

    return 0;
}
