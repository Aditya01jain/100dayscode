class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
         unordered_map<int, int> remainderCount;
    long long pairCount = 0;
    
    for (int hour : hours) {
        int remainder = hour % 24;
        int complement = (24 - remainder) % 24;
        
        if (remainderCount.find(complement) != remainderCount.end()) {
            pairCount += remainderCount[complement];
        }
        
        remainderCount[remainder]++;
    }
    
    return pairCount;
    }
};