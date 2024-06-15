#include <vector>
#include <stack>
#define mod 1000000007
using namespace std;

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> ple(n), nle(n);
        stack<int> s;

        // Calculate Previous Less Element (PLE)
        for (int i = 0; i < n; ++i) {
            while (!s.empty() && arr[s.top()] > arr[i]) {
                s.pop();
            }
            ple[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }

        // Clear the stack for reuse
        while (!s.empty()) s.pop();

        // Calculate Next Less Element (NLE)
        for (int i = n - 1; i >= 0; --i) {
            while (!s.empty() && arr[s.top()] >= arr[i]) {
                s.pop();
            }
            nle[i] = s.empty() ? n : s.top();
            s.push(i);
        }

        // Calculate the sum of subarray minimums
        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            long long left = i - ple[i];
            long long right = nle[i] - i;
            sum = (sum + arr[i] * left * right) % mod;
        }

        return static_cast<int>(sum);
    }
};
