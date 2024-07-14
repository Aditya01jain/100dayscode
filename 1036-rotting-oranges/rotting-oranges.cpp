class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size(); // Number of columns
        queue<pair<int, int>> q;
        int freshOranges = 0;

        // Add all initially rotten oranges to the queue
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push(make_pair(i, j));
                } else if (grid[i][j] == 1) {
                    freshOranges++;
                }
            }
        }

        if (freshOranges == 0) return 0; // No fresh oranges to rot

        int minutes = 0;
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        // Perform BFS
        while (!q.empty()) {
            int size = q.size();
            bool anyRottingHappened = false;

            for (int i = 0; i < size; i++) {
                pair<int, int> temp = q.front();
                q.pop();

                for (auto& dir : directions) {
                    int newX = temp.first + dir.first;
                    int newY = temp.second + dir.second;

                    if (newX >= 0 && newX < n && newY >= 0 && newY < m && grid[newX][newY] == 1) {
                        grid[newX][newY] = 2;
                        q.push(make_pair(newX, newY));
                        freshOranges--;
                        anyRottingHappened = true;
                    }
                }
            }

            if (anyRottingHappened) {
                minutes++;
            }
        }

        // If there are still fresh oranges left, return -1 indicating not all oranges can be rotten
        return freshOranges == 0 ? minutes : -1;
    }
};