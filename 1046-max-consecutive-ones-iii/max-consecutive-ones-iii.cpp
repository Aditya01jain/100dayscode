class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0,j=0;
        int n = nums.size();
        int z=0;
        int ans = 0;
        while(j<n){
            if(nums[j]==0){
                z++;
            }
            if(z>k){
                while(z>k){
                    if(nums[i]==0) z--;
                    i++;
                }
            }
            ans = max(ans,(j-i+1));
            j++;
        }
        return ans;
    }
};