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
        vector<vector<int>> dp(n+1,vector<int> (m+1,-1));
        for(int i=0;i<=n;i++) dp[i][0]=0;
        for(int j=0;j<=m;j++) dp[0][j]=0;
        for(int i =1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1]==text2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
};