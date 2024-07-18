class Solution {
public:
int mod=1e9+7;
int power(long long a,long long b){
    // if(b==0)return 0;
    long long res=1;
    while(b){
        if(b&1){
            res=(res*a)%mod;
            b=b-1;
        }
        else{
            a=(a*a)%mod;
            b=b/2;

        }
    }
    return (int)res%mod;
}
    int countGoodNumbers(long long n) {
        long long odd=0,even=0;
        if(n%2==0){
odd=n/2;
even=n/2;
        }
        else {
            odd=n/2;
            even=n/2+1;
        }
        long long a=power(5,even)%mod;
        long long b=power(4,odd)%mod;
        long long k=(a*b)%mod;
        return (int)k;
    }
};