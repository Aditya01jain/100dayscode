class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> sum_map;
        sum_map[0] = -1; // To handle the case where the subarray starts from index 0
        int cumulative_sum = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            cumulative_sum += nums[i];
            int mod = cumulative_sum % k;
            if (mod < 0) {
                mod += k; // To handle negative mod values
            }
            
            if (sum_map.find(mod) != sum_map.end()) {
                if (i - sum_map[mod] > 1) {
                    return true;
                }
            } else {
                sum_map[mod] = i;
            }
        }
        return false;
    }
};
