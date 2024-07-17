class Solution {
public:
    int maxDepth(string s) {
        int i =0;
        int ans = 0;
        for(auto c : s){
            if(c=='('){
                i++;
                ans = max(ans,i);
            }else if(c==')'){
                i--;
            }
        }
        return ans ;
    }
};