class Solution {
public:
    void f(vector<int>& arr, int ind,vector<int>& ans,vector<vector<int>>& ds){
        ds.push_back(ans);
        for(int i= ind;i<arr.size();i++){
            //avoiding duplicates
            if(i!=ind && arr[i]==arr[i-1]){
                continue;
            }
            ans.push_back(arr[i]);
            f(arr,i+1,ans,ds);
            ans.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& arr) {
        //so that duplicate no.s are together
        sort(arr.begin(), arr.end());
        vector<vector<int>> ds;
        vector<int> ans;
        //initital state of recursion
        f(arr,0,ans,ds);
        return ds;
    }
};