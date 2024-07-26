class Solution {
public:
    int solve(vector<int>& nums, int i, int j,vector<vector<int>> &dp) {
        if (i > j) return 0; 
        int maxi = INT_MIN;
        if(dp[i][j]!=-1) return dp[i][j];
        for (int k = i; k <= j; k++) {
            int left = (i > 0) ? nums[i - 1] : 1; 
            int right = (j < nums.size() - 1) ? nums[j + 1] : 1; 
            int coins = left * nums[k] * right;
            coins += solve(nums, i, k - 1,dp);
            coins += solve(nums, k + 1, j,dp);
            maxi = max(maxi, coins);
        }
        return dp[i][j]=maxi;
    }

    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(nums, 0,n-1,dp);
    }
};
