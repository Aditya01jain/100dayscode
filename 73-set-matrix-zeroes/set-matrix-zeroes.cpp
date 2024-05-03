class Solution {
public:
    void zero(vector<vector<int>>& matrix,int row,int col){
        for(int i=0;i<matrix.size();i++){
            matrix[i][col]=0;
        }
        for(int i=0;i<matrix[0].size();i++){
            matrix[row][i]=0;
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>> zeros;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    zeros.push_back(make_pair(i,j));
                }
            }
        }
        for(int i=0;i<zeros.size();i++){
          cout<<zeros[i].first<<zeros[i].second;
          zero(matrix,zeros[i].first,zeros[i].second);  
        }
    }
};