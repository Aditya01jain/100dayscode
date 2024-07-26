class Solution {
public:
    int solve(vector<int>& cuts ,int i,int j,vector<vector<int>>& dp){
        if(i>j) return 0;
        int mini = 1e9;
        if(dp[i][j]!=-1) return dp[i][j];
        for(int k=i;k<=j;k++){
            int res = (cuts[j+1] - cuts[i-1]) + solve(cuts,i,k-1,dp) + solve(cuts,k+1,j,dp); 
            mini = min(res,mini);
        }
        return dp[i][j]=mini;

    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        int s = cuts.size();
        vector<vector<int>> dp(s,vector<int>(s,0));
        for(int i = s-1;i>0;i--){
            for(int j = i;j<(s-1);j++){
                int mini = 1e9;
                for(int k=i;k<=j;k++){
                    int res = (cuts[j+1] - cuts[i-1]) + dp[i][k-1] + dp[k+1][j]; 
                    mini = min(res,mini);
                }
                dp[i][j]=mini;
            }
        }
        return dp[1][s-2];
    }
};