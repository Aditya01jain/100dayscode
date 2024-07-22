class Solution {
public:
    int solve(vector<int>& nums,int i,int sum,vector<vector<int>>& dp){
        if(i==0){
            if(sum==0 && nums[i]==0) return 2;
            if(sum==0 || nums[i]==sum) return 1;
            return 0;
        }
        if(dp[i][sum]!=-1) return dp[i][sum];
        int dont = solve(nums,i-1,sum,dp);
        int take =0;
        if(sum-nums[i]>=0)
            take = solve(nums,i-1,sum-nums[i],dp);
        return dp[i][sum] = take || dont;
    }
    bool canPartition(vector<int>& nums) {
        int total = 0;
        for(int i:nums) total+=i;
        if(total%2!=0) return false;
        total = total/2;
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(total+1,-1));
        if(solve(nums,n-1,total,dp)>0) return true;
        return false;
    }
};