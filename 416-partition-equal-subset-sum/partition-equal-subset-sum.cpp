class Solution {
public:
    int solve(vector<int>& nums,int sum ,int i,int n,vector<vector<int>>& dp){
        if(i>=n || sum<0){
            return 0;
        }
        if(sum==0){
            return 1;
        }
        if(dp[i][sum]!=-1){
            return dp[i][sum];
        }
        int take = solve(nums,sum-nums[i],i+1,n,dp);
        int dont = solve(nums,sum,i+1,n,dp);
        dp[i][sum] = take || dont;
        return dp[i][sum];
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(auto i:nums){
            sum+=i;
        }
        if(sum%2!=0){
            return false;
        }
        sum = sum/2;
        vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
        return solve(nums,sum,0,n,dp)>0;
    }
};