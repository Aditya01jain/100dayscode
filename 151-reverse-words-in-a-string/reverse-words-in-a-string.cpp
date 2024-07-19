class Solution {
public:
    string reverseWords(string s) {
        vector<string> ans;
        string temp ="";
        for(auto ch:s){
            if(ch==' '){
                if(temp.size()>0){
                    ans.push_back(temp);
                }
                temp ="";
            }else{
                temp+=ch;
            }
        }
        if(temp.size()>0) ans.push_back(temp);
        reverse(ans.begin(),ans.end());
        string res ="";
        for(int i=0;i<ans.size();i++){
            res+=ans[i];
            if(i!=ans.size()-1) res+=" ";
        }
        return res;
    }
};