class Solution {
public:
    int maxProfitAssignment(vector<int>& d, vector<int>& profit, vector<int>& worker) {
        using node = pair<int,int>;
        int n = worker.size();
        priority_queue<node,vector<node>,greater<node>> mini;
        priority_queue<node> maxi;
        for(int i =0;i<profit.size();i++){
            mini.push(make_pair(d[i],profit[i]));
        }
        int sum = 0;
        sort(worker.begin(),worker.end());
        for(int i =0;i<n;i++){
            while(!mini.empty() && mini.top().first<=worker[i]){
                node temp = mini.top();
                mini.pop();
                maxi.push(make_pair(temp.second,temp.first));
            }
            if(!maxi.empty()){sum+=maxi.top().first;}
        }
        return sum;
    }
};