class Solution {
public:
    int solve(vector<int>& prices,int i,bool buy,vector<vector<int>>& dp){
        if(i==prices.size()){
            return 0;
        }
        if (dp[i][buy] != -1) {
            return dp[i][buy];
        }
        if(!buy){
            return dp[i][buy] = max((-prices[i] + solve(prices,i+1,true,dp)),solve(prices,i+1,false,dp));
        }
        return dp[i][buy] = max((prices[i] + solve(prices,i+1,false,dp)),solve(prices,i+1,true,dp));
    }
    int maxProfit(vector<int>& prices) {
        bool buy = false;
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(prices,0,buy,dp);
    }
};