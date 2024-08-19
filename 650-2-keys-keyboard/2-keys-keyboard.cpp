class Solution {
public:
    int minSteps(int n) {
        int steps = 0;
        int current_length = 1, copied_length = 0;
        bool copied = false;

        while (current_length < n){
            if (!copied){
                copied = true;
                copied_length = current_length;
            } else {
                current_length += copied_length;
                if (n % (current_length) == 0){
                    copied = false;
                }
            }	
            steps += 1;
	}
		
	return steps;
    }
};