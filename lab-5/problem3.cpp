/**
 * Problem 3: The Network Infrastructure
 * 
 * Use Union-Find to manage network connectivity.
 * Process connection and query operations.
 */

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class NetworkManager {
private:
    vector<int> parent;
    vector<int> rank_;
    int numNetworks;  // Track the number of separate networks

public:
    NetworkManager(int n) {
        parent.resize(n);
        rank_.resize(n, 0);
        numNetworks = n;  // Initially, each node is its own network
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    
    int find(int x) {
        // Implement with path compression
        return x;  // placeholder
    }
    
    // Connect two data centers
    // Remember to update numNetworks when two different networks merge!
    void connect(int x, int y) {
        // Implement this
    }
    
    // Query if two data centers can communicate
    bool canCommunicate(int x, int y) {
        // Implement this
        return false;  // placeholder
    }
    
    // Get the number of separate networks
    int getNetworkCount() {
        return numNetworks;
    }
};

int main() {
    cout << "=== Network Infrastructure Manager ===" << endl;
    
    // Test 1: Example from README
    cout << "\n--- Test 1: Basic Operations ---" << endl;
    NetworkManager nm(5);  // 5 data centers: 0, 1, 2, 3, 4
    
    cout << "Initial networks: " << nm.getNetworkCount() << " (expected: 5)" << endl;
    
    cout << "\nC 0 1 (Connect 0 and 1)" << endl;
    nm.connect(0, 1);
    
    cout << "C 2 3 (Connect 2 and 3)" << endl;
    nm.connect(2, 3);
    
    cout << "N -> " << nm.getNetworkCount() << " (expected: 3)" << endl;
    
    cout << "Q 0 2 -> " << (nm.canCommunicate(0, 2) ? "YES" : "NO") << " (expected: NO)" << endl;
    
    cout << "\nC 1 2 (Connect 1 and 2 - merges networks)" << endl;
    nm.connect(1, 2);
    
    cout << "Q 0 3 -> " << (nm.canCommunicate(0, 3) ? "YES" : "NO") << " (expected: YES)" << endl;
    cout << "N -> " << nm.getNetworkCount() << " (expected: 2)" << endl;
    
    // Test 2: Redundant connections
    cout << "\n--- Test 2: Redundant Connections ---" << endl;
    NetworkManager nm2(4);
    
    nm2.connect(0, 1);
    nm2.connect(1, 2);
    nm2.connect(2, 3);
    cout << "After connecting 0-1-2-3 in a line: " << nm2.getNetworkCount() << " networks (expected: 1)" << endl;
    
    cout << "Adding redundant connection 0-3..." << endl;
    nm2.connect(0, 3);  // Already connected!
    cout << "Networks after redundant connection: " << nm2.getNetworkCount() << " (expected: 1)" << endl;
    
    // Test 3: Interactive simulation
    cout << "\n--- Test 3: Command Simulation ---" << endl;
    NetworkManager nm3(6);
    
    vector<string> commands = {
        "C 0 1",
        "C 2 3",
        "C 4 5",
        "N",
        "Q 0 5",
        "C 1 2",
        "Q 0 3",
        "N",
        "C 3 4",
        "Q 0 5",
        "N"
    };
    
    cout << "Processing commands for 6 data centers:" << endl;
    for (const string& cmd : commands) {
        cout << "> " << cmd;
        
        if (cmd[0] == 'C') {
            int x, y;
            sscanf(cmd.c_str(), "C %d %d", &x, &y);
            nm3.connect(x, y);
            cout << endl;
        } else if (cmd[0] == 'Q') {
            int x, y;
            sscanf(cmd.c_str(), "Q %d %d", &x, &y);
            cout << " -> " << (nm3.canCommunicate(x, y) ? "YES" : "NO") << endl;
        } else if (cmd[0] == 'N') {
            cout << " -> " << nm3.getNetworkCount() << endl;
        }
    }
    
    cout << "\nExpected outputs for N: 3, 2, 1" << endl;
    cout << "Expected outputs for Q 0 5: NO, NO, YES" << endl;
    cout << "Expected outputs for Q 0 3: YES" << endl;

    return 0;
}
