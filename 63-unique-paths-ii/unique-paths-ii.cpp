class Solution {
public:
    int solve(int n,int m, vector<vector<int>>& o,vector<vector<int>>& dp){
        if(n<0 || m<0 || o[n][m]==1){
            return 0;
        }
        if(n==0 && m==0){
            return 1;
        }
        if(dp[n][m]!=-1){
            return dp[n][m];
        }
        dp[n][m] = solve(n-1,m,o,dp) + solve(n,m-1,o,dp);
        return dp[n][m];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& o) {
        int n = o.size();
        int m = o[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(n-1,m-1,o,dp);
    }
};