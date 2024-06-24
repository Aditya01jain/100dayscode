class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int satisfied = 0;
        int n = grumpy.size();
        for (int i = 0; i < n; i++) {
            if (grumpy[i] == 0) {
                satisfied += customers[i];
                customers[i] = 0; 
            }
        }

        int maxIncrease = 0;
        int currentIncrease = 0;
        for (int i = 0; i < minutes && i < n; i++) {
            currentIncrease += customers[i];
        }
        maxIncrease = currentIncrease;
        for (int i = minutes; i < n; i++) {
            currentIncrease += customers[i] - customers[i - minutes];
            maxIncrease = max(maxIncrease, currentIncrease);
        }

        return satisfied + maxIncrease;
    }
};
