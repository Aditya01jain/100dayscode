class Solution {
public:
    bool check(vector<int>& b, int m, int k, int mid) {
        int n = b.size();
        int bouquets = 0;
        int flowers = 0;
        for (int i = 0; i < n; ++i) {
            if (b[i] <= mid) {
                flowers++;
                if (flowers == k) {
                    bouquets++;
                    flowers = 0;
                }
            } else {
                flowers = 0;
            }
            if (bouquets >= m) {
                return true;
            }
        }
        return false;
    }

    int minDays(vector<int>& b, int m, int k) {
        int n = b.size();
        if (static_cast<long long>(m) * k > n) {
            return -1; 
        }
        int s = *min_element(b.begin(), b.end());
        int e = *max_element(b.begin(), b.end());
        int ans = -1;
        
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (check(b, m, k, mid)) {
                e = mid - 1;
                ans = mid;
            } else {
                s = mid + 1;
            }
        }
        return ans;
    }
};
