class Solution {
public:

    int solve(string str, int ind,vector<string>&m,int len, int n, vector<vector<int>>&dp){
        if(len==n) return 1;
        if(ind==5) return 0;
        if(dp[len][ind]!=-1) return dp[len][ind];
        int np = solve(str,ind+1,m,len,n,dp);
        int p = 0;
        if(len<n){
            str = str+m[ind];
            p = solve(str,ind,m,len+1,n,dp);
        }
        return dp[len][ind] = np+p;
    }
    int countVowelStrings(int n) {
        vector<string>m = {"a","e","i","o","u"};
        string str = "";
        vector<vector<int>>dp(n,vector<int>(5,-1));
        int ans = solve(str,0,m,0,n,dp);
        return ans;
    }
};