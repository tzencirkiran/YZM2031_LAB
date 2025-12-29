/**
 * Problem 2: The Student Record System
 * 
 * Implement a Hash Table with Linear Probing (Open Addressing).
 * - insert(id, name, gpa): Add a student record
 * - find(id): Retrieve a student's data
 * - remove(id): Delete a student record (using lazy deletion)
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Student {
    int id;
    string name;
    double gpa;
    
    Student() : id(-1), name(""), gpa(0.0) {}
    Student(int i, string n, double g) : id(i), name(n), gpa(g) {}
};

class HashTableLinearProbing {
private:
    vector<Student> table;
    vector<bool> occupied;   // true if slot has data
    vector<bool> deleted;    // true if slot was deleted (tombstone)
    int tableSize;
    int numElements;
    
    // Hash function: simple modulo
    int hash(int key) {
        return key % tableSize;
    }
    
    // Linear probing: find the next slot
    // Returns the index where the key is found, or where it should be inserted
    // If searching, returns -1 if not found
    int probe(int key, bool isSearching) {
        // TODO: Implement linear probing
        int idx = hash(key);
        while (occupied[idx] == true) {
            if (isSearching == true && table[idx].id == key) {
                return idx;
            }
            idx++;
        }
        if (isSearching) return -1;
        else return idx;  
    }

public:
    HashTableLinearProbing(int size = 101) : tableSize(size), numElements(0) {
        table.resize(tableSize);
        occupied.resize(tableSize, false);
        deleted.resize(tableSize, false);
    }
    
    // Insert a student record
    // If student ID already exists, update the record
    void insert(int id, const string& name, double gpa) {
        // TODO: Implement insertion with linear probing
        int id_place = probe(id, true);
        if (id_place == -1) {
            int idx = probe(id, false); 
            table[idx] = Student(id, name, gpa);
            occupied[idx] = true;
            numElements++;
        }
        else {
            table[id_place].id = id;
            table[id_place].name = name;
            table[id_place].gpa = gpa;
        }
        
    }
    
    // Find a student by ID
    // Returns pointer to student if found, nullptr if not found
    Student* find(int id) {
        // Implement this
        int id_place = probe(id, true);
        if (id_place == -1) return nullptr;
        else if (!deleted[id_place]) {
            return &table[id_place];
        }
        else return nullptr;
    }
    
    // Remove a student by ID (lazy deletion)
    // Return true if found and removed, false if not found
    bool remove(int id) {
        // TODO: Implement lazy deletion
        int id_place = probe(id, true);
        if (id_place == -1) return false;
        else deleted[id_place] = true;
        return true;  // placeholder
    }
    
    // Get current load factor
    double loadFactor() {
        return (double)numElements / tableSize;
    }
    
    // Debug: print the table
    void printTable() {
        cout << "Hash Table (Linear Probing):" << endl;
        for (int i = 0; i < tableSize; i++) {
            cout << "  [" << i << "]: ";
            if (deleted[i]) {
                cout << "DELETED";
            } else if (occupied[i]) {
                cout << "ID=" << table[i].id << ", " << table[i].name << ", GPA=" << table[i].gpa;
            } else {
                cout << "EMPTY";
            }
            cout << endl;
        }
        cout << "Load factor: " << loadFactor() << endl;
    }
};

int main() {
    cout << "=== Student Record System ===" << endl;
    
    // Use a small table to demonstrate collisions
    HashTableLinearProbing records(11);  // Prime number
    
    // Test 1: Basic insertions
    cout << "\n--- Test 1: Basic Insertions ---" << endl;
    records.insert(12345, "Alice", 3.8);
    records.insert(67890, "Bob", 3.5);
    records.insert(11111, "Charlie", 3.9);
    records.insert(22222, "Diana", 3.7);
    
    cout << "Inserted 4 students." << endl;
    records.printTable();
    
    // Test 2: Find operations
    cout << "\n--- Test 2: Find Operations ---" << endl;
    
    Student* s1 = records.find(12345);
    if (s1) {
        cout << "Found ID 12345: " << s1->name << ", GPA=" << s1->gpa << endl;
    } else {
        cout << "ID 12345 not found!" << endl;
    }
    
    Student* s2 = records.find(99999);
    if (s2) {
        cout << "Found ID 99999: " << s2->name << endl;
    } else {
        cout << "ID 99999 not found (expected)" << endl;
    }
    
    // Test 3: Collision handling
    cout << "\n--- Test 3: Collision Handling ---" << endl;
    // Insert keys that will collide (same hash value)
    // With tableSize=11: 5, 16, 27, 38 all hash to index 5
    records.insert(5, "Eve", 3.6);
    records.insert(16, "Frank", 3.4);
    records.insert(27, "Grace", 3.8);
    
    cout << "Inserted 3 colliding keys (5, 16, 27 all hash to 5)." << endl;
    records.printTable();
    
    // Verify we can find all of them
    cout << "\nVerifying all records are findable:" << endl;
    for (int id : {5, 16, 27}) {
        Student* s = records.find(id);
        if (s) {
            cout << "  Found ID " << id << ": " << s->name << endl;
        } else {
            cout << "  ID " << id << " NOT FOUND (ERROR!)" << endl;
        }
    }
    
    // Test 4: Deletion with lazy deletion
    cout << "\n--- Test 4: Lazy Deletion ---" << endl;
    cout << "Removing ID 16 (middle of collision chain)..." << endl;
    records.remove(16);
    records.printTable();
    
    cout << "\nVerifying ID 27 is still findable after deleting ID 16:" << endl;
    Student* s3 = records.find(27);
    if (s3) {
        cout << "  Found ID 27: " << s3->name << " (lazy deletion works!)" << endl;
    } else {
        cout << "  ID 27 NOT FOUND (lazy deletion broken!)" << endl;
    }
    
    // Test 5: Update existing record
    cout << "\n--- Test 5: Update Existing Record ---" << endl;
    cout << "Updating Alice's GPA from 3.8 to 4.0..." << endl;
    records.insert(12345, "Alice", 4.0);
    Student* s4 = records.find(12345);
    if (s4) {
        cout << "  Alice's new GPA: " << s4->gpa << " (expected: 4.0)" << endl;
    }
    
    return 0;
}
