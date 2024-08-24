class Solution {
public:
    int solve(int left, int right, vector<int>& piles, vector<vector<int>>& dp, bool f) {
        if (left > right) return 0; // Base case

        if (dp[left][right] != -1) return dp[left][right]; // Memoization check

        if (f) { // First player's turn
            return dp[left][right] = max(piles[left] + solve(left + 1, right, piles, dp, !f), 
                                         piles[right] + solve(left, right - 1, piles, dp, !f));
        } else { // Second player's turn
            return dp[left][right] = min(solve(left + 1, right, piles, dp, !f), 
                                         solve(left, right - 1, piles, dp, !f));
        }
    }

    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, -1)); // DP table initialization
        return solve(0, n - 1, piles, dp, 1) > 0; // Call solve function starting with the first player's turn
    }
};