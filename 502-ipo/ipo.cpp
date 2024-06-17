#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minCapital;
        priority_queue<pair<int, int>> maxProfit;
        for (int i = 0; i < profits.size(); i++) {
            minCapital.push(make_pair(capital[i], profits[i]));
        }
        for (int i = 0; i < k; i++) {
            while (!minCapital.empty() && minCapital.top().first <= w) {
                pair<int, int> project = minCapital.top();
                minCapital.pop();
                maxProfit.push(make_pair(project.second, project.first));
            }
            if (maxProfit.empty()) {
                break;
            }
            w += maxProfit.top().first;
            maxProfit.pop();
        }

        return w;
    }
};
