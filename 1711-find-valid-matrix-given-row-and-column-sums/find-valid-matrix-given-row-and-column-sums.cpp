class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n = rowSum.size(), m = colSum.size();
        vector<vector<int>> ans(n, vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int temp = min(rowSum[i], colSum[j]); //just takeout the min of that rowSum and ColSum
                ans[i][j] = temp; //ans will be that min
                rowSum[i] -= temp; //rowSum will be modified by subtracting that min
                colSum[j] -= temp; //colSum will be modified by subtracting that min
            }
        }

        return ans;
    }
};
