class Solution {
public:
    int numberOfSubstrings(string s) {
        int l = 0, r = 0;
        int n = s.size();
        unordered_map<char, int> mp;
        int ans = 0;

        while (r < n) {
            mp[s[r]]++;
            
            // If we have all 3 characters in the current window
            while (mp['a'] > 0 && mp['b'] > 0 && mp['c'] > 0) {
                ans += (n - r); // All substrings from current r to end are valid
                mp[s[l]]--;
                l++;
            }
            
            r++;
        }
        
        return ans;
    }
};
