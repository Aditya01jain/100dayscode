class Solution {
public:
    bool solve(string s1, string s2,unordered_map<string,bool>& dp) {
        if (s1.size() == 1)
            return s1 == s2;
        if (s1 == s2)
            return true;
        if(dp.find(s1+s2)!=dp.end()) return dp[s1+s2];
        int n = s1.size();
        for (int i = 1; i < n; i++) {
            if((solve(s1.substr(0, i), s2.substr(0, i),dp) &&
              solve(s1.substr(i), s2.substr(i),dp)) ||
             (solve(s1.substr(0, i), s2.substr(n - i),dp) &&
              solve(s1.substr(i), s2.substr(0, n - i),dp))){
                return dp[s1+s2] = true;
              }
        }
        return dp[s1+s2] = false;
    }
    bool isScramble(string s1, string s2) {
        unordered_map<string,bool> dp;
        return solve(s1, s2,dp); 
    }
};