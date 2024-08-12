class Solution {
public:
    void solve(vector<int>& can, vector<vector<int>>& ans, vector<int>& out, int start, int target) {
        if (target == 0) {
            ans.push_back(out);
            return;
        }
        
        for (int i = start; i < can.size(); i++) {
            if (i > start && can[i] == can[i-1]) continue;
            if (can[i] > target) break;
            
            out.push_back(can[i]);
            solve(can, ans, out, i + 1, target - can[i]);
            out.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& can, int target) {
        sort(can.begin(), can.end());
        vector<vector<int>> ans;
        vector<int> out;
        solve(can, ans, out, 0, target);
        return ans;
    }
};
