class Solution {
public:
    vector<int> intersect(vector<int>& a, vector<int>& b) {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int i = 0, j = 0;
        vector<int> v;
        while (i < a.size() && j < b.size()) {
            if (a[i] < b[j])
                i++;
            else if (b[j] < a[i])
                j++;
            else {
                v.push_back(a[i]);
                i++;
                j++;
            }
        }
        return v;
    }
};