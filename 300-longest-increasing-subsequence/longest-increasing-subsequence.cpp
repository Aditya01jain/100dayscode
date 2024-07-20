class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        vector<int> temp;
        temp.push_back(nums[0]);
        int l = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] > temp.back()) {
                temp.push_back(nums[i]);
                l++;
            } else {
                int ind = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
                temp[ind] = nums[i];
            }
        }
        return l;
    }
};
