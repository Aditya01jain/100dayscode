class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,set<pair<int,int>>> mp;
        for(auto i:times){
            int u = i[0];
            int v = i[1];
            int t = i[2];
            mp[u].insert({v,t});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        q.push({0,k});
        vector<int> ans(n+1,-1);
        ans[k]=0;
        ans[0]=0;
        while(!q.empty()){
            int time = q.top().first;
            int node = q.top().second;
            q.pop();
            for(auto no:mp[node]){
                if(ans[no.first]==-1 || ans[no.first]>time+no.second){
                    ans[no.first] = time + no.second;
                    q.push({ans[no.first],no.first});
                }
            }
        }
        int res = -1;
        for(auto i:ans) {
            if(i==-1) return -1;
            res = max(res,i);}
        return res;
    }
};