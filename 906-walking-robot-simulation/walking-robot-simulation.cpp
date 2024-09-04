class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        vector<int> p = {0, 0};
        set<pair<int, int>> obstacleSet;
        for (auto& obs : obstacles) {
            obstacleSet.insert({obs[0], obs[1]});
        }
        int ans = 0;
        char dir = 'N';
        for (int i : commands) {
            if (i == -2) {
                if (dir == 'N') dir = 'W';
                else if (dir == 'S') dir = 'E';
                else if (dir == 'E') dir = 'N';
                else if (dir == 'W') dir = 'S';
            }
            else if (i == -1) {
                if (dir == 'N') dir = 'E';
                else if (dir == 'S') dir = 'W';
                else if (dir == 'E') dir = 'S';
                else if (dir == 'W') dir = 'N';
            }
            else {
                if (dir == 'N') {
                    for (int j = 1; j <= i; j++) {
                        p[1] += 1;
                        if (obstacleSet.count({p[0], p[1]})) {
                            p[1] -= 1;
                            break;
                        }
                    }
                }
                else if (dir == 'S') {
                    for (int j = 1; j <= i; j++) {
                        p[1] -= 1;
                        if (obstacleSet.count({p[0], p[1]})) {
                            p[1] += 1;
                            break;
                        }
                    }
                }
                else if (dir == 'E') {
                    for (int j = 1; j <= i; j++) {
                        p[0] += 1;
                        if (obstacleSet.count({p[0], p[1]})) {
                            p[0] -= 1;
                            break;
                        }
                    }
                }
                else if (dir == 'W') {
                    for (int j = 1; j <= i; j++) {
                        p[0] -= 1;
                        if (obstacleSet.count({p[0], p[1]})) {
                            p[0] += 1;
                            break;
                        }
                    }
                }
                ans = max(ans, p[0] * p[0] + p[1] * p[1]);
            }
        }
        return ans;
    }
};
