/**
 * Problem 4: The Two Sum Problem
 * 
 * Classic coding interview problem solved efficiently using a hash table.
 * Given an array of integers and a target sum, find two numbers that add up to the target.
 * 
 * Naive: O(N^2) - check all pairs
 * Optimal: O(N) - use hash table to store complements
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class TwoSumSolver {
public:
    // Find two indices whose comp_pairs sum to target
    // Return {-1, -1} if no solution exists
    // Time: O(N), Space: O(N)
    pair<int, int> twoSum(const vector<int>& nums, int target) {
        // TODO: Implement using hash map for O(N) solution
        unordered_map<int, pair<int, int>> num_comp; // int for num, pair for idx of itself and complement

        for (int idx = 0; idx < nums.size(); idx++) {
            int num = nums[idx];
            pair<int, int> num_pair = {idx, -1}; // indice pair of num

            int complement = target - num;
            if (num_comp.find(num) != num_comp.end()) { // if num already in the table
                auto comp_it = num_comp.find(complement);
                if (comp_it == num_comp.end()) {    // if complement is not yet in the table, assign default
                    num_comp[complement] = {-1, num_comp[num].first};
                }
                else if (num_comp[complement].first == -1) {
                    continue;   // iterate until we find complement in the nums, comp already exists in table
                }
                else {  // if we have complement in table update both comp_pair and num_pair
                    if (num_comp[num].first == -1) num_comp[num].first = idx;
                    num_comp[num].second = num_comp[complement].first;  
                    num_comp[complement].second = num_comp[num].first;
                    return num_comp[num];
                }
            }
            else {  // initialize num in the table as key with {idx, -1}
                num_comp[num] = num_pair;
                idx--;
                continue;
            }
            
        }
        
        return {-1, -1};  // placeholder
    }
    
    // Find ALL pairs of indices that sum to target
    // Returns a vector of index pairs
    vector<pair<int, int>> twoSumAll(const vector<int>& nums, int target) {
        // TODO: Implement (bonus challenge)
        return {};  // placeholder
    }
};

// Helper function to print the result
void printResult(const pair<int, int>& result, const vector<int>& nums, int target) {
    if (result.first == -1) {
        cout << "  No solution found." << endl;
    } else {
        cout << "  Indices: [" << result.first << ", " << result.second << "]" << endl;
        cout << "  comp_pairs: " << nums[result.first] << " + " << nums[result.second] 
             << " = " << target << endl;
    }
}

int main() {
    cout << "=== Two Sum Problem ===" << endl;
    
    TwoSumSolver solver;
    
    // Test 1: Basic case
    cout << "\n--- Test 1: Basic Case ---" << endl;
    vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    cout << "Array: [2, 7, 11, 15], Target: " << target1 << endl;
    auto result1 = solver.twoSum(nums1, target1);
    printResult(result1, nums1, target1);
    cout << "Expected: [0, 1] (2 + 7 = 9)" << endl;
    
    // Test 2: Solution in middle
    cout << "\n--- Test 2: Solution in Middle ---" << endl;
    vector<int> nums2 = {3, 2, 4};
    int target2 = 6;
    cout << "Array: [3, 2, 4], Target: " << target2 << endl;
    auto result2 = solver.twoSum(nums2, target2);
    printResult(result2, nums2, target2);
    cout << "Expected: [1, 2] (2 + 4 = 6)" << endl;
    
    // Test 3: Same element twice (but different indices)
    cout << "\n--- Test 3: Duplicate comp_pairs ---" << endl;
    vector<int> nums3 = {3, 3};
    int target3 = 6;
    cout << "Array: [3, 3], Target: " << target3 << endl;
    auto result3 = solver.twoSum(nums3, target3);
    printResult(result3, nums3, target3);
    cout << "Expected: [0, 1] (3 + 3 = 6)" << endl;
    
    // Test 4: No solution
    cout << "\n--- Test 4: No Solution ---" << endl;
    vector<int> nums4 = {1, 2, 3, 4, 5};
    int target4 = 100;
    cout << "Array: [1, 2, 3, 4, 5], Target: " << target4 << endl;
    auto result4 = solver.twoSum(nums4, target4);
    printResult(result4, nums4, target4);
    cout << "Expected: No solution" << endl;
    
    // Test 5: Negative numbers
    cout << "\n--- Test 5: Negative Numbers ---" << endl;
    vector<int> nums5 = {-3, 4, 3, 90};
    int target5 = 0;
    cout << "Array: [-3, 4, 3, 90], Target: " << target5 << endl;
    auto result5 = solver.twoSum(nums5, target5);
    printResult(result5, nums5, target5);
    cout << "Expected: [0, 2] (-3 + 3 = 0)" << endl;
    
    // Test 6: Large array (performance test)
    cout << "\n--- Test 6: Large Array Performance ---" << endl;
    vector<int> nums6;
    for (int i = 0; i < 100000; i++) {
        nums6.push_back(i);
    }
    int target6 = 199997;  // 99998 + 99999
    cout << "Array: [0, 1, 2, ..., 99999] (100,000 elements)" << endl;
    cout << "Target: " << target6 << endl;
    
    auto result6 = solver.twoSum(nums6, target6);
    printResult(result6, nums6, target6);
    cout << "Expected: [99998, 99999]" << endl;
    cout << "(If this runs instantly, your O(N) solution works!)" << endl;
    
    // Bonus: Find all pairs
    cout << "\n--- Bonus: Find All Pairs ---" << endl;
    vector<int> nums7 = {1, 5, 3, 3, 5, 1};
    int target7 = 6;
    cout << "Array: [1, 5, 3, 3, 5, 1], Target: " << target7 << endl;
    auto allPairs = solver.twoSumAll(nums7, target7);
    cout << "All pairs that sum to " << target7 << ":" << endl;
    if (allPairs.empty()) {
        cout << "  (Not implemented or no pairs found)" << endl;
    } else {
        for (const auto& p : allPairs) {
            cout << "  [" << p.first << ", " << p.second << "] -> " 
                 << nums7[p.first] << " + " << nums7[p.second] << endl;
        }
    }
    
    return 0;
}
