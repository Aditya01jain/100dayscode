class Solution {
public:
    bool check(vector<int> v, int t) {
        int s = 0;
        int e = v.size() - 1;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (v[mid] == t) {
                return true;
            } else if (v[mid] > t) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;

        int s = 0;
        int e = matrix.size() - 1;
        int m = matrix[0].size();
        
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (matrix[mid][0] <= target && matrix[mid][m - 1] >= target) {
                return check(matrix[mid], target);
            } else if (matrix[mid][0] > target) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return false;
    }
};
