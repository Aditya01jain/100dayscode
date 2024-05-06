class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,0);
        int zero=-1;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                zero=i;
                break;
            }
        }
        if(zero!=-1){
            int prod=1;
            for(int i=0;i<n;i++){
                if(i!=zero){
                    prod*=nums[i];
                }
            }
            ans[zero]=prod;
            return ans;
        }
        int prod=1;
        for(int i=0;i<n;i++){
            prod*=nums[i];
        }
        for(int i=0;i<n;i++){
            ans[i]=prod/nums[i];
        }
        return ans;
    }
};