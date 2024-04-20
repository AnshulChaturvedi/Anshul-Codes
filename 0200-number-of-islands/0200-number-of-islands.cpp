class Solution {
private:
    void dfs(int r,int c,vector<vector<char>>& grid,vector<vector<int>>& vis){
        int n = grid.size();
        int m = grid[0].size();
        vis[r][c] = 1;

        int drow[] = {-1,0,+1,0};
        int dcol[] = {0,+1,0,-1};

        for(int i=0;i<4;i++){
            int nrow = r + drow[i];
            int ncol = c + dcol[i];

            if(nrow >=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol] == '1' && vis[nrow][ncol] == 0){
                dfs(nrow,ncol,grid,vis);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        vector<vector<int>> vis(n,vector<int> (m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == '1' && vis[i][j] == 0){
                    dfs(i,j,grid,vis);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};