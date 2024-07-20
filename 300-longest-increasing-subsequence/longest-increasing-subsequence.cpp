class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1);
        int ans =1;
        for(int i=0;i<n;i++){
            for(int j= 0;j<i;j++){
                if(nums[i]>nums[j]){
                    dp[i] = max(dp[i],1+dp[j]);
                }
            }
            ans = max(dp[i],ans);
        }
        return ans;
    }
};