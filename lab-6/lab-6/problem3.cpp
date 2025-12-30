/**
 * Problem 3: The Duplicate File Detector
 * 
 * Use hashing to efficiently detect duplicate files based on content.
 * - Hash file content to quickly identify potential duplicates
 * - Group files by hash value
 * - Report potential duplicate groups
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <list>

using namespace std;

// Represents a file with a name and content
struct File {
    string name;
    string content;
    
    File(string n, string c) : name(n), content(c) {}
};

class DuplicateDetector {
private:
    // Large prime for hashing
    const int MOD = 1000000007;
    
    // Compute a hash of the file content
    long long hashContent(const string& content) {
        // TODO: Implement content hashing
        int sum = 0;
        for (char c : content) {
            sum += (c % MOD);
        }
        sum = sum % MOD;
        return sum;  
    }

public:
    // Find and print groups of potential duplicate files
    // Returns the number of duplicate groups found
    int findDuplicates(const vector<File>& files) {
        // TODO: Implement duplicate detection using hash map
        int dup_groups = 0;
        vector<list<File>> hash_groups(MOD);
        for (File f : files) {
            long long hash_val = hashContent(f.content);
            hash_groups[hash_val].push_back(f);
            if (hash_groups[hash_val].size() == 2) {
                dup_groups++;
            }
        }
        return dup_groups;  // placeholder
    }
    
    // Verify if two files are actually duplicates (exact content match)
    bool verifyDuplicate(const File& f1, const File& f2) {
        return f1.content == f2.content;
    }
};

int main() {
    cout << "=== Duplicate File Detector ===" << endl;
    
    DuplicateDetector detector;
    
    // Test 1: Clear duplicates
    cout << "\n--- Test 1: Clear Duplicates ---" << endl;
    vector<File> files1 = {
        File("document1.txt", "Hello, World!"),
        File("report.txt", "This is a report about data structures."),
        File("backup.txt", "Hello, World!"),  // Duplicate of document1
        File("notes.txt", "Some random notes here."),
        File("copy.txt", "Hello, World!")     // Another duplicate
    };
    
    cout << "Files:" << endl;
    for (const auto& f : files1) {
        cout << "  " << f.name << ": \"" << f.content.substr(0, 30) << "...\"" << endl;
    }
    
    cout << "\nAnalyzing for duplicates..." << endl;
    int groups1 = detector.findDuplicates(files1);
    cout << "Found " << groups1 << " duplicate group(s)." << endl;
    
    // Test 2: No duplicates
    cout << "\n--- Test 2: No Duplicates ---" << endl;
    vector<File> files2 = {
        File("file1.txt", "Content A"),
        File("file2.txt", "Content B"),
        File("file3.txt", "Content C"),
        File("file4.txt", "Content D")
    };
    
    cout << "Files:" << endl;
    for (const auto& f : files2) {
        cout << "  " << f.name << ": \"" << f.content << "\"" << endl;
    }
    
    cout << "\nAnalyzing for duplicates..." << endl;
    int groups2 = detector.findDuplicates(files2);
    cout << "Found " << groups2 << " duplicate group(s). (expected: 0)" << endl;
    
    // Test 3: Multiple duplicate groups
    cout << "\n--- Test 3: Multiple Duplicate Groups ---" << endl;
    vector<File> files3 = {
        File("a.txt", "Alpha"),
        File("b.txt", "Beta"),
        File("c.txt", "Alpha"),   // Dup of a.txt
        File("d.txt", "Gamma"),
        File("e.txt", "Beta"),    // Dup of b.txt
        File("f.txt", "Alpha"),   // Dup of a.txt
        File("g.txt", "Delta"),
        File("h.txt", "Beta")     // Dup of b.txt
    };
    
    cout << "Files:" << endl;
    for (const auto& f : files3) {
        cout << "  " << f.name << ": \"" << f.content << "\"" << endl;
    }
    
    cout << "\nAnalyzing for duplicates..." << endl;
    int groups3 = detector.findDuplicates(files3);
    cout << "Found " << groups3 << " duplicate group(s). (expected: 2)" << endl;
    
    // Test 4: Hash collision awareness
    cout << "\n--- Test 4: Verification Step ---" << endl;
    File f1("test1.txt", "Hello");
    File f2("test2.txt", "Hello");
    File f3("test3.txt", "World");
    
    cout << "Verifying actual content match:" << endl;
    cout << "  test1.txt vs test2.txt: " 
         << (detector.verifyDuplicate(f1, f2) ? "MATCH" : "DIFFERENT") 
         << " (expected: MATCH)" << endl;
    cout << "  test1.txt vs test3.txt: " 
         << (detector.verifyDuplicate(f1, f3) ? "MATCH" : "DIFFERENT") 
         << " (expected: DIFFERENT)" << endl;
    
    return 0;
}
