class Solution {
private:
    vector<vector<int>> prefixSum(vector<vector<char>> &grid,char ch){
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> pre(n,vector<int> (m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                pre[i][j] = (grid[i][j] == ch);
                if(i>0) pre[i][j] += pre[i-1][j];
                if(j>0) pre[i][j] += pre[i][j-1];
                if(i>0 && j>0) pre[i][j] -= pre[i-1][j-1];
            }
        }
        return pre;
    }
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> xMatrix = prefixSum(grid,'X');
        vector<vector<int>> yMatrix = prefixSum(grid,'Y');
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans += (xMatrix[i][j] == yMatrix[i][j] && xMatrix[i][j] > 0);
            }
        }
        return ans;
    }
};