class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> ans = image;
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int val = image[sr][sc];
        
        // If the new color is the same as the original color, no need to do anything
        if (val == color) return ans;

        queue<pair<int, int>> q;
        q.push({sr, sc});
        ans[sr][sc] = color;

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (auto& dir : directions) {
                int newX = x + dir.first;
                int newY = y + dir.second;

                if (newX >= 0 && newX < n && newY >= 0 && newY < m && image[newX][newY] == val) {
                    ans[newX][newY] = color;
                    q.push({newX, newY});
                    image[newX][newY] = color; // Mark it in the original image to avoid revisiting
                }
            }
        }
        return ans;
    }
};
