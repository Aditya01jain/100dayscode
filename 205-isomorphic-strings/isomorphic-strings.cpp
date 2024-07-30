class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        // s -> t
        unordered_map<char, char> s_t;
        // t -> s
        unordered_map<char, char> t_s;
        
        for (int i=0; i<s.length(); i++) {
            if (s_t[s[i]] && s_t[s[i]] != t[i]) return false;
            if (t_s[t[i]] && t_s[t[i]] != s[i]) return false;
            
            s_t[s[i]] = t[i];
            t_s[t[i]] = s[i];
        }
        return true;
    }
};