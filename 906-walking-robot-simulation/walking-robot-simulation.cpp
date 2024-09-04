struct VectorHash {
    size_t operator()(const std::vector<int>& v) const {
        std::hash<int> hasher;
        size_t seed = 0;
        for (int i : v) {
            seed ^= hasher(i) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        }
        return seed;
    }
};
class Solution {
public:
    bool find(vector<int> p, vector<vector<int>>& ob) {
        for (auto i : ob)
            if (p == i)
                return false;
        return true;
    }
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        vector<int> p = {0, 0};
        unordered_map<vector<int>, int, VectorHash> mp;
        for(auto i:obstacles) mp[i]++;
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
            else{
                if (dir == 'N'){
                    for(int j =1;j<=i;j++){
                        p[1]+=1;
                        if(mp[p]==1){
                            p[1]-=1;
                            break;
                        }
                    }
                    ans = max(ans,(p[0]*p[0] + p[1]*p[1]));
                }
                else if (dir == 'S'){
                    for(int j =1;j<=i;j++){
                        p[1]-=1;
                        if(mp[p]==1){
                            p[1]+=1;
                            break;
                        }
                    }
                    ans = max(ans,(p[0]*p[0] + p[1]*p[1]));
                }
                else if (dir == 'E'){
                    for(int j =1;j<=i;j++){
                        p[0]+=1;
                        if(mp[p]==1){
                            p[0]-=1;
                            break;
                        }
                    }
                    ans = max(ans,(p[0]*p[0] + p[1]*p[1]));
                }
                else if (dir == 'W'){
                    for(int j =1;j<=i;j++){
                        p[0]-=1;
                        if(mp[p]==1){
                            p[0]+=1;
                            break;
                        }
                    }
                    ans = max(ans,(p[0]*p[0] + p[1]*p[1]));
                }
            }
        }
        return ans;
    }
};