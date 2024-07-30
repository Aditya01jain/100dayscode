class Solution {
public:
    int minimumDeletions(string s) {
        map<char,int>mp;
        int cnt=0;
        for(int i=0;i<s.size();i++){
                if(s[i]=='a'&& mp['b']>0){
                    cnt++;mp['b']--;
                }
            else{
                mp[s[i]]++;
            }
        }
        return cnt;
    }
};