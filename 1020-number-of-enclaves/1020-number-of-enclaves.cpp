class Solution {
public:
    int delr[4] = {0,+1,0,-1};
    int delc[4] = {+1,0,-1,0};
    int n=0,m=0;

    void dfs(int r,int c,vector<vector<int>> &board,vector<vector<int>> &vis){
        vis[r][c] = 1;
        for(int i=0;i<4;i++){
            int nrow = r + delr[i];
            int ncol = c + delc[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && board[nrow][ncol] == 1 && !vis[nrow][ncol]){
                dfs(nrow,ncol,board,vis);
            }
        }
    }
    
    int numEnclaves(vector<vector<int>>& board) {
        n = board.size();
        m = board[0].size();
        vector<vector<int>> vis(n,vector<int> (m,0));

        for(int i=0;i<n;i++){
            if(board[i][0] == 1 && !vis[i][0]) dfs(i,0,board,vis);
            if(board[i][m-1] == 1 && !vis[i][m-1]) dfs(i,m-1,board,vis);
        }
        for(int j=0;j<m;j++){
            if(board[0][j] == 1 && !vis[0][j])  dfs(0,j,board,vis);
            if(board[n-1][j] == 1 && !vis[n-1][j]) dfs(n-1,j,board,vis);
        }

        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == 1 && !vis[i][j]){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};