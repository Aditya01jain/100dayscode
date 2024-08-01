class Solution {
public:
    int solve(vector<int>& pri,int i,int buy,int t,vector<vector<vector<int>>> &dp){
        if(i==pri.size() || t>=2) return 0;
        if(dp[i][buy][t]!=-1) return dp[i][buy][t];
        int profit = 0;
        if(buy==1){
            profit = max(-pri[i]+solve(pri,i+1,0,t,dp),solve(pri,i+1,1,t,dp));
        }else{
            profit = max(pri[i]+solve(pri,i+1,1,t+1,dp),solve(pri,i+1,0,t,dp));
        }
        return dp[i][buy][t]=profit;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>>(2,vector<int>(3,-1)));
        return solve(prices,0,1,0,dp);
    }
};