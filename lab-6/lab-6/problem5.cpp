/**
 * Problem 5: The Anagram Grouper
 * 
 * Group words that are anagrams of each other using hash tables.
 * Two words are anagrams if they contain the same letters with the same frequencies.
 * 
 * Key insight: Instead of sorting each word O(K log K), generate a "signature"
 * based on character counts in O(K) time.
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class AnagramGrouper {
private:
    // Generate a signature for a word that identifies its anagram group
    string getSignature(const string& word) {
        // TODO: Implement signature generation
        return "";  // placeholder
    }

public:
    // Group anagrams together
    // Returns a vector of groups, where each group is a vector of anagram words
    vector<vector<string>> groupAnagrams(const vector<string>& words) {
        // TODO: Implement anagram grouping using signatures
        return {};  // placeholder
    }
    
    // Check if two words are anagrams
    bool areAnagrams(const string& word1, const string& word2) {
        // TODO: Implement anagram check
        return false;  // placeholder
    }
};

// Helper function to print groups
void printGroups(const vector<vector<string>>& groups) {
    int groupNum = 1;
    for (const auto& group : groups) {
        cout << "  Group " << groupNum++ << ": [";
        for (size_t i = 0; i < group.size(); i++) {
            cout << "\"" << group[i] << "\"";
            if (i < group.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
}

int main() {
    cout << "=== Anagram Grouper ===" << endl;
    
    AnagramGrouper grouper;
    
    // Test 1: Classic example
    cout << "\n--- Test 1: Classic Example ---" << endl;
    vector<string> words1 = {"eat", "tea", "tan", "ate", "nat", "bat"};
    cout << "Words: [\"eat\", \"tea\", \"tan\", \"ate\", \"nat\", \"bat\"]" << endl;
    cout << "Grouped anagrams:" << endl;
    auto groups1 = grouper.groupAnagrams(words1);
    printGroups(groups1);
    cout << "Expected: [eat, tea, ate], [tan, nat], [bat]" << endl;
    
    // Test 2: Single word groups
    cout << "\n--- Test 2: No Anagrams ---" << endl;
    vector<string> words2 = {"abc", "def", "ghi"};
    cout << "Words: [\"abc\", \"def\", \"ghi\"]" << endl;
    cout << "Grouped anagrams:" << endl;
    auto groups2 = grouper.groupAnagrams(words2);
    printGroups(groups2);
    cout << "Expected: Each word in its own group" << endl;
    
    // Test 3: All anagrams
    cout << "\n--- Test 3: All Anagrams ---" << endl;
    vector<string> words3 = {"listen", "silent", "enlist", "inlets", "tinsel"};
    cout << "Words: [\"listen\", \"silent\", \"enlist\", \"inlets\", \"tinsel\"]" << endl;
    cout << "Grouped anagrams:" << endl;
    auto groups3 = grouper.groupAnagrams(words3);
    printGroups(groups3);
    cout << "Expected: All 5 words in one group" << endl;
    
    // Test 4: Empty string and single characters
    cout << "\n--- Test 4: Edge Cases ---" << endl;
    vector<string> words4 = {"", "a", "b", "a", ""};
    cout << "Words: [\"\", \"a\", \"b\", \"a\", \"\"]" << endl;
    cout << "Grouped anagrams:" << endl;
    auto groups4 = grouper.groupAnagrams(words4);
    printGroups(groups4);
    
    // Test 5: Anagram check function
    cout << "\n--- Test 5: Anagram Verification ---" << endl;
    cout << "Are 'listen' and 'silent' anagrams? " 
         << (grouper.areAnagrams("listen", "silent") ? "YES" : "NO")
         << " (expected: YES)" << endl;
    cout << "Are 'hello' and 'world' anagrams? " 
         << (grouper.areAnagrams("hello", "world") ? "YES" : "NO")
         << " (expected: NO)" << endl;
    cout << "Are 'race' and 'care' anagrams? " 
         << (grouper.areAnagrams("race", "care") ? "YES" : "NO")
         << " (expected: YES)" << endl;
    
    // Test 6: Performance test with many words
    cout << "\n--- Test 6: Performance Test ---" << endl;
    vector<string> words6;
    // Generate variations of "abc", "bca", "cab", etc.
    string base = "algorithm";
    for (int i = 0; i < 1000; i++) {
        string word = base;
        // Shuffle to create anagrams
        for (int j = 0; j < i % 10; j++) {
            int p1 = (i + j) % word.length();
            int p2 = (i * 2 + j) % word.length();
            swap(word[p1], word[p2]);
        }
        words6.push_back(word);
    }
    cout << "Grouping 1000 variations of 'algorithm'..." << endl;
    auto groups6 = grouper.groupAnagrams(words6);
    cout << "Number of groups: " << groups6.size() << endl;
    cout << "(Should be 1 if all are anagrams of 'algorithm')" << endl;
    
    return 0;
}
