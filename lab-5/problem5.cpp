#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <numeric>

using namespace std;

// Disjoint Set implementation
class DisjointSet {
private:
    vector<int> parent;
    vector<int> rank;

public:
    DisjointSet(int n) : parent(n), rank(n, 0) {
        // TODO: Initialize parent and rank arrays
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        // TODO: Implement find with path compression
        if (x != parent[x])
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        // TODO: Implement union by rank
        int root_x = find(x);
        int root_y = find(y);

        if (root_x == root_y) return; // do nothing
        
        // assign lower ranked root's parent to the higher ranked one's
        if (rank[root_x] < rank[root_y]) {
            parent[root_x] = root_y;
        }
        else if (rank[root_x] > rank[root_y]) {
            parent[root_y] = root_x;
        }
        else {
            parent[root_y] = root_x;
            rank[root_x] += 1; 
        }
    }

    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};

struct Wall {
    int cell1; // keeps column idx I guess
    int cell2;
    // For visualization logic (optional, but good for understanding)
    // 0: vertical wall between (r, c) and (r, c+1)
    // 1: horizontal wall between (r, c) and (r+1, c)
};

class MazeGenerator {
private:
    int width;
    int height;
    DisjointSet ds;
    vector<Wall> walls;
    
    // Grid representation for visualization
    // cells[r][c] stores bitmask of open directions: 1=Right, 2=Down, 4=Left, 8=Up
    vector<vector<int>> grid; 

public:
    MazeGenerator(int w, int h) : width(w), height(h), ds(w * h), grid(h, vector<int>(w, 0)) {
        // Initialize all possible walls
        // Cell index = row * width + col
        for (int r = 0; r < height; r++) { 
            for (int c = 0; c < width; c++) { // for each row's each column
                int current = r * width + c;
                
                // Add vertical wall to the right (if not last column) (|)
                if (c < width - 1) {
                    int right = r * width + (c + 1);
                    walls.push_back({current, right});
                }
                
                // Add horizontal wall below (if not last row) 
                if (r < height - 1) {
                    int down = (r + 1) * width + c;
                    walls.push_back({current, down});
                }
            }
        }
    }

    void generate() {
        // TODO: Implement Randomized Kruskal's Algorithm
        random_device rd;
        mt19937 rng(rd());
        shuffle(walls.begin(), walls.end(), rng);
        int united_walls = 0;

        // Iterate walls and remove (unite) those that join different sets
        for (const auto& w : walls) {
            if (!ds.connected(w.cell1, w.cell2)) {
                ds.unite(w.cell1, w.cell2);
                united_walls++;
            }
            if (united_walls == walls.size() - 1) break;
        }
    }

    void printMaze() {
        // Top border
        for (int c = 0; c < width; c++) cout << "+---";
        cout << "+" << endl;

        for (int r = 0; r < height; r++) {
            // Left border of the row
            cout << "|";
            for (int c = 0; c < width; c++) {
                // If there is a connection to the right (bit 1 is set), print "   ", else "   |"
                // We need to check our grid or check connectivity
                // For simplicity in this template, let's assume 'grid' is updated correctly
                
                // Print cell space
                cout << "   ";
                
                // Check right wall
                int current = r * width + c;
                int right = r * width + (c + 1);
                
                if (c < width - 1 && ds.connected(current, right)) {
                    cout << " "; // No wall
                } else {
                    cout << "|"; // Wall
                }
            }
            cout << endl;

            // Bottom border of the row
            cout << "+";
            for (int c = 0; c < width; c++) {
                int current = r * width + c;
                int down = (r + 1) * width + c;
                
                if (r < height - 1 && ds.connected(current, down)) {
                    cout << "   +"; // No wall
                } else {
                    cout << "---+"; // Wall
                }
            }
            cout << endl;
        }
    }
};

int main() {
    int width = 10;
    int height = 10;

    cout << "Generating " << width << "x" << height << " maze..." << endl;
    
    MazeGenerator maze(width, height);
    maze.generate();
    maze.printMaze();

    return 0;
}
