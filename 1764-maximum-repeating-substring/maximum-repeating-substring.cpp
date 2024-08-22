class Solution {
public:
    int maxRepeating(string seq, string w) {
        int maxCount = 0;
        int k = w.size();
        string temp = w;
        
        while (seq.find(temp) != string::npos) {
            maxCount++;
            temp += w;
        }
        
        return maxCount;
    }
};
