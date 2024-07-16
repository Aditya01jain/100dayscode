class Solution {
public:
    void dfs(int x,int y,vector<vector<int>>& grid,vector<vector<int>>& vis,vector<pair<int,int>> dir){
        vis[x][y]=1;
        int n = grid.size();
        int m = grid[0].size();
        for(auto& i:dir){
            int nx = x + i.first;
            int ny = y + i.second;
            if(nx>=0 && nx<n && ny>=0 && ny<m && vis[nx][ny]==0 && grid[nx][ny]==1){
                dfs(nx,ny,grid,vis,dir);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<pair<int,int>> dir ={{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for(int i=0;i<n;i++){
            if(grid[i][0]==1 && vis[i][0]==0){
                dfs(i,0,grid,vis,dir);
            }
            if(grid[i][m-1]==1 && vis[i][m-1]==0){
                dfs(i,m-1,grid,vis,dir);
            }
        }
        for(int j=0;j<m;j++){
            if(grid[0][j]==1 && vis[0][j]==0){
                dfs(0,j,grid,vis,dir);
            }
            if(grid[n-1][j]==1 && vis[n-1][j]==0){
                dfs(n-1,j,grid,vis,dir);
            }
        }
        int c=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 && grid[i][j]==1){
                    c++;
                }
            }
        }
        return c;
    }
};