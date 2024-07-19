class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        vector<int> lucky;
        int n = matrix.size();
        int m = matrix[0].size();
        int x, y, col;
        for (int i = 0; i < n; i++) {
            x = INT_MAX;
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] < x) {
                    col = j;
                    x = matrix[i][j];
                }
            }
            y = INT_MIN;
            for (int j = 0; j < n; j++) y = max(y, matrix[j][col]);
            if(x == y) lucky.push_back(x);
        }
        return lucky;
    }
};