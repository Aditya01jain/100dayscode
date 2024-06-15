class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<int> arg(n);
        iota(arg.begin(), arg.end(), 0);
        sort(arg.begin(), arg.end(), [&](int a, int b){
            return capital[a] < capital[b];
        });
        int i = 0;
        priority_queue<int> pq;
        while(k--){
            while(i < n and capital[arg[i]] <= w){
                pq.push(profits[arg[i]]);
                i++;
            }
            if(pq.empty()) return w;
            w += pq.top();
            pq.pop();
        }
        return w;
    }
};