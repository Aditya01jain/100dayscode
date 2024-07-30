class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> sm; 
        unordered_map<char,int> tm;
        for(auto i:s) sm[i]++;
        for(auto i:t) tm[i]++;
        return sm==tm;
    }
};