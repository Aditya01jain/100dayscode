class Solution {
public:
    bool isSafe1(int row, int col, vector<string> board, int n) {
        // check upper element
        int duprow = row;
        int dupcol = col;

        while (row >= 0 && col >= 0) {
            if (board[row][col] == 'Q')
                return false;
            row--;
            col--;
        }

        col = dupcol;
        row = duprow;
        while (col >= 0) {
            if (board[row][col] == 'Q')
                return false;
            col--;
        }

        row = duprow;
        col = dupcol;
        while (row < n && col >= 0) {
            if (board[row][col] == 'Q')
                return false;
            row++;
            col--;
        }
        return true;
    }
    void solve(int col ,vector<string> board,vector<vector<string>>& ans,int n ){
        if(col == n ){
            ans.push_back(board);
            return;
        };
        for(int i =0;i<n;i++){
            if(isSafe1(i,col,board,n)){
                board[i][col] = 'Q';
                solve(col+1,board,ans,n);
                board[i][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board;
        string s(n, '.');
        for (int i = 0; i < n; i++)
            board.push_back(s);
        solve(0, board, ans,n);
        return ans;
    }
};