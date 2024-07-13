class Solution {
public:
    void dfs(vector<int> adj[],int node,unordered_map<int,bool>& vis){
        vis[node]=true;
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(adj,it,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int,bool> vis;
        int V = isConnected.size();
        vector<int> adj[V];
        for(int i=0;i<V;i++){
            for(int j =0;j<V;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adj[i].push_back(j); 
                    adj[j].push_back(i);
                }
            }
        }
        int c=0;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                c++;
                dfs(adj,i,vis);
            }
        }
        return c;
    }
};