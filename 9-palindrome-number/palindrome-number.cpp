class Solution {
public:
    bool isPalindrome(int x) {
        vector<int> ans;
        if(x<0) return false;
        while(x>0){
            ans.push_back(x%10);
            x = x/10;
        }
        int i =0;
        int e =ans.size()-1;
        while(i<=e){
            if(ans[i]!=ans[e]) return false;
            i++;
            e--;
        }
        return true;
    } 
};