class Solution {
public:
    void dfs(int i,int j,vector<vector<char>>& board,vector<vector<int>>& vis,vector<pair<int, int>> dir){
        vis[i][j]=1;
        int n = board.size();
        int m = board[0].size();
        for (auto [dx, dy] : dir) {
                int x = i + dx;
                int y = j + dy;

                if (x >= 0 && x < n && y >= 0 && y < m && vis[x][y] == 0&& board[x][y]=='O') {
                    dfs(x,y,board,vis,dir);
                }
            }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O' && vis[i][0] == 0) {
                dfs(i, 0, board, vis, dir);
            }
            if (board[i][m - 1] == 'O' && vis[i][m - 1] == 0) {
                dfs(i, m - 1, board, vis, dir);
            }
        }
        for (int j = 0; j < m; j++) {
            if (board[0][j] == 'O' && vis[0][j] == 0) {
                dfs(0, j, board, vis, dir);
            }
            if (board[n - 1][j] == 'O' && vis[n - 1][j] == 0) {
                dfs(n - 1, j, board, vis, dir);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 && board[i][j]=='O'){
                    board[i][j] ='X';
                }
            }
        }
    }
};