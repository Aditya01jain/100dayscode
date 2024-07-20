class Solution {
public:
    void buildAdjList(vector<vector<int>>& prerequisites, unordered_map<int, set<int>>& adj) { 
        for (auto& pair : prerequisites) {
            int u = pair[0];
            int v = pair[1];
            adj[v].insert(u); 
        }
    }

    bool hasCycle(int node, unordered_map<int, set<int>>& adj, unordered_map<int, bool>& vis, unordered_map<int, bool>& recStack) {
        vis[node] = true;
        recStack[node] = true;
        for (auto neighbor : adj[node]) {
            if (!vis[neighbor] && hasCycle(neighbor, adj, vis, recStack)) {
                return true;
            } else if (recStack[neighbor]) {
                return true;
            }
        }
        recStack[node] = false;
        return false;
    }

    void topologicalSort(int node, unordered_map<int, set<int>>& adj, unordered_map<int, bool>& vis, vector<int>& result) {
        vis[node] = true;
        for (auto neighbor : adj[node]) {
            if (!vis[neighbor]) {
                topologicalSort(neighbor, adj, vis, result);
            }
        }
        result.push_back(node);
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, set<int>> adj;
        buildAdjList(prerequisites, adj);

        vector<int> result;
        unordered_map<int, bool> vis, recStack;
        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                if (hasCycle(i, adj, vis, recStack)) {
                    return {};  
                }
            }
        }
        vis.clear();
        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                topologicalSort(i, adj, vis, result);
            }
        }
        reverse(result.begin(), result.end()); 
        return result;
    }
};
