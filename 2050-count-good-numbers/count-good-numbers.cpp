class Solution {
public:
    int mod = 1e9+7;
    
    long long modPow(long long base, long long exp, int mod) {
        long long result = 1;
        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exp /= 2;
        }
        return result;
    }
    
    int countGoodNumbers(long long n) {
        long long odd = n / 2;
        long long even = (n + 1) / 2;  // This is the same as n/2 + (n%2)
        
        long long a = modPow(5, even, mod);
        long long b = modPow(4, odd, mod);
        
        long long k = (a * b) % mod;
        return (int)k;
    }
};
