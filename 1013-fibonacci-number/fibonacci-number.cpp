class Solution {
public:
    int fib(int n) {
        if(n==0) return 0;
        if (n <= 2) return 1;
        int fir = 0;
        int sec = 1;
        for (int i = 2; i <= n; i++) {
            int temp = sec;
            sec = fir + sec;
            fir = temp;
        }
        return sec;
    }
};