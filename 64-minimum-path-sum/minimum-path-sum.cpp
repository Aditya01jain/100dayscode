class Solution {
public:
    int solve(vector<vector<int>>& grid,int i,int j,vector<vector<int>>& dp){
        if(i<0 || j<0) return INT_MAX;
        if(i==0&&j==0) return grid[0][0];
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j] = grid[i][j] + min(solve(grid,i-1,j,dp),solve(grid,i,j-1,dp));
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));

        dp[1][1] = grid[0][0];
        for(int i=0;i<=n;i++){
            dp[i][0] = 1e5;
        }
        for(int i=0;i<=m;i++){
            dp[0][i] = 1e5;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(i==1&&j==1) continue;
                dp[i][j] = grid[i-1][j-1] + min(dp[i-1][j],dp[i][j-1]);
            }
            
        }
        
        return dp[n][m];
    }
};