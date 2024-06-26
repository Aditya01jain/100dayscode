class Solution {
public:
    void solve(vector<int>& nums, int target, vector<int>& out, vector<vector<int>>& ans, int start) {
        if (out.size() == 4) {
            long long sum = accumulate(out.begin(), out.end(), 0LL); // Use long long for sum
            if (sum == target) {
                ans.push_back(out);
            }
            return;
        }

        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i - 1]) continue; // Skip duplicates
            out.push_back(nums[i]);
            solve(nums, target, out, ans, i + 1);
            out.pop_back();
        }
    }

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> out;
        vector<vector<int>> ans;
        solve(nums, target, out, ans, 0);
        return ans;
    }
};
