class Solution {
public:
    int solve(vector<vector<int>>& g,int n,int m,vector<vector<int>> &dp){
        if(n<0 || m<0){
            return INT_MAX;
        }
        if(n==0&&m==0){
            return g[0][0];
        }
        if(dp[n][m]!=-1){
            return dp[n][m];
        }
        dp[n][m] = g[n][m] + min(solve(g,n-1,m,dp),solve(g,n,m-1,dp));
        return dp[n][m];
    }
    int minPathSum(vector<vector<int>>& g) {
        int n = g.size();
        int m = g[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(g,n-1,m-1,dp);
    }
};