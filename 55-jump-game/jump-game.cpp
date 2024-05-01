#include <vector>
#include <algorithm> // for std::max

class Solution {
public:
    bool canJump(std::vector<int>& nums) {
        int reach = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (reach < i) // Can't reach the current position 'i'
                return false;
            reach = std::max(reach, i + nums[i]);
            if (reach >= nums.size() - 1) // Can reach the last index
                return true;
        }
        return true; // This is unreachable if the last index can't be reached.
    }
};
