#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> numSet(nums.begin(), nums.end()); // Use set constructor to directly insert elements
        if (numSet.empty()) return 0; // Handle empty input
        
        int longestStreak = 0;
        
        for (int num : numSet) {
            // Check if it's the start of a sequence
            if (!numSet.count(num - 1)) {
                int currentNum = num;
                int currentStreak = 1;
                
                // Check the length of the current sequence
                while (numSet.count(currentNum + 1)) {
                    currentNum++;
                    currentStreak++;
                }
                
                longestStreak = max(longestStreak, currentStreak);
            }
        }
        
        return longestStreak;
    }
};
