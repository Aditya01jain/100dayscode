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
        int n = arr.size();
        vector<int> dp(n+1,-1);
        dp[n]=0;
        for(int ind=n-1;ind>=0;ind--){
            int maxi = INT_MIN;
            int ans = INT_MIN;
            int len =0;
            int l = min(ind+k,(int)arr.size());
            for(int i =ind;i<l;i++){
                len++;
                maxi = max(maxi,arr[i]);
                int res = len*maxi + dp[i+1];
                ans = max(res,ans);
            }
            dp[ind]=ans;
            }
        return dp[0];
    }
};