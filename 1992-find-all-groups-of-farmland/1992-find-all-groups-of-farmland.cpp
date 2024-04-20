class Solution {
private:
    void dfs(int row,int col, vector<vector<int>>& land, vector<int> &result,vector<vector<int>> &vis){
        int n = land.size();
        int m = land[0].size();
        vis[row][col] = 1;

        //conditions to find end part of farm
        if(row == n-1 && col == m-1){
            result.push_back(row);
            result.push_back(col);
        }
        else if(row+1 <= n-1 && col+1 <= m-1 && land[row+1][col] == 0 && land[row][col+1] == 0){
            result.push_back(row);
            result.push_back(col);
        }
        else if(row == n-1 && col+1 <= m-1 && land[row][col+1] == 0){
            result.push_back(row);
            result.push_back(col);
        }
        else if(row+1 <= n-1 && col == m-1 && land[row+1][col] == 0){
            result.push_back(row);
            result.push_back(col);
        }

        //dfs
        int delr[] = {-1,0,+1,0};
        int delc[] = {0,+1,0,-1};

        for(int i=0;i<4;i++){
            int nrow = row + delr[i];
            int ncol = col + delc[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && land[nrow][ncol] == 1 && vis[nrow][ncol] == 0){
                dfs(nrow,ncol,land,result,vis);
            }
        }

    }
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n = land.size();
        int m = land[0].size();

        vector<vector<int>> ans;
        vector<vector<int>> vis(n,vector<int> (m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                vector<int> result;
                if(land[i][j] == 1 && vis[i][j] == 0){
                    result.push_back(i);
                    result.push_back(j);
                    dfs(i,j,land,result,vis);
                    ans.push_back(result);
                }
            }
        }
        return ans;
    }
};