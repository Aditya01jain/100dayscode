class Solution {
public:
    int solve(string &s,string& t,int i,int j){
        if(i<0 && j<0) return 1;
        if(i<0) return 1;
        if(j<0) return 0;
        if(s[i]==t[j]) return solve(s,t,i-1,j-1);
        return solve(s,t,i,j-1);
    }
    bool isSubsequence(string s, string t) {
        if(solve(s,t,s.size()-1,t.size()-1)==1) return true;
        return false;
    }
};