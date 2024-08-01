class Solution {
public:
    int solve(vector<int>& pri,int i,int buy,int fee,vector<vector<int>> &dp){
        if(i>=pri.size()) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        int p=0;
        if(buy==1){
            p = max(-pri[i]+solve(pri,i+1,0,fee,dp),solve(pri,i+1,1,fee,dp));
        }else{
            p = max(pri[i] - fee + solve(pri,i+1,1,fee,dp),solve(pri,i+1,0,fee,dp));
        }
        return dp[i][buy]=p;
    }
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return solve(prices,0,1,fee,dp);
    }
};