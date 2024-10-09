class Solution {
public:
    // DFS for marking all the invalid cells visited:
    void dfs(int row,int col,vector<vector<int>>&vis,vector<vector<char>>& board){
        vis[row][col] = 1;
        int m = board.size();
        int n = board[0].size();
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};

        for(int i = 0;i<4;i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && !vis[nrow][ncol] &&
               board[nrow][ncol] == 'O'){
                dfs(nrow,ncol,vis,board);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        // traverse all edge columns
        for(int i = 0;i<n;i++){
            if(board[0][i] == 'O' && !vis[0][i]){
                dfs(0,i,vis,board); 
            }
            if(board[m-1][i] == 'O' && !vis[m-1][i]){
                dfs(m-1,i,vis,board);
            }
        }
        // traverse all edge rows
        for(int i = 0;i<m;i++){
            if(board[i][0] == 'O' && !vis[i][0]){
                dfs(i,0,vis,board);
            }
            if(board[i][n-1] == 'O' && !vis[i][n-1]){
                dfs(i,n-1,vis,board);
            }
        }
        // convert all the valid 'O' to 'X'
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] == 'O' && !vis[i][j]){
                    board[i][j] = 'X';
                }
            }
        }
    }
};