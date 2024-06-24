class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int ans = 0,pref =0;
        unordered_map<int,int> mp;
        mp[0]=1;
        for(int i =0;i<nums.size();i++){
            pref += nums[i];
            if(mp.find(pref-goal)!=mp.end()){
                ans+=mp[pref-goal];
            }
            mp[pref]++;
        }
        return ans ;
    }
};