class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans =0;
        int c =0;
        for(auto i:nums){
            if(i==1){
                c++;
            }else{
                ans = max(c,ans);
                c=0;
            }
        }
        return max(ans,c);
    }
};