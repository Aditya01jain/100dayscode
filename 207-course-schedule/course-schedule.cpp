class Solution {
public:
    void list(vector<vector<int>>& p,unordered_map<int,set<int>> &adj){
        for(auto i:p){
            int u = i[0];
            int v = i[1];
            adj[u].insert(v);
        }
    }
    bool dfs(int node ,int parent, unordered_map<int,set<int>> &adj, unordered_map<int,bool>& vis,unordered_map<int,bool>& call){
        vis[node] = true;
        call[node] = true;
        for(auto i:adj[node]){
            if(vis[i]&&call[i]&& node!=parent) return true;
            if(!vis[i]){
                if(dfs(i,node,adj,vis,call)) return true;
            }
        }
        call[node] = false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,set<int>> adj;
        list(prerequisites,adj);
        unordered_map<int,bool> vis;
        unordered_map<int,bool> call;
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(dfs(i,-1,adj,vis,call)) return false;
            }
        }
        return true;
    }
};