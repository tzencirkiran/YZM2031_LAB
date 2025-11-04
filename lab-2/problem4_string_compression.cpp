#include <iostream>
#include <string>

using namespace std;

string compressString(const string& str) {
    // TODO: Implement string compression
    string compressed_str;
    int char_count = 1;
    for (uint i = 1; i < str.size(); i++) {
        if (str[i] == str[i-1]) {
            char_count++;
            if (i == str.size()-1) {
                compressed_str = compressed_str + str[i] + to_string(char_count);
            }
            continue;
        }
        else {
            if (i == str.size()-1 && char_count==1) {
                compressed_str = compressed_str + str[i] + to_string(char_count);
                break;
            }
            else if (i == str.size()-1) {
                char_count++;
            }
        }  
        compressed_str = compressed_str + str[i-1] + to_string(char_count); // appends previous char and then...
        char_count = 1;  
    }
    switch (compressed_str.size() > 0 && compressed_str.size() < str.size()) {
        case 1:
        return compressed_str;
        break;
        case 0:
        return str;
        break;
    }
    // Algorithm:
    // 1. Track current character and its count
    // 2. When character changes, append "char + count" to result
    // 3. Don't forget the last character group!
    // 4. Compare lengths and return the shorter string
    
}

int main() {
    cout << "=== Problem 4: String Compression ===" << endl;
    
    // Test 1: String that compresses well
    cout << "\nTest 1 - Good compression:" << endl;
    cout << "Input:  'aabcccccaaa'" << endl;
    cout << "Output: '" << compressString("aabcccccaaa") << "'" << endl;
    // Expected: "a2b1c5a3"
    
    // Test 2: String that doesn't compress
    cout << "\nTest 2 - No compression benefit:" << endl;
    cout << "Input:  'abc'" << endl;
    cout << "Output: '" << compressString("abc") << "'" << endl;
    // Expected: "abc"
    
    // Test 3: String with same compressed length
    cout << "\nTest 3 - Same length:" << endl;
    cout << "Input:  'aabbcc'" << endl;
    cout << "Output: '" << compressString("aabbcc") << "'" << endl;
    // Expected: "aabbcc"
    
    // Test 4: Long run of same character
    cout << "\nTest 4 - Long run:" << endl;
    cout << "Input:  'aaaaaaaaaa' (10 a's)" << endl;
    cout << "Output: '" << compressString("aaaaaaaaaa") << "'" << endl;
    // Expected: "a10"
    
    // Test 5: All different characters
    cout << "\nTest 5 - All different:" << endl;
    cout << "Input:  'abcdefg'" << endl;
    cout << "Output: '" << compressString("abcdefg") << "'" << endl;
    // Expected: "abcdefg"
    
    // Test 6: Empty string
    cout << "\nTest 6 - Empty string:" << endl;
    cout << "Input:  ''" << endl;
    cout << "Output: '" << compressString("") << "'" << endl;
    // Expected: ""
    
    // Test 7: Single character
    cout << "\nTest 7 - Single character:" << endl;
    cout << "Input:  'a'" << endl;
    cout << "Output: '" << compressString("a") << "'" << endl;
    // Expected: "a"
    
    // Test 8: Multiple groups
    cout << "\nTest 8 - Multiple groups:" << endl;
    cout << "Input:  'aaabbbccc'" << endl;
    cout << "Output: '" << compressString("aaabbbccc") << "'" << endl;
    // Expected: "a3b3c3"
    
    return 0;
}
