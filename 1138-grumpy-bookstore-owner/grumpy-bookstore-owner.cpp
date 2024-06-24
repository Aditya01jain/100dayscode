#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int satisfied = 0;
        int n = grumpy.size();

        // Calculate the initial satisfied customers without any grumpy periods
        for (int i = 0; i < n; i++) {
            if (grumpy[i] == 0) {
                satisfied += customers[i];
                customers[i] = 0;  // Neutralize these customers as they are always satisfied
            }
        }

        int maxIncrease = 0;
        int currentIncrease = 0;

        // Initialize the sliding window
        for (int i = 0; i < minutes && i < n; i++) {
            currentIncrease += customers[i];
        }
        maxIncrease = currentIncrease;

        // Slide the window over the rest of the elements
        for (int i = minutes; i < n; i++) {
            currentIncrease += customers[i] - customers[i - minutes];
            maxIncrease = max(maxIncrease, currentIncrease);
        }

        return satisfied + maxIncrease;
    }
};
