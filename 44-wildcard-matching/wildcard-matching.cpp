class Solution {
public:
    int solve(string &s,string &p,int i,int j,vector<vector<int>> &dp){
        if(i<0 && j<0) return 1;
        if(i>=0 && j<0) return 0;
        if(i<0){
            for(int k=0;k<=j;k++){
                if(p[k]!='*') return 0;
            }
            return 1;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==p[j] || p[j]=='?') return dp[i][j] = solve(s,p,i-1,j-1,dp);
        if(p[j]=='*') return dp[i][j] = solve(s,p,i-1,j,dp) || solve(s,p,i,j-1,dp);
        return dp[i][j]=0;
    }
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n,vector<int> (m,-1));
        if(solve(s,p,n-1,m-1,dp)>=1) return true;
        return false;
    }
};