class Solution {
    int fun(string &text1,string &text2,int i,int j,vector<vector<int>> &dp){
        if(i==-1 || j==-1) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int res1=0,res2=0;
        if(text1[i]==text2[j])res1= 1+ fun(text1,text2,i-1,j-1,dp);
        res2= max(fun(text1,text2,i-1,j,dp),fun(text1,text2,i,j-1,dp));
        return dp[i][j]=max(res1,res2);
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.length(),m=text2.length();
        vector<vector<int>> dp(n,vector<int> (m,-1));
        return fun(text1,text2,n-1,m-1,dp);
    }
};