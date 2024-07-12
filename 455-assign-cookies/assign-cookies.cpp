class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // Sort both arrays
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i = 0; // Pointer for children
        int j = 0; // Pointer for cookies

        // Try to satisfy each child with the smallest cookie that can satisfy them
        while (i < g.size() && j < s.size()) {
            if (s[j] >= g[i]) {
                i++; // Move to the next child
            }
            j++; // Move to the next cookie
        }

        // The number of satisfied children is `i`
        return i;
    }
};
