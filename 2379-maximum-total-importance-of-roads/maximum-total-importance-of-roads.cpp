class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int>degrees(n,0);
        for(auto rd:roads){
            int u = rd[0];
            int v = rd[1];
            degrees[u]++;
            degrees[v]++;
        }

        sort(degrees.begin(),degrees.end());

        long long val = 1;
        long long sum = 0;
        for(auto deg : degrees)
        {
            sum+= (deg *val);
            val++;
        }

        return sum;
        
    }
};