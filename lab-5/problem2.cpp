/**
 * Problem 2: The Social Network
 * 
 * Implement Union-Find (Disjoint Set Union) data structure
 * with path compression and union by rank optimizations.
 */

#include <iostream>
#include <vector>

using namespace std;

class UnionFind {
private:
    vector<int> parent;  // parent[i] = parent of element i
    vector<int> rank_;   // rank_[i] = rank (approximate depth) of tree rooted at i

public:
    // Initialize n elements (0 to n-1), each in its own set
    UnionFind(int n) {
        parent.resize(n);
        rank_.resize(n, 0);
        // Initially, each element is its own parent (self-loop)
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    
    // Find the representative (root) of the set containing x
    // Implement PATH COMPRESSION: make nodes point directly to root
    int find(int x) {
        // Implement this
        return x;  // placeholder
    }
    
    // Unite the sets containing x and y
    // Implement UNION BY RANK: attach smaller tree under larger tree
    void unite(int x, int y) {
        // Implement this
    }
    
    // Check if x and y are in the same set
    bool connected(int x, int y) {
        // Implement this
        return false;  // placeholder
    }
    
    // Return the number of disjoint sets
    int countSets() {
        // Implement this
        return 0;  // placeholder
    }
    
    // Debug: print the parent array
    void printParent() {
        cout << "Parent array: ";
        for (int i = 0; i < (int)parent.size(); i++) {
            cout << parent[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    cout << "=== Social Network Friend Groups ===" << endl;
    
    // Test 1: Basic operations
    cout << "\n--- Test 1: Basic Union and Find ---" << endl;
    UnionFind uf(5);  // 5 users: 0, 1, 2, 3, 4
    
    cout << "Initial state (5 users, each in their own group):" << endl;
    uf.printParent();
    cout << "Number of groups: " << uf.countSets() << " (expected: 5)" << endl;
    
    cout << "\nunite(0, 1) - Users 0 and 1 become friends" << endl;
    uf.unite(0, 1);
    uf.printParent();
    
    cout << "\nunite(2, 3) - Users 2 and 3 become friends" << endl;
    uf.unite(2, 3);
    uf.printParent();
    
    cout << "\nconnected(0, 1): " << (uf.connected(0, 1) ? "YES" : "NO") << " (expected: YES)" << endl;
    cout << "connected(0, 2): " << (uf.connected(0, 2) ? "YES" : "NO") << " (expected: NO)" << endl;
    cout << "Number of groups: " << uf.countSets() << " (expected: 3)" << endl;
    
    cout << "\nunite(1, 3) - Merges groups {0,1} and {2,3}" << endl;
    uf.unite(1, 3);
    uf.printParent();
    
    cout << "\nconnected(0, 3): " << (uf.connected(0, 3) ? "YES" : "NO") << " (expected: YES)" << endl;
    cout << "connected(0, 4): " << (uf.connected(0, 4) ? "YES" : "NO") << " (expected: NO)" << endl;
    cout << "Number of groups: " << uf.countSets() << " (expected: 2)" << endl;
    
    // Test 2: Path compression verification
    cout << "\n--- Test 2: Path Compression ---" << endl;
    UnionFind uf2(10);
    
    // Create a chain: 0 -> 1 -> 2 -> 3 -> 4
    uf2.unite(0, 1);
    uf2.unite(1, 2);
    uf2.unite(2, 3);
    uf2.unite(3, 4);
    
    cout << "After creating chain 0-1-2-3-4:" << endl;
    uf2.printParent();
    
    cout << "\nCalling find(0) should compress the path:" << endl;
    int root = uf2.find(0);
    cout << "Root of 0: " << root << endl;
    uf2.printParent();
    cout << "(After path compression, nodes should point closer to root)" << endl;
    
    // Test 3: Larger example
    cout << "\n--- Test 3: Larger Network ---" << endl;
    UnionFind uf3(8);
    
    uf3.unite(0, 1);
    uf3.unite(2, 3);
    uf3.unite(4, 5);
    uf3.unite(6, 7);
    cout << "After pairing: {0,1}, {2,3}, {4,5}, {6,7}" << endl;
    cout << "Number of groups: " << uf3.countSets() << " (expected: 4)" << endl;
    
    uf3.unite(0, 2);
    uf3.unite(4, 6);
    cout << "After merging: {0,1,2,3}, {4,5,6,7}" << endl;
    cout << "Number of groups: " << uf3.countSets() << " (expected: 2)" << endl;
    
    uf3.unite(0, 4);
    cout << "After final merge: all connected" << endl;
    cout << "Number of groups: " << uf3.countSets() << " (expected: 1)" << endl;

    return 0;
}
