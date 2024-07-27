class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<long long,long long> mp;
        long long sum =0;
        for(long long i =0;i<k;i++){
            sum+=nums[i];
            mp[nums[i]]++;
        }
        long long i=0;
        long long j=k-1;
        long long ans =0;

        while(j<nums.size()-1){
            if(mp.size()==k){
                ans = max(ans,sum);
            }
            mp[nums[i]]--;
            if(mp[nums[i]]==0) mp.erase(nums[i]);
            sum-=nums[i];
            i++;
            j++;
            sum+=nums[j];
            mp[nums[j]]++;
        }
        if(mp.size()==k){
            ans = max(ans,sum);
        }
        return ans;
    }
};