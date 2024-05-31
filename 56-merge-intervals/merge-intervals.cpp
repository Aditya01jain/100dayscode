
class Solution {
public: 
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n == 0) return {};

        sort(intervals.begin(), intervals.end());

        int i = 0;
        while (i < n - 1) {
            if (intervals[i][1] >= intervals[i + 1][0]) {
                int mini = min(intervals[i + 1][0], intervals[i][0]);
                int maxi = max(intervals[i + 1][1], intervals[i][1]);
                intervals[i + 1][0] = mini;
                intervals[i + 1][1] = maxi;
                intervals.erase(intervals.begin() + i);
                n = intervals.size();
            } else {
                i++;
            }
        }
        return intervals;
    }
};
