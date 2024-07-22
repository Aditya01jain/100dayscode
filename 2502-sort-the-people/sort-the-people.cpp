class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<string> ans ;
        vector<pair<int,string>> q;
        for(int i=0;i<names.size();i++){
            q.push_back({heights[i],names[i]});
        }
        sort(q.begin(),q.end(),greater<pair<int,string>>());
        for(auto i : q){
            ans.push_back(i.second);
        }
        return ans;
    }
};