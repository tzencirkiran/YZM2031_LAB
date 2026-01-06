/**
 * Problem 5: The Navigation System
 * 
 * Implement Dijkstra's Algorithm to find shortest paths in a weighted graph.
 * - Find shortest distances from a source to all other vertices
 * - Reconstruct the actual path to any destination
 * - Handle disconnected vertices
 */

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>
#include <climits>

using namespace std;

class NavigationSystem {
private:
    int numCities;
    // Adjacency list: city -> list of (neighbor, distance)
    vector<vector<pair<int, int>>> adjList;

public:
    NavigationSystem(int n) : numCities(n), adjList(n) {}
    
    // Add a road between two cities with given distance
    // Roads are bidirectional (undirected graph)
    void addRoad(int city1, int city2, int distance) {
        adjList[city1].push_back({city2, distance});
        adjList[city2].push_back({city1, distance});
    }
    
    // Add a one-way road from city1 to city2
    void addOneWayRoad(int city1, int city2, int distance) {
        adjList[city1].push_back({city2, distance});
    }
    
    // Dijkstra's Algorithm
    // Returns a vector of shortest distances from source to all cities
    // distance[i] = shortest distance from source to city i
    // distance[i] = INT_MAX if city i is unreachable
    vector<int> shortestDistances(int source) {
        vector<int> dist(numCities, INT_MAX);
        
        // TODO: Implement Dijkstra's Algorithm
        
        return dist;  // placeholder
    }
    
    // Find shortest path from source to destination
    // Returns the path as a vector of city IDs
    // Returns empty vector if no path exists
    vector<int> shortestPath(int source, int destination) {
        if (source == destination) {
            return {source};
        }
        
        vector<int> dist(numCities, INT_MAX);
        vector<int> parent(numCities, -1);
        
        // TODO: Implement Dijkstra's with path reconstruction
        
        return {};  // placeholder
    }
    
    // Get shortest distance between two cities
    // Returns -1 if no path exists
    int getDistance(int source, int destination) {
        vector<int> distances = shortestDistances(source);
        if (distances[destination] == INT_MAX) {
            return -1;
        }
        return distances[destination];
    }
    
    // Print the graph structure
    void printGraph() {
        cout << "Road Network:" << endl;
        for (int i = 0; i < numCities; i++) {
            cout << "  City " << i << ": ";
            if (adjList[i].empty()) {
                cout << "(no roads)";
            } else {
                for (int j = 0; j < adjList[i].size(); j++) {
                    if (j > 0) cout << ", ";
                    cout << "-> " << adjList[i][j].first 
                         << " (dist: " << adjList[i][j].second << ")";
                }
            }
            cout << endl;
        }
    }
};

// Helper class for cities with names
class NamedNavigationSystem {
private:
    unordered_map<string, int> cityToId;
    vector<string> idToCity;
    NavigationSystem* nav;

public:
    NamedNavigationSystem() : nav(nullptr) {}
    
    ~NamedNavigationSystem() {
        delete nav;
    }
    
    void addCity(const string& name) {
        if (cityToId.find(name) == cityToId.end()) {
            cityToId[name] = idToCity.size();
            idToCity.push_back(name);
        }
    }
    
    void build() {
        nav = new NavigationSystem(idToCity.size());
    }
    
    void addRoad(const string& city1, const string& city2, int distance) {
        if (nav && cityToId.count(city1) && cityToId.count(city2)) {
            nav->addRoad(cityToId[city1], cityToId[city2], distance);
        }
    }
    
    int getDistance(const string& from, const string& to) {
        if (!nav) return -1;
        return nav->getDistance(cityToId[from], cityToId[to]);
    }
    
    vector<string> getPath(const string& from, const string& to) {
        if (!nav) return {};
        
        vector<int> path = nav->shortestPath(cityToId[from], cityToId[to]);
        vector<string> result;
        for (int id : path) {
            result.push_back(idToCity[id]);
        }
        return result;
    }
};

