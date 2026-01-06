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
#include <stack>

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

    pair<int, int> valid_pos(int x, int y, int rows, int cols, 
                const vector<vector<int>>& grid, 
                vector<vector<bool>>& visited) {
        
        if (isValid(x, y, rows, cols, grid, visited)) {
            return {x, y};
        }
        else return {-1, -1};
    }
    
    // DFS to mark all cells of an island as visited
    // Starting from cell (x, y), visit all connected land cells
    void dfs(int x, int y, int rows, int cols,
             const vector<vector<int>>& grid,
             vector<vector<bool>>& visited) {
        // TODO: Implement DFS
        const int n_dir[4] = {0, 1, 2, 3};
        stack<pair<int, int>> s;
        pair<int, int> start_pos = {x, y};
        s.push(start_pos);
        
        while (!s.empty()) {
            pair<int, int> current_pos = s.top(); s.pop();
            int n_x, n_y;

            if (visited[current_pos.first][current_pos.second] == false) {
                visited[current_pos.first][current_pos.second] = true;
                for (int d = 0; d <=3; d++) {   // push all unvisited neighbours
                    n_x = current_pos.first + dx[n_dir[d]];
                    n_y = current_pos.second + dy[n_dir[d]];
                    if (isValid(n_x, n_y, rows, cols, grid, visited)) {
                        s.push({n_x,n_y});
                    }
                }
            }
        }

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
        int visit_count = 0;
        const int box_count = rows * cols;
        
        // TODO: Implement island counting
        pair<int, int> pos = {0,0};
        dfs(pos.first, pos.second, rows, cols, grid, visited);
        int x = pos.first; int y = pos.second; // y holds where land starts current_y where land is the seen for each row.
        while (visit_count < box_count) {
            int current_y = y;
            int current_x = x;
            int leftmost = current_x; // leftmost land's y (ie column idx) for the next row (for now ignore)
            while (visited[current_x][current_y] != false) {
                current_y++;
                visit_count++;
                if (visited[current_x][current_y] == false) {   // move next row (x++)
                    current_x++;
                }
            }
            islandCount++;
        }
        
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

