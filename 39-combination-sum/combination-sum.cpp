class Solution {
public:
    void solve(vector<int>& candidates,vector<int>  out,set<vector<int>>& ans,int tar){
        if(tar==0){
            sort(out.begin(),out.end());
            ans.insert(out);
        }
        if(tar<0) return ;
        for(int i:candidates){
            out.push_back(i);
            solve(candidates,out,ans,tar-i);
            out.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        set<vector<int>> ans;
        vector<int> out;
        for(int i:candidates){
            out.push_back(i);
            solve(candidates,out,ans,target-i);
            out.pop_back();
        }
        vector<vector<int>> res(ans.begin(),ans.end());
        return res;
    }
};