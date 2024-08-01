class Solution {
public:
    int solve(vector<int>& prices,int i,int buy,vector<vector<int>> &dp){
        if(i==prices.size()) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        int profit = INT_MIN;
        if(buy==1){
            profit = max(-prices[i]+solve(prices,i+1,0,dp),solve(prices,i+1,1,dp));
        }else{
            profit = max(prices[i]+solve(prices,i+1,1,dp),solve(prices,i+1,0,dp));
        }
        return dp[i][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        int buy=1;
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                int profit = INT_MIN;
                if(buy==1){
                    profit = max(-prices[i]+dp[i+1][0],dp[i+1][1]);
                }else{
                    profit = max(prices[i]+dp[i+1][1],dp[i+1][0]);
                }
                dp[i][buy]=profit;
            }
        }
        return dp[0][1];
    }
};