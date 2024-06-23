#include<algorithm>
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int ans = INT_MIN;
        int n = nums.size();
        for(int i =0;i<n;i++){
            priority_queue<int> maxi;
            priority_queue<int,vector<int>,greater<int>> mini;
            maxi.push(nums[i]);
            mini.push(nums[i]);
            for(int j= i+1 ;j<n;j++){
                if(abs(max(maxi.top(),nums[j])-min(mini.top(),nums[j]))<=limit ){
                    maxi.push(nums[j]);
                    mini.push(nums[j]);
                }else{
                    break;
                }
                
            }
            int s = maxi.size();
            ans = max(ans,s);
            if(ans == (n-i+1)){
                return ans;
            }
        }
        return ans;
    }
};