class Solution {
public:
    int solve(vector<int>& nums, int prevIndex, int currentIndex, int n, vector<vector<int>>& dp) {
        if (currentIndex == n) return 0;
        if (dp[prevIndex + 1][currentIndex] != -1) return dp[prevIndex + 1][currentIndex];
        int take = 0;
        if (prevIndex == -1 || nums[currentIndex] > nums[prevIndex])
            take = 1 + solve(nums, currentIndex, currentIndex + 1, n, dp);
        int dontTake = solve(nums, prevIndex, currentIndex + 1, n, dp);
        dp[prevIndex + 1][currentIndex] = max(take, dontTake);
        return dp[prevIndex + 1][currentIndex];
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n, -1));
        return solve(nums, -1, 0, n, dp);
    }
};
