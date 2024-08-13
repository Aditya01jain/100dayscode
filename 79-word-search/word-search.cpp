class Solution {
public:
    bool solve(vector<vector<char>>& board, string word,int i,int j,int n,int m,int in){
        if(in == word.size()) return true;
        if(i<0 || j<0 || i==n || j== m || board[i][j]=='!'|| board[i][j]!= word[in]) return false;
        char c = board[i][j];
        board[i][j] = '!';
        bool top = solve(board,word,i-1,j,n,m,in+1);
        bool bottom = solve(board,word,i+1,j,n,m,in+1);
        bool left = solve(board,word,i,j-1,n,m,in+1);
        bool right = solve(board,word,i,j+1,n,m,in+1);
        board[i][j] = c;
        return top||bottom||left||right;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]) if(solve(board,word,i,j,n,m,0)) return true;
            }
        }
        return false;
    }
};