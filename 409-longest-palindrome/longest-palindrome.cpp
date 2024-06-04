class Solution {
public:
    int longestPalindrome(string s) {
        map<char,int> m;
        for(int i=0;i<s.size();i++){
            m[s[i]]++;
        }
        int ans=0;
        bool oneOdd=false;
        for(auto i:m){
            if(i.second % 2==0){
                ans=ans+i.second;
            }
            else{
                if(oneOdd==false){
                    ans=ans+i.second;
                    oneOdd=true;
                }
                else{
                    ans=ans+i.second-1;
                }
            }
        }
        return ans;
    }
};