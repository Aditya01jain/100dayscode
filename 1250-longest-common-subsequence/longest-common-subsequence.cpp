class Solution {
public:
    int solve(string text1, string text2,int first,int second,vector<vector<int>>& dp){
        if(first<0 || second<0){
            return 0;
        }
        if(dp[first][second]!=-1){
            return dp[first][second];
        }
        if(text1[first]==text2[second])
            return dp[first][second]= 1+solve(text1,text2,first-1,second-1,dp);
            
        
        return dp[first][second]= max(solve(text1,text2,first-1,second,dp),solve(text1,text2,first,second-1,dp));
        
    }
    int lcs(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1)); // Create a DP table

    // Initialize the base cases
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }
    for (int i = 0; i <= m; i++) {
        dp[0][i] = 0;
    }

    // Fill in the DP table to calculate the length of LCS
    for (int ind1 = 1; ind1 <= n; ind1++) {
        for (int ind2 = 1; ind2 <= m; ind2++) {
            if (s1[ind1 - 1] == s2[ind2 - 1])
                dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1]; // Characters match, increment LCS length
            else
                dp[ind1][ind2] = max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]); // Characters don't match, consider the maximum from left or above
        }
    }

    return dp[n][m]; // Return the length of the Longest Common Subsequence
}
    int longestCommonSubsequence(string text1, string text2) {
        int first = text1.length()-1;
        int second = text2.length()-1;
        vector<vector<int>> dp(first+1, vector<int>(second+1, -1)); 
        return lcs (text1,text2);
    }
};