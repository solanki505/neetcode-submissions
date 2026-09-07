class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<int, int>> q;
        int fresh_count = 0;
        
        // Step 1: Find all initial rotten oranges and count fresh ones
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    fresh_count++;
                }
            }
        }
        
        // If there are no fresh oranges to begin with, it takes 0 minutes
        if (fresh_count == 0) return 0;
        
        int minutes = 0;
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        // Step 2: Multi-source BFS
        while (!q.empty()) {
            int level_size = q.size();
            bool rotted_this_minute = false;
            
            for (int i = 0; i < level_size; i++) {
                auto [r, c] = q.front();
                q.pop();
                
                for (auto dir : directions) {
                    int nr = r + dir.first;
                    int nc = c + dir.second;
                    
                    // If the adjacent cell is within bounds and has a fresh orange
                    if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1) {
                        grid[nr][nc] = 2; // Rot it
                        fresh_count--;
                        q.push({nr, nc});
                        rotted_this_minute = true;
                    }
                }
            }
            if (rotted_this_minute) {
                minutes++;
            }
        }
        
        // Step 3: Check if any fresh oranges survived
        return fresh_count == 0 ? minutes : -1;
    }
};
