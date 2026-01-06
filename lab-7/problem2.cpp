/**
 * Problem 2: Six Degrees of Separation
 * 
 * Implement BFS to find the shortest path between two users in a social network.
 * - Find minimum number of hops between two users
 * - Return the actual path as a sequence of user IDs
 * - Return empty path if no connection exists
 */

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <string>

using namespace std;

class SocialGraph {
private:
    // Adjacency list: user -> list of friends (undirected graph)
    unordered_map<string, vector<string>> adjList;

    pair<string, bool> pair_s(const string& s, bool visited=false) {
        return {s, visited};
    }

public:
    // Add a user to the network
    void addUser(const string& user) {
        if (adjList.find(user) == adjList.end()) {
            adjList[user] = {};
        }
    }
    
    // Add a friendship (undirected edge)
    void addFriendship(const string& user1, const string& user2) {
        addUser(user1);
        addUser(user2);
        adjList[user1].push_back(user2);
        adjList[user2].push_back(user1);
    }
    
    // Check if a user exists
    bool userExists(const string& user) {
        return adjList.find(user) != adjList.end();
    }
    
    // BFS to find shortest path between two users
    // Returns the path as a vector of user names
    // Returns empty vector if no path exists or users don't exist
    vector<string> shortestPath(const string& start, const string& end) {
        // Check if both users exist
        if (!userExists(start) || !userExists(end)) {
            return {};
        }
        
        // Same user - path is just that user
        if (start == end) {
            return {start};
        }
        
        // TODO: Implement BFS
        // For each vertex v of the graph, go to each neighbour of the v, mark v as visited
        // each v and its neighbours will be added to the queee, if all neighbours of v traversed
        // v will be popped from the queue
        // repeat untill all nodes in the graph has been traversed (no node left in queueu)
        queue<string> q;
        unordered_map<string, bool> visited;
        unordered_map<string, int> distances;
        unordered_map<string, string> parents;

        q.push(start);
        visited.insert(pair_s(start, true));
        parents[start] = start;
        distances[start] = 0;

        while (!q.empty()) {
            string current_v = q.front();
            q.pop();
            visited[current_v] = true;
            

            // for each neighbour of current_v
            for (string n_v : adjList[current_v]) {
                if (visited[n_v] == false) {
                    visited[n_v] == true;
                    q.push(n_v);
                    parents[n_v] = current_v;
                    distances[n_v] = distances[current_v] + 1;
                }
            }
        }

        if (distances.find(end) == distances.end()) {
            return {};
        }
        int d = distances[end];
        vector<string> path(d + 1);
        string current_node = end;
        for (d; d >= 0; d--) {
            path[d] = current_node;
            current_node = parents[current_node];
        }

        return path;  // placeholder
    }

    // Get the distance (number of hops) between two users
    // Returns -1 if no path exists
    int getDistance(const string& start, const string& end) {
        vector<string> path = shortestPath(start, end);
        if (path.empty()) {
            return -1;
        }
        return path.size() - 1;  // Number of edges = nodes - 1
    }
    
    // Print the graph structure
    void printGraph() {
        cout << "Social Network Graph:" << endl;
        for (const auto& pair : adjList) {
            cout << "  " << pair.first << " -- [";
            for (int i = 0; i < pair.second.size(); i++) {
                if (i > 0) cout << ", ";
                cout << pair.second[i];
            }
            cout << "]" << endl;
        }
    }
};

