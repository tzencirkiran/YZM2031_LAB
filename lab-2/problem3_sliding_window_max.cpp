#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> result;
    deque<int> dq;  // Store indices, not values!
    // TODO: Implement the sliding window maximum algorithm

    for (uint i = 0; i < result.size()-(k-1); i++) {
        if (!dq.empty() && nums[i] >= nums[dq.front()]) {
            dq.push_front(i);
        }
        else {
            dq.push_back(i);
        }
        
        dq.push_front(i);
        if (dq.size() == k) {
            result[i-k+1] = dq.front();
            dq.pop_back();
        }
    }
    // Hint: Maintain deque in decreasing order of values
    // Hint: Store indices in the deque, not values
    // Hint: Remove indices outside the current window
    // Hint: Remove indices whose values are smaller than current
    
    return result;
}

int main() {
    cout << "=== Problem 3: Sliding Window Maximum ===" << endl;
    
    // Test 1: Example from description
    cout << "\nTest 1 - Basic sliding window:" << endl;
    vector<int> nums1 = {1, 3, -1, -3, 5, 3, 6, 7};
    vector<int> result1 = maxSlidingWindow(nums1, 3);
    cout << "Array: [1, 3, -1, -3, 5, 3, 6, 7], k=3" << endl;
    cout << "Result: ";
    for (int val : result1) {
        cout << val << " ";
    }
    cout << endl;  // Expected: 3 3 5 5 6 7
    
    // Test 2: All decreasing
    cout << "\nTest 2 - All decreasing:" << endl;
    vector<int> nums2 = {5, 4, 3, 2, 1};
    vector<int> result2 = maxSlidingWindow(nums2, 2);
    cout << "Array: [5, 4, 3, 2, 1], k=2" << endl;
    cout << "Result: ";
    for (int val : result2) {
        cout << val << " ";
    }
    cout << endl;  // Expected: 5 4 3 2
    
    // Test 3: All increasing
    cout << "\nTest 3 - All increasing:" << endl;
    vector<int> nums3 = {1, 2, 3, 4, 5};
    vector<int> result3 = maxSlidingWindow(nums3, 3);
    cout << "Array: [1, 2, 3, 4, 5], k=3" << endl;
    cout << "Result: ";
    for (int val : result3) {
        cout << val << " ";
    }
    cout << endl;  // Expected: 3 4 5
    
    // Test 4: Window size = 1
    cout << "\nTest 4 - Window size = 1:" << endl;
    vector<int> nums4 = {7, 2, 4};
    vector<int> result4 = maxSlidingWindow(nums4, 1);
    cout << "Array: [7, 2, 4], k=1" << endl;
    cout << "Result: ";
    for (int val : result4) {
        cout << val << " ";
    }
    cout << endl;  // Expected: 7 2 4
    
    // Test 5: Window size = array length
    cout << "\nTest 5 - Window size = array length:" << endl;
    vector<int> nums5 = {9, 11, 8, 5};
    vector<int> result5 = maxSlidingWindow(nums5, 4);
    cout << "Array: [9, 11, 8, 5], k=4" << endl;
    cout << "Result: ";
    for (int val : result5) {
        cout << val << " ";
    }
    cout << endl;  // Expected: 11
    
    return 0;
}
