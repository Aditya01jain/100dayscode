class Solution {
public:
    void solve(set<vector<int>> &ans,vector<int> out,vector<int>& candidates,int target,int total){
        if(target==total){
            sort(out.begin(),out.end());
            ans.insert(out);
            return;
        }
        if(total>target){
            return;
        }
        for(auto i:candidates){
            out.push_back(i);
            solve(ans,out,candidates,target,total+i);
            out.pop_back();
        }
        return ;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        set<vector<int>> ans;
        vector<int> out;
        int total =0;
        for(auto i:candidates){
            out.push_back(i);
            solve(ans,out,candidates,target,total+i);
            out.pop_back();
        }
        vector<vector<int>> a(ans.begin(),ans.end());
        return a;
    }
};