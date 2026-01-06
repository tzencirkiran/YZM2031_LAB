/**
 * Problem 3: The Island Counter
 * 
 * Implement DFS to count the number of islands in a 2D grid.
 * - 1 represents land
 * - 0 represents water
 * - An island is a group of connected 1s (horizontally or vertically)
 */

#include <iostream>
#include <vector>

using namespace std;

class IslandCounter {
private:
    // Direction vectors for 4-directional movement (up, down, left, right)
    const int dx[4] = {-1, 1, 0, 0};
    const int dy[4] = {0, 0, -1, 1};
    
    // Helper function to check if a cell is valid and is land
    bool isValid(int x, int y, int rows, int cols, 
                 const vector<vector<int>>& grid, 
                 vector<vector<bool>>& visited) {
        return x >= 0 && x < rows && y >= 0 && y < cols && 
               grid[x][y] == 1 && !visited[x][y];
    }
    
    // DFS to mark all cells of an island as visited
    // Starting from cell (x, y), visit all connected land cells
    void dfs(int x, int y, int rows, int cols,
             const vector<vector<int>>& grid,
             vector<vector<bool>>& visited) {
        // TODO: Implement DFS
    }

public:
    // Count the number of islands in the grid
    int countIslands(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        
        int islandCount = 0;
        
        // TODO: Implement island counting
        
        return islandCount;  // placeholder
    }
    
    // Count islands and label each island with a unique ID
    // Returns the labeled grid where each island has a unique number
    vector<vector<int>> labelIslands(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return {};
        }
        
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> labeled(rows, vector<int>(cols, 0));
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        
        int islandId = 0;
        
        // TODO: Implement island labeling
        
        return labeled;  // placeholder
    }
    
    // Helper to print a grid
    void printGrid(const vector<vector<int>>& grid, const string& title) {
        cout << title << ":" << endl;
        for (const auto& row : grid) {
            cout << "  ";
            for (int cell : row) {
                cout << cell << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    cout << "=== Island Counter ===" << endl;
    
    IslandCounter counter;
    
    // Test 1: Simple case with 3 islands
    cout << "\n--- Test 1: Three Islands ---" << endl;
    {
        vector<vector<int>> grid = {
            {1, 1, 0, 0, 0},
            {1, 1, 0, 0, 0},
            {0, 0, 1, 0, 0},
            {0, 0, 0, 1, 1}
        };
        
        counter.printGrid(grid, "Input Grid");
        
        int islands = counter.countIslands(grid);
        cout << "Number of islands: " << islands << endl;
        cout << "Expected: 3" << endl;
    }
    
    // Test 2: One large island
    cout << "\n--- Test 2: One Large Island ---" << endl;
    {
        vector<vector<int>> grid = {
            {1, 1, 1, 1, 1},
            {1, 0, 0, 0, 1},
            {1, 0, 0, 0, 1},
            {1, 1, 1, 1, 1}
        };
        
        counter.printGrid(grid, "Input Grid");
        
        int islands = counter.countIslands(grid);
        cout << "Number of islands: " << islands << endl;
        cout << "Expected: 1 (the ring is one connected island)" << endl;
    }
    
    // Test 3: No islands (all water)
    cout << "\n--- Test 3: No Islands ---" << endl;
    {
        vector<vector<int>> grid = {
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0}
        };
        
        counter.printGrid(grid, "Input Grid");
        
        int islands = counter.countIslands(grid);
        cout << "Number of islands: " << islands << endl;
        cout << "Expected: 0" << endl;
    }
    
    // Test 4: All land (one big island)
    cout << "\n--- Test 4: All Land ---" << endl;
    {
        vector<vector<int>> grid = {
            {1, 1, 1},
            {1, 1, 1},
            {1, 1, 1}
        };
        
        counter.printGrid(grid, "Input Grid");
        
        int islands = counter.countIslands(grid);
        cout << "Number of islands: " << islands << endl;
        cout << "Expected: 1" << endl;
    }
    
    // Test 5: Diagonal neighbors (should NOT connect)
    cout << "\n--- Test 5: Diagonal Neighbors ---" << endl;
    {
        vector<vector<int>> grid = {
            {1, 0, 1},
            {0, 1, 0},
            {1, 0, 1}
        };
        
        counter.printGrid(grid, "Input Grid");
        
        int islands = counter.countIslands(grid);
        cout << "Number of islands: " << islands << endl;
        cout << "Expected: 5 (diagonals don't connect)" << endl;
    }
    
    // Test 6: Complex shape
    cout << "\n--- Test 6: Complex Shape ---" << endl;
    {
        vector<vector<int>> grid = {
            {1, 1, 0, 0, 1, 1, 0},
            {1, 0, 0, 0, 0, 1, 0},
            {0, 0, 1, 1, 0, 0, 0},
            {0, 0, 1, 1, 0, 1, 1},
            {0, 0, 0, 0, 0, 1, 1},
            {1, 1, 0, 0, 0, 0, 0}
        };
        
        counter.printGrid(grid, "Input Grid");
        
        int islands = counter.countIslands(grid);
        cout << "Number of islands: " << islands << endl;
        cout << "Expected: 4" << endl;
    }
    
    // Test 7: Island labeling
    cout << "\n--- Test 7: Island Labeling ---" << endl;
    {
        vector<vector<int>> grid = {
            {1, 1, 0, 0, 0},
            {1, 1, 0, 0, 0},
            {0, 0, 1, 0, 0},
            {0, 0, 0, 1, 1}
        };
        
        counter.printGrid(grid, "Input Grid");
        
        vector<vector<int>> labeled = counter.labelIslands(grid);
        if (!labeled.empty()) {
            counter.printGrid(labeled, "Labeled Islands");
            cout << "Each number represents a different island." << endl;
        } else {
            cout << "(labelIslands not implemented yet)" << endl;
        }
    }
    
    // Test 8: Empty grid
    cout << "\n--- Test 8: Empty Grid ---" << endl;
    {
        vector<vector<int>> grid = {};
        
        int islands = counter.countIslands(grid);
        cout << "Number of islands in empty grid: " << islands << endl;
        cout << "Expected: 0" << endl;
    }
    
    return 0;
}