int main() {
    cout << "=== Six Degrees of Separation ===" << endl;
    
    SocialGraph network;
    
    // Build the network
    // Creating a network that looks like:
    //
    //    Alice -- Bob -- Charlie -- Diana
    //      |              |
    //    Eve ----------- Frank -- Grace
    //                      |
    //                    Henry
    
    network.addFriendship("Alice", "Bob");
    network.addFriendship("Alice", "Eve");
    network.addFriendship("Bob", "Charlie");
    network.addFriendship("Charlie", "Diana");
    network.addFriendship("Charlie", "Frank");
    network.addFriendship("Eve", "Frank");
    network.addFriendship("Frank", "Grace");
    network.addFriendship("Frank", "Henry");
    
    cout << "\n--- Network Structure ---" << endl;
    network.printGraph();
    
    // Test 1: Direct connection
    cout << "\n--- Test 1: Direct Connection ---" << endl;
    {
        vector<string> path = network.shortestPath("Alice", "Bob");
        cout << "Path from Alice to Bob: ";
        if (path.empty()) {
            cout << "No path found";
        } else {
            for (int i = 0; i < path.size(); i++) {
                if (i > 0) cout << " -> ";
                cout << path[i];
            }
            cout << " (distance: " << path.size() - 1 << ")";
        }
        cout << endl;
        cout << "Expected: Alice -> Bob (distance: 1)" << endl;
    }
    
    // Test 2: Path with multiple hops
    cout << "\n--- Test 2: Multiple Hops ---" << endl;
    {
        vector<string> path = network.shortestPath("Alice", "Diana");
        cout << "Path from Alice to Diana: ";
        if (path.empty()) {
            cout << "No path found";
        } else {
            for (int i = 0; i < path.size(); i++) {
                if (i > 0) cout << " -> ";
                cout << path[i];
            }
            cout << " (distance: " << path.size() - 1 << ")";
        }
        cout << endl;
        cout << "Expected: Alice -> Bob -> Charlie -> Diana (distance: 3)" << endl;
    }
    
    // Test 3: Shortest path when multiple paths exist
    cout << "\n--- Test 3: Multiple Paths ---" << endl;
    {
        vector<string> path = network.shortestPath("Alice", "Frank");
        cout << "Path from Alice to Frank: ";
        if (path.empty()) {
            cout << "No path found";
        } else {
            for (int i = 0; i < path.size(); i++) {
                if (i > 0) cout << " -> ";
                cout << path[i];
            }
            cout << " (distance: " << path.size() - 1 << ")";
        }
        cout << endl;
        cout << "Expected: Alice -> Eve -> Frank (distance: 2)" << endl;
        cout << "(Note: Alice -> Bob -> Charlie -> Frank would be distance 3)" << endl;
    }
    
    // Test 4: Same start and end
    cout << "\n--- Test 4: Same Start and End ---" << endl;
    {
        vector<string> path = network.shortestPath("Alice", "Alice");
        cout << "Path from Alice to Alice: ";
        if (path.empty()) {
            cout << "No path found";
        } else {
            for (int i = 0; i < path.size(); i++) {
                if (i > 0) cout << " -> ";
                cout << path[i];
            }
            cout << " (distance: " << path.size() - 1 << ")";
        }
        cout << endl;
        cout << "Expected: Alice (distance: 0)" << endl;
    }
    
    // Test 5: Non-existent user
    cout << "\n--- Test 5: Non-existent User ---" << endl;
    {
        vector<string> path = network.shortestPath("Alice", "Zoe");
        cout << "Path from Alice to Zoe: ";
        if (path.empty()) {
            cout << "No path found";
        } else {
            for (int i = 0; i < path.size(); i++) {
                if (i > 0) cout << " -> ";
                cout << path[i];
            }
        }
        cout << endl;
        cout << "Expected: No path found (Zoe doesn't exist)" << endl;
    }
    
    // Test 6: Disconnected components
    cout << "\n--- Test 6: Disconnected Components ---" << endl;
    {
        // Add a disconnected user
        network.addUser("Isolated");
        
        vector<string> path = network.shortestPath("Alice", "Isolated");
        cout << "Path from Alice to Isolated: ";
        if (path.empty()) {
            cout << "No path found";
        } else {
            for (int i = 0; i < path.size(); i++) {
                if (i > 0) cout << " -> ";
                cout << path[i];
            }
        }
        cout << endl;
        cout << "Expected: No path found (Isolated has no connections)" << endl;
    }
    
    // Test 7: Distance calculations
    cout << "\n--- Test 7: Distance Summary ---" << endl;
    vector<pair<string, string>> testPairs = {
        {"Alice", "Bob"},
        {"Alice", "Diana"},
        {"Alice", "Frank"},
        {"Alice", "Henry"},
        {"Bob", "Grace"},
        {"Eve", "Diana"}
    };
    
    for (const auto& p : testPairs) {
        int dist = network.getDistance(p.first, p.second);
        cout << "  Distance " << p.first << " to " << p.second << ": ";
        if (dist == -1) {
            cout << "No path";
        } else {
            cout << dist;
        }
        cout << endl;
    }
    
    return 0;
}

