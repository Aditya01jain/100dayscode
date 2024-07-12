class Solution {
public:
int minFallingPathSum(vector<vector<int>>& matrix) {
    int n = matrix.size();
    vector<vector<int>> dp = matrix;  // Initialize the dp table with the matrix values

    // Fill the dp table from the second-to-last row to the top row
    for (int i = n - 2; i >= 0; --i) {
        for (int j = 0; j < n; ++j) {
            int min_below = dp[i + 1][j];  // Element directly below
            if (j > 0) {
                min_below = min(min_below, dp[i + 1][j - 1]);  // Element diagonally below left
            }
            if (j < n - 1) {
                min_below = min(min_below, dp[i + 1][j + 1]);  // Element diagonally below right
            }
            dp[i][j] += min_below;  // Add the minimum path sum from the next row
        }
    }

    // The answer is the minimum value in the first row of dp
    return *min_element(dp[0].begin(), dp[0].end());
}

};
