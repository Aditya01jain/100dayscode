class Solution {
public:
    int solve(vector<int>& arr, int ind,int k,vector<int>& dp){
        if(ind==arr.size()) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int maxi = INT_MIN;
        int ans = INT_MIN;
        int len =0;
        int l = min(ind+k,(int)arr.size());
        for(int i =ind;i<l;i++){
            len++;
            maxi = max(maxi,arr[i]);
            int res = len*maxi + solve(arr,i+1,k,dp);
            ans = max(res,ans);
        }
        return dp[ind]=ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size(),-1);
        return solve(arr,0,k,dp);
    }
};