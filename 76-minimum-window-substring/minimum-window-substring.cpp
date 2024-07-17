class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;
        for (char c : t) mp[c]++;
        int required = mp.size();
        int l = 0, r = 0;
        int formed = 0;
        unordered_map<char, int> windowCounts;
        int ans[] = {-1, 0, 0};
        while (r < s.size()) {
            char c = s[r];
            windowCounts[c]++;
            if (mp.count(c) && windowCounts[c] == mp[c]) formed++;
            while (l <= r && formed == required) {
                c = s[l];
                if (ans[0] == -1 || r - l + 1 < ans[0]) {
                    ans[0] = r - l + 1;
                    ans[1] = l;
                    ans[2] = r;
                }
                windowCounts[c]--;
                if (mp.count(c) && windowCounts[c] < mp[c]) formed--;
                l++;
            }
            r++;
        }
        return ans[0] == -1 ? "" : s.substr(ans[1], ans[0]);
    }
};
