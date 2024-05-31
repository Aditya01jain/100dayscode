class Solution {
public:
    bool ok(string s,int len){
        int n = s.size();
        map<char,int> first;
        for(int i =0;i<len;i++){
            first[s[i]]++;
        }
        for(int i=len ;i<n;i+=len){
            map<char,int> range;
            for(int j = i ;j<i+len;j++){
                range[s[j]]++;
            }
            if(first!=range){
                return false;
            }
        }
        return true;
    }
    int minAnagramLength(string s) {
        int n = s.size();
        for(int len = 1;len<=n;len++){
            if(n%len==0 && ok(s,len)){
                return len;
            }
        }
        return n;
    }
};