int main() {
    cout << "=== Navigation System ===" << endl;
    
    // Test 1: Simple graph
    cout << "\n--- Test 1: Simple Graph ---" << endl;
    {
        //     1
        // 0 ----- 1
        // |       |
        // 4       2
        // |       |
        // 2 ----- 3
        //     3
        
        NavigationSystem nav(4);
        nav.addRoad(0, 1, 1);
        nav.addRoad(0, 2, 4);
        nav.addRoad(1, 3, 2);
        nav.addRoad(2, 3, 3);
        
        nav.printGraph();
        
        vector<int> distances = nav.shortestDistances(0);
        cout << "\nShortest distances from city 0:" << endl;
        for (int i = 0; i < 4; i++) {
            cout << "  City " << i << ": ";
            if (distances[i] == INT_MAX) {
                cout << "unreachable";
            } else {
                cout << distances[i];
            }
            cout << endl;
        }
        cout << "Expected: City 0: 0, City 1: 1, City 2: 4, City 3: 3" << endl;
    }
    
    // Test 2: Path reconstruction
    cout << "\n--- Test 2: Path Reconstruction ---" << endl;
    {
        //       5
        //   0 ----- 1
        //   |\      |
        // 2 | \ 3   | 1
        //   |  \    |
        //   2   \-- 3
        //   |       |
        // 7 |       | 2
        //   |       |
        //   4 ----- 5
        //       4
        
        NavigationSystem nav(6);
        nav.addRoad(0, 1, 5);
        nav.addRoad(0, 2, 2);
        nav.addRoad(0, 3, 3);
        nav.addRoad(1, 3, 1);
        nav.addRoad(2, 4, 7);
        nav.addRoad(3, 5, 2);
        nav.addRoad(4, 5, 4);
        
        cout << "Finding shortest path from 0 to 5:" << endl;
        vector<int> path = nav.shortestPath(0, 5);
        
        if (path.empty()) {
            cout << "  No path found" << endl;
        } else {
            cout << "  Path: ";
            for (int i = 0; i < path.size(); i++) {
                if (i > 0) cout << " -> ";
                cout << path[i];
            }
            cout << " (distance: " << nav.getDistance(0, 5) << ")" << endl;
        }
        cout << "Expected: 0 -> 3 -> 5 (distance: 5)" << endl;
    }
    
    // Test 3: Disconnected graph
    cout << "\n--- Test 3: Disconnected Cities ---" << endl;
    {
        NavigationSystem nav(5);
        nav.addRoad(0, 1, 1);
        nav.addRoad(1, 2, 2);
        nav.addRoad(3, 4, 1);  // Separate component
        
        cout << "Path from 0 to 2:" << endl;
        vector<int> path1 = nav.shortestPath(0, 2);
        if (path1.empty()) {
            cout << "  No path found" << endl;
        } else {
            cout << "  Path: ";
            for (int i = 0; i < path1.size(); i++) {
                if (i > 0) cout << " -> ";
                cout << path1[i];
            }
            cout << endl;
        }
        
        cout << "\nPath from 0 to 4:" << endl;
        vector<int> path2 = nav.shortestPath(0, 4);
        if (path2.empty()) {
            cout << "  No path found (expected - cities are disconnected)" << endl;
        } else {
            cout << "  Path found unexpectedly!" << endl;
        }
    }
    
    // Test 4: Same source and destination
    cout << "\n--- Test 4: Same Source and Destination ---" << endl;
    {
        NavigationSystem nav(3);
        nav.addRoad(0, 1, 1);
        nav.addRoad(1, 2, 1);
        
        vector<int> path = nav.shortestPath(1, 1);
        cout << "Path from 1 to 1: ";
        if (path.empty()) {
            cout << "No path";
        } else {
            for (int i = 0; i < path.size(); i++) {
                if (i > 0) cout << " -> ";
                cout << path[i];
            }
        }
        cout << endl;
        cout << "Expected: 1 (just the source)" << endl;
    }
    
    // Test 5: Named cities
    cout << "\n--- Test 5: Named Cities ---" << endl;
    {
        NamedNavigationSystem nav;
        
        nav.addCity("Istanbul");
        nav.addCity("Ankara");
        nav.addCity("Izmir");
        nav.addCity("Bursa");
        nav.addCity("Antalya");
        
        nav.build();
        
        nav.addRoad("Istanbul", "Ankara", 450);
        nav.addRoad("Istanbul", "Bursa", 150);
        nav.addRoad("Istanbul", "Izmir", 480);
        nav.addRoad("Ankara", "Antalya", 480);
        nav.addRoad("Izmir", "Antalya", 350);
        nav.addRoad("Bursa", "Izmir", 330);
        
        cout << "Shortest distance Istanbul -> Antalya: " 
             << nav.getDistance("Istanbul", "Antalya") << " km" << endl;
        cout << "Expected: 830 km (Istanbul -> Bursa -> Izmir -> Antalya)" << endl;
        
        vector<string> path = nav.getPath("Istanbul", "Antalya");
        if (!path.empty()) {
            cout << "Route: ";
            for (int i = 0; i < path.size(); i++) {
                if (i > 0) cout << " -> ";
                cout << path[i];
            }
            cout << endl;
        }
    }
    
    // Test 6: Multiple shortest paths
    cout << "\n--- Test 6: Equal Distance Paths ---" << endl;
    {
        //     2       2
        // 0 ----- 1 ----- 3
        //  \             /
        //   \--- 2 ----/
        //     2     2
        
        NavigationSystem nav(4);
        nav.addRoad(0, 1, 2);
        nav.addRoad(1, 3, 2);
        nav.addRoad(0, 2, 2);
        nav.addRoad(2, 3, 2);
        
        cout << "Distance from 0 to 3: " << nav.getDistance(0, 3) << endl;
        cout << "Expected: 4 (multiple paths with same distance)" << endl;
        
        vector<int> path = nav.shortestPath(0, 3);
        if (!path.empty()) {
            cout << "One valid path: ";
            for (int i = 0; i < path.size(); i++) {
                if (i > 0) cout << " -> ";
                cout << path[i];
            }
            cout << endl;
        }
    }
    
    // Test 7: All distances from source
    cout << "\n--- Test 7: All Distances from Source ---" << endl;
    {
        NavigationSystem nav(5);
        nav.addRoad(0, 1, 10);
        nav.addRoad(0, 2, 3);
        nav.addRoad(1, 2, 1);
        nav.addRoad(1, 3, 2);
        nav.addRoad(2, 1, 4);
        nav.addRoad(2, 3, 8);
        nav.addRoad(2, 4, 2);
        nav.addRoad(3, 4, 7);
        
        nav.printGraph();
        
        vector<int> distances = nav.shortestDistances(0);
        cout << "\nAll shortest distances from city 0:" << endl;
        for (int i = 0; i < 5; i++) {
            cout << "  To city " << i << ": ";
            if (distances[i] == INT_MAX) {
                cout << "unreachable";
            } else {
                cout << distances[i];
            }
            cout << endl;
        }
    }
    
    return 0;
}

