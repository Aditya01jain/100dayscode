#include <vector>
#include <set>

class Solution {
public:
    int nthUglyNumber(int n) {
        if (n <= 0) return 0;
        if (n == 1) return 1;
        
        vector<int> ans(n);
        ans[0] = 1;
        
        int i2 = 0, i3 = 0, i5 = 0; // indices for 2, 3, and 5
        
        for (int i = 1; i < n; ++i) {
            int next2 = ans[i2] * 2;
            int next3 = ans[i3] * 3;
            int next5 = ans[i5] * 5;
            
            int nextUgly = std::min({next2, next3, next5});
            ans[i] = nextUgly;
            
            if (nextUgly == next2) i2++;
            if (nextUgly == next3) i3++;
            if (nextUgly == next5) i5++;
        }
        
        return ans[n - 1];
    }
};
