class Solution {
public:
    void leftmax(vector<int>& height,vector<int>& left){
        int m =-1;
        for(int i=0;i<height.size();i++){
            m= max(m,height[i]);
            left[i]=m;
        }
    }
    void rightmax(vector<int>& height,vector<int>& right){
        int m =-1;
        for(int i=height.size()-1;i>=0;i--){
            m= max(m,height[i]);
            right[i]=m;
        }
    }
    int trap(vector<int>& height) {
    int n = height.size();
    int ans = 0;
    vector<int> left(n);  // l[i] := max(height[0..i])
    vector<int> right(n);
    rightmax(height,right);
    leftmax(height,left);
    for (int i = 0; i < n; ++i){
        int temp = min(right[i],left[i]);
        if((temp - height[i])>0){
            ans+=temp-height[i];
        }
    }
    return ans;
    }
};