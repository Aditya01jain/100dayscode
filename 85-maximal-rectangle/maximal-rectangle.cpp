class Solution {
public:
int solve(vector<int> h){
        stack<int> s;
        int maxA =0;
        int n = h.size();
        for(int i=0;i<=n;i++){
            while(!s.empty() &&(i==n || h[s.top()]>=h[i])){
                int hig = h[s.top()];
                s.pop();
                int wid;
                if(s.empty()) wid = i;
                else wid = i - s.top() - 1;
                maxA = max(maxA,hig*wid);
            }
            s.push(i);
        }
        return maxA;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int ans = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> h(m,0);
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]=='1') h[j]++;
                else h[j]=0;
            }
            ans =max(ans,solve(h));
        }
        return ans;
    }
};