class Solution {
public:
    int delr[4] = {0,+1,0,-1};
    int delc[4] = {+1,0,-1,0};
    void dfs(int r,int c,vector<vector<int>> &vis,int n,int m,vector<vector<char>> &grid){
        vis[r][c] = 1;
        for(int i=0;i<4;i++){
            int nrow = r + delr[i];
            int ncol = c + delc[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol] == '1' && !vis[nrow][ncol]){
                dfs(nrow,ncol,vis,n,m,grid);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int> (m,0));

        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    dfs(i,j,vis,n,m,grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};