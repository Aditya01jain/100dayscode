class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, r = 0;
        int ans = 0;
        int maxf = 0;
        unordered_map<char, int> mp; // Change int to char for map key type
        
        while (r < s.size()) {
            mp[s[r]]++;
            maxf = max(maxf, mp[s[r]]);
            
            while ((r - l + 1) - maxf > k) {
                mp[s[l]]--;
                l++;
                // No need to recalculate maxf here as it does not impact the logic
            }
            
            ans = max(ans, r - l + 1); // Correctly calculate the answer
            r++;
        }
        
        return ans;
    }
};
