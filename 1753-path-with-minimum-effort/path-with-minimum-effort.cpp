class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& h) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> q;
        q.push({0, {0, 0}});
        int n = h.size();
        int m = h[0].size();
        
        // Initialize the effort grid with INT_MAX
        vector<vector<int>> eff(n, vector<int>(m, INT_MAX));
        eff[0][0] = 0;
        
        vector<pair<int,int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        while (!q.empty()) {
            int diff = q.top().first;
            int x = q.top().second.first;
            int y = q.top().second.second;
            q.pop();
            
            // If we have reached the bottom-right corner, return the effort
            if (x == n-1 && y == m-1) return diff;
            
            for (auto i : dir) {
                int nx = x + i.first;
                int ny = y + i.second;
                
                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    int newdiff = max(abs(h[x][y] - h[nx][ny]), diff);
                    
                    // Update the effort if we found a smaller effort path
                    if (newdiff < eff[nx][ny]) {
                        eff[nx][ny] = newdiff;
                        q.push({newdiff, {nx, ny}});
                    }
                }
            }
        }
        
        return 0;
    }
};
