class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,int> mp;
        int n = edges.size();
        for(auto& i:edges){
            mp[i[0]]++;
            mp[i[1]]++;
            if(mp[i[1]]==n-1){
                return i[1];
            }
            if(mp[i[0]]==n-1){
                return i[0];
            }
        }
        return -1;
    }
};