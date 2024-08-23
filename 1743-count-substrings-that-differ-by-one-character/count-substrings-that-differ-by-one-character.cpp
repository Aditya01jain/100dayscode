class Solution {
public:
    int solve(string& s,string &t,int i,int j,bool diff,vector<vector<vector<int>>>&dp){
        if(i == s.length() || j == t.length())
            return 0;
        if(dp[i][j][diff] != -1)
            return dp[i][j][diff];
        if(diff){
            if(s[i] != t[j])
                return dp[i][j][diff] = 0;
            return dp[i][j][diff] = 1 + solve(s,t,i+1,j+1,diff,dp);
        }
        if(s[i] != t[j])
            return dp[i][j][diff] = 1 + solve(s,t,i+1,j+1,true,dp);
        return dp[i][j][diff] = solve(s,t,i+1,j+1,diff,dp);
    }
    int countSubstrings(string s, string t) {
        int ans = 0;
        vector<vector<vector<int>>>dp(s.length(),vector<vector<int>>(t.length(),vector<int>(2,-1)));
        for(int i = 0;i < s.length();i++)
            for(int j = 0;j < t.length();j++)
                ans += solve(s,t,i,j,false,dp);
        return ans;
    }
};