class Solution {
public:
    int appendCharacters(string s, string t) {
        int is=0;
        int it=0;
        while(is<s.size() && it<t.size()){
            if(s[is]==t[it]){
                is++;
                it++;
            }else{
                is++;
            }
        }
        return t.size()-it;
    }
};