class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));
        vector<int> dp(n + 1, 0);
        
        // Precompute palindrome substrings
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i; j < n; ++j) {
                if (s[i] == s[j] && (j - i < 2 || isPalindrome[i + 1][j - 1])) {
                    isPalindrome[i][j] = true;
                }
            }
        }
        
        // Calculate minimum cuts
        for (int i = n - 1; i >= 0; --i) {
            int mini = INT_MAX;
            for (int j = i; j < n; ++j) {
                if (isPalindrome[i][j]) {
                    mini = min(mini, 1 + dp[j + 1]);
                }
            }
            dp[i] = mini;
        }
        
        return dp[0] - 1;
    }
};
