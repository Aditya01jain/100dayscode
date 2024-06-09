class Solution {
public:
    int longestValidParentheses(string s) {
        unordered_map<int,int> count;
        int sum = 0;
        int retval = 0;
        int check = 1;
        count[0] = -1;
        for(int i = 0;i<s.length();i++)
        {
            if(s[i]=='(') sum++; else sum--;
            if(count[sum]==0) count[sum] = i+1;
            else
            {
                if(retval<i-count[sum]+1) 
                {
                    if(count[sum]==-1) retval = i+1;
                    else retval = i-count[sum]+1;
                }
            }
            count[sum+1] = 0;
        }
        return retval;   
    }
};