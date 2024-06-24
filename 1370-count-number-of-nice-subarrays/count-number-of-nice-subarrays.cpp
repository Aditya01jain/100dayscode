class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int> pre;
        int ans = 0;
        int n = nums.size();
        int pref = 0;
        pre[0]=1;
        for(int i =0 ;i<n;i++){
           if(nums[i]%2!=0){
            pref++;
           }
           if(pre.find(pref-k)!=pre.end()){
            ans+=pre[pref-k];
           }
           pre[pref]++;
        }
        return ans;
    }
};