class Solution {
public:
    int solve(vector<int>& nums, int s2,int i,vector<vector<int>> &dp){
        if(i==0){
            if(s2==0 && nums[i]==0){
                return 2;
            }
            if(s2==0 || nums[i]==s2){
                return 1;
            }
            return 0;
        }
        if(dp[i][s2]!=-1){
            return dp[i][s2];
        }
        int dont = solve(nums,s2,i-1,dp);
        int take =0;
        if(s2>=nums[i]){
            take = solve(nums,s2-nums[i],i-1,dp);
        }
        return dp[i][s2] = dont+take;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = 0;
        int n = nums.size();
        for(int i=0;i<nums.size();i++){
            total+=nums[i];
        }
        if((total-target)%2!=0){
            return 0;
        }
        if(total-target<0){
            return 0;
        }
        int s2 = (total-target)/2;
        vector<vector<int>> dp(n+1,vector<int>(s2+1,-1));
        return solve(nums,s2,n-1,dp);
    }
};