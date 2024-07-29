class Solution {
public:
    bool check(string &s,int i,int j){
        while(i<=j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n+1,-1);
        dp[n]=0;
        for(int i=n-1;i>=0;i--){
            int mini = INT_MAX;
            for(int j=i;j<n;j++){
                if(check(s,i,j)){
                    int res = 1 + dp[j+1];
                    mini=min(res,mini);
                }
            }
           dp[i]=mini;
        }
        return dp[0]-1;
    }
};