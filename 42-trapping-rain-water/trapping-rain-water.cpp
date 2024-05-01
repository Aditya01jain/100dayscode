#include <vector>
#include <algorithm> // for std::max

class Solution {
public:
    void leftmax(std::vector<int>& height, std::vector<int>& left) {
        int m = -1;
        for (int i = 0; i < height.size(); i++) {
            m = std::max(m, height[i]);
            left[i] = m;
        }
    }
    
    void rightmax(std::vector<int>& height, std::vector<int>& right) {
        int m = -1;
        for (int i = height.size() - 1; i >= 0; i--) {
            m = std::max(m, height[i]);
            right[i] = m;
        }
    }
    
    int trap(std::vector<int>& height) {
        int n = height.size();
        int ans = 0;
        std::vector<int> left(n);  // l[i] := max(height[0..i])
        std::vector<int> right(n); // r[i] := max(height[i..n-1])
        rightmax(height, right);
        leftmax(height, left);
        for (int i = 0; i < n; ++i) {
            int temp = std::min(right[i], left[i]);
            if (temp > height[i]) {
                ans += temp - height[i];
            }
        }
        return ans;
    }
};
