class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        using ll = long long;
        ll mod = 1e9 + 7;  // Correct mod value
        unordered_map<int, set<pair<int, int>>> list;
        for (auto& i : roads) {
            list[i[0]].insert({i[1], i[2]});
            list[i[1]].insert({i[0], i[2]});
        }

        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
        vector<ll> dis(n, LLONG_MAX);
        vector<int> ways(n, 0);
        dis[0] = 0;
        ways[0] = 1;
        q.push({0, 0});

        while (!q.empty()) {
            ll w = q.top().first;
            int node = q.top().second;
            q.pop();

            for (auto& i : list[node]) {
                ll newDist = w + i.second;
                if (dis[i.first] > newDist) {
                    dis[i.first] = newDist;
                    q.push({dis[i.first], i.first});
                    ways[i.first] = ways[node];
                } else if (dis[i.first] == newDist) {
                    ways[i.first] = (ways[i.first] + ways[node]) % mod;
                }
            }
        }
        return ways[n - 1] % mod;
    }
};
