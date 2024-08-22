class Solution {
public:
    int twoEggDrop(int n) {
        int a = sqrt(2 * n) + 1;
        int l = 1, h = a;
        int mid = (l + h) / 2;
        while (l <= h) {
            int b = (mid * (mid + 1)) / 2;
            if (b < n) {
                l = mid + 1;
            } else {
                h = mid - 1;
            }
            mid = (l + h) / 2;
        }
        return l;
    }
};