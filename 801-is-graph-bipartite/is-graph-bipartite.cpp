class Solution {
public:
    bool dfs(vector<vector<int>>& graph, int node, vector<int>& vis, int col) {
        vis[node] = col;
        for (auto it : graph[node]) {
            if (vis[it] == col) {
                return false;
            }
            if (vis[it] == -1) {
                if (col == 0) {
                    if (!dfs(graph, it, vis, 1)) return false;
                } else {
                    if (!dfs(graph, it, vis, 0)) return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, -1);
        for (int i = 0; i < n; i++) {
            if (vis[i] == -1) {
                if (!dfs(graph, i, vis, 0)) return false;
            }
        }
        return true;
    }
};
