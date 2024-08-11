class Solution {
public:
    void generator(vector<string> &ans,string s,int n,int index,int cnt1,int cnt2){
        if(index==2*n){
            ans.push_back(s);
            return;
        }
        if(cnt1<n){
            s=s+'(';
            generator(ans,s,n,index+1,cnt1+1,cnt2);
            s.pop_back();
        }
        if(cnt2<cnt1){
            s=s+')';
            generator(ans,s,n,index+1,cnt1,cnt2+1);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        generator(ans,"",n,0,0,0);
        return ans;
    }
};