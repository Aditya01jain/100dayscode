class Solution {
public:
    void solve(set<vector<int>>& ans,vector<int> out,int k,int n ,vector<int> &vis){
        if(n==0 && out.size()==k){
            sort(out.begin(),out.end());
            ans.insert(out);
            return;
        }
        if(n<0 || out.size()>=k){
            return;
        }
        for(int i = 1 ;i<=9;i++){
            if(vis[i]!=1){
                vis[i]=1;
                out.push_back(i);
                solve(ans,out,k,n-i,vis);
                vis[i]=-1;
                out.pop_back();
            }
        }
        return;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        set<vector<int>> ans;
        vector<int> out;
        vector<int> vis(10,-1);
        for(int i =1;i<=9;i++){
            vis[i]=1;
            out.push_back(i);
            solve(ans,out,k,n-i,vis);
            vis[i]=-1;
            out.pop_back();
        }
        vector<vector<int>> a(ans.begin(),ans.end());
        return a;
    }
};