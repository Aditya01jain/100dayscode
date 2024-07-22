class Solution {
public:
    bool check(const vector<int>& piles, int mid, int h) {
        int hours = 0;
        for (int pile : piles) {
            hours += (pile + mid - 1) / mid;
            if (hours > h) return false; 
        }
        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int s = 1;
        int e = *max_element(piles.begin(), piles.end());
        int ans = e;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (check(piles, mid, h)) {
                ans = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return ans;
    }
};
