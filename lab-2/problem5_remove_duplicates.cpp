#include <iostream>
#include <string>
#include <stack>

using namespace std;

string removeDuplicates(const string& s) {
    // TODO: Implement remove adjacent duplicates algorithm
    // Use a stack to efficiently remove adjacent duplicate characters
    stack<char> dedup;
    string dedup_str;

    // Algorithm:
    // 1. Iterate through each character in the string
    dedup.push(0);
    for (uint i = 1; i < s.size(); i++) {
        if (!dedup.empty() && dedup.top() == s[i]) {
            dedup.pop();
        }
        else {
            dedup.push(s[i]);
        }
    }
    uint dedup_size = dedup.size();
    for (uint i = 0; i < dedup_size; i++) {
        dedup_str += dedup.top();
        dedup.pop();
    }

    if (dedup_size < s.size()) {
        return removeDuplicates(dedup_str);
    }
    return dedup_str;
    // 2. If stack is empty or top != current char, push current char
    // 3. If top == current char, pop (they cancel out)
    // 4. Build result string from stack contents 
}

int main() {
    cout << "=== Problem 5: Remove Adjacent Duplicates ===" << endl;
    
    // Test 1: Basic duplicate removal
    cout << "\nTest 1 - Basic duplicates:" << endl;
    cout << "Input:  'abbaca'" << endl;
    cout << "Output: '" << removeDuplicates("abbaca") << "'" << endl;
    // Expected: "ca"
    // Explanation: "bb" cancels, leaving "aaca", then "aa" cancels, leaving "ca"
    
    // Test 2: All characters cancel
    cout << "\nTest 2 - All cancel:" << endl;
    cout << "Input:  'aabbcc'" << endl;
    cout << "Output: '" << removeDuplicates("aabbcc") << "'" << endl;
    // Expected: ""
    
    // Test 3: No duplicates
    cout << "\nTest 3 - No duplicates:" << endl;
    cout << "Input:  'abcdef'" << endl;
    cout << "Output: '" << removeDuplicates("abcdef") << "'" << endl;
    // Expected: "abcdef"
    
    // Test 4: Multiple cancellations
    cout << "\nTest 4 - Multiple cancellations:" << endl;
    cout << "Input:  'azxxzy'" << endl;
    cout << "Output: '" << removeDuplicates("azxxzy") << "'" << endl;
    // Expected: "ay"
    // Explanation: "xx" cancels → "azzy", then "zz" cancels → "ay"
    
    // Test 5: Single character
    cout << "\nTest 5 - Single character:" << endl;
    cout << "Input:  'a'" << endl;
    cout << "Output: '" << removeDuplicates("a") << "'" << endl;
    // Expected: "a"
    
    // Test 6: Empty string
    cout << "\nTest 6 - Empty string:" << endl;
    cout << "Input:  ''" << endl;
    cout << "Output: '" << removeDuplicates("") << "'" << endl;
    // Expected: ""
    
    // Test 7: Repeated pattern
    cout << "\nTest 7 - Repeated pattern:" << endl;
    cout << "Input:  'aaabbaabb'" << endl;
    cout << "Output: '" << removeDuplicates("aaabbaabb") << "'" << endl;
    // Expected: "a"
    // Explanation: 'aa' cancel → 'a', 'bb' cancel, 'aa' cancel, 'bb' cancel → "a"
    
    // Test 8: Complex case
    cout << "\nTest 8 - Complex case:" << endl;
    cout << "Input:  'pbbcggttciiippooaaasssas'" << endl;
    cout << "Output: '" << removeDuplicates("pbbcggttciiippooaaasssas") << "'" << endl;
    // Expected: "piasas"
    
    return 0;
}

