class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,1);
        vector<int> hash(n+1,1);
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && dp[i]<1+dp[j]){
                    dp[i] = 1+dp[j];
                    hash[i]=j;
                }
            }
        }
        int ans=-1;
        int last=-1;
        for(int i=0;i<n;i++){
            if(dp[i]>ans){
                ans = dp[i];
                last = i;
            }
        }
        vector<int> res;
        res.push_back(nums[last]);
        while(hash[last]!=last){
            last = hash[last];
            res.push_back(nums[last]);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};