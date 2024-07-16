class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> ans(n, vector<int>(m, INT_MAX));
        queue<pair<int, pair<int, int>>> q;

        // Initialize the queue with all the cells that are 0
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    q.push({0, {i, j}});
                    ans[i][j] = 0;
                    vis[i][j] = 1;
                }
            }
        }

        // Directions for moving up, down, left, and right
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!q.empty()) {
            pair<int, pair<int, int>> node = q.front();
            q.pop();
            int dist = node.first;
            int x = node.second.first;
            int y = node.second.second;

            for (auto [dx, dy] : directions) {
                int newX = x + dx;
                int newY = y + dy;

                if (newX >= 0 && newX < n && newY >= 0 && newY < m && vis[newX][newY] == 0) {
                    ans[newX][newY] = dist + 1;
                    vis[newX][newY] = 1;
                    q.push({dist + 1, {newX, newY}});
                }
            }
        }

        return ans;
    }
};
