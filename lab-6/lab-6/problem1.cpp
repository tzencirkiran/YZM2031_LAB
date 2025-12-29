/**
 * Problem 1: The URL Shortener
 * 
 * Implement a Hash Table with Separate Chaining to store URL mappings.
 * - insert(shortCode, longUrl): Store a mapping
 * - find(shortCode): Retrieve the long URL
 * - remove(shortCode): Delete a mapping
 */

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <math.h>

using namespace std;

class HashTableChaining {
private:
    // Each bucket is a list of (key, value) pairs
    vector<list<pair<string, string>>> table;
    int tableSize;
    int numElements;
    
    // Hash function for strings
    int hash(const string& key) {
        // TODO: Implement polynomial rolling hash
        int h_val = 0;
        int prime_pow = 0;
        const int MODULOS = 1e-7;
        const int PRIME = 31;
        for (char c : key) {
            h_val += (int(c)+ pow(PRIME, prime_pow));
            prime_pow++;
        }
        return h_val;  // placeholder
    }

public:
    HashTableChaining(int size = 101) : tableSize(size), numElements(0) {
        table.resize(tableSize);
    }
    
    // Insert a (shortCode, longUrl) pair
    // If shortCode already exists, update the longUrl
    void insert(const string& shortCode, const string& longUrl) {
        // Implement this
        for (int i = 0; i < numElements && numElements <= tableSize; i++) {
           if (table[i].front().first == shortCode) {
                pair<string, string> inserted_pair;
                inserted_pair.first = shortCode; inserted_pair.second = longUrl;
                table[i].push_back(inserted_pair);
           }
        }
        if (numElements < tableSize) {
            pair<string, string> inserted_pair;
            inserted_pair.first = shortCode; inserted_pair.second = longUrl;
            table.emplace_back(1, inserted_pair);
            numElements++;
        }
    }
    
    // Find the long URL for a given short code
    // Return empty string if not found
    string find(const string& shortCode) {
        // Implement this
        return "";  // placeholder
    }
    
    // Remove a mapping by short code
    // Return true if found and removed, false if not found
    bool remove(const string& shortCode) {
        // Implement this
        return false;  // placeholder
    }
    
    // Get current load factor
    double loadFactor() {
        return (double)numElements / tableSize;
    }
    
    // Debug: print the table contents
    void printTable() {
        cout << "Hash Table Contents:" << endl;
        for (int i = 0; i < tableSize; i++) {
            if (!table[i].empty()) {
                cout << "  Bucket " << i << ": ";
                for (const auto& pair : table[i]) {
                    cout << "[" << pair.first << " -> " << pair.second << "] ";
                }
                cout << endl;
            }
        }
        cout << "Load factor: " << loadFactor() << endl;
    }
};

// URL Shortener service using the hash table
class URLShortener {
private:
    HashTableChaining hashTable;
    int counter;
    
    // Generate a short code from a counter (base62 encoding)
    string generateShortCode() {
        const string chars = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string code = "";
        int num = counter++;
        
        // Convert number to base62
        do {
            code = chars[num % 62] + code;
            num /= 62;
        } while (num > 0);
        
        // Pad to minimum length of 6
        while (code.length() < 6) {
            code = "0" + code;
        }
        
        return code;
    }

public:
    URLShortener() : hashTable(1009), counter(1) {}  // 1009 is prime
    
    // Shorten a URL and return the short code
    string shorten(const string& longUrl) {
        string shortCode = generateShortCode();
        hashTable.insert(shortCode, longUrl);
        return shortCode;
    }
    
    // Expand a short code to the original URL
    string expand(const string& shortCode) {
        string result = hashTable.find(shortCode);
        return result.empty() ? "NOT FOUND" : result;
    }
    
    // Delete a URL mapping
    bool deleteUrl(const string& shortCode) {
        return hashTable.remove(shortCode);
    }
    
    void debug() {
        hashTable.printTable();
    }
};

int main() {
    cout << "=== URL Shortener Service ===" << endl;
    
    URLShortener shortener;
    
    // Test 1: Basic operations
    cout << "\n--- Test 1: Basic Shorten and Expand ---" << endl;
    
    string url1 = "https://www.example.com/very/long/path/to/resource";
    string url2 = "https://www.google.com/search?q=hash+tables";
    string url3 = "https://www.github.com/user/repository/blob/main/file.cpp";
    
    string code1 = shortener.shorten(url1);
    string code2 = shortener.shorten(url2);
    string code3 = shortener.shorten(url3);
    
    cout << "Shortened URLs:" << endl;
    cout << "  " << url1.substr(0, 40) << "... -> " << code1 << endl;
    cout << "  " << url2.substr(0, 40) << "... -> " << code2 << endl;
    cout << "  " << url3.substr(0, 40) << "... -> " << code3 << endl;
    
    cout << "\nExpanding short codes:" << endl;
    cout << "  " << code1 << " -> " << shortener.expand(code1) << endl;
    cout << "  " << code2 << " -> " << shortener.expand(code2) << endl;
    cout << "  " << code3 << " -> " << shortener.expand(code3) << endl;
    
    // Test 2: Non-existent code
    cout << "\n--- Test 2: Non-existent Code ---" << endl;
    cout << "  xyz999 -> " << shortener.expand("xyz999") << " (expected: NOT FOUND)" << endl;
    
    // Test 3: Delete operation
    cout << "\n--- Test 3: Delete Operation ---" << endl;
    cout << "Deleting " << code2 << "..." << endl;
    shortener.deleteUrl(code2);
    cout << "  " << code2 << " -> " << shortener.expand(code2) << " (expected: NOT FOUND)" << endl;
    
    // Test 4: Collision handling (stress test)
    cout << "\n--- Test 4: Multiple Insertions ---" << endl;
    for (int i = 0; i < 20; i++) {
        shortener.shorten("https://test.com/page" + to_string(i));
    }
    cout << "Inserted 20 more URLs." << endl;
    shortener.debug();
    
    return 0;
}
