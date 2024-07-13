class Solution {
public:
    int solve(vector<int>& coins, int amount,int i ,vector<vector<int>>& dp){
        if(i==0){
            if(amount%coins[0]==0)
                return amount/coins[0];
            else
                return 1e7;
        }
        if(dp[i][amount]!=-1)
            return dp[i][amount];
        
        int dont = solve(coins,amount,i-1,dp);
        int take = INT_MAX;
        if(amount>=coins[i])
            take = 1 + solve(coins,amount-coins[i],i,dp);
        return dp[i][amount] = min(take,dont);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        if(amount==0){
            return 0;
        }
        int ans = solve(coins,amount,n-1,dp);
        if(ans!=1e7){
            return ans;
        }else
            return -1;
    }
};