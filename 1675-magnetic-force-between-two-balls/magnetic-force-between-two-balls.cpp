class Solution {
public:
    bool check(vector<int>& p , int m, int dist) {
        int n = p.size();
        int count = 1; 
        int last_position = p[0];
        
        for (int i = 1; i < n; ++i) {
            if (p[i] - last_position >= dist) {
                count++;
                last_position = p[i];
                if (count >= m) {
                    return true;
                }
            }
        }
        return false;
    }
    
    int maxDistance(vector<int>& p, int m) {
        sort(p.begin(), p.end());
        int n = p.size();
        int s = 1; 
        int e = p[n-1] - p[0]; 
        int ans = 0;
        
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (check(p, m, mid)) {
                ans = mid;
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
        return ans;
    }
};
