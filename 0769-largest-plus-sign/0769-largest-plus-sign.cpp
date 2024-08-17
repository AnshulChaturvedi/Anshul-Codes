class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> grid(n, vector<int> (n,1));
        for(auto &mine : mines){
            grid[mine[0]][mine[1]] = 0;
        }
        vector<vector<int>> left(n,vector<int> (n,0));
        vector<vector<int>> right(n,vector<int> (n,0));
        vector<vector<int>> up(n,vector<int> (n,0));
        vector<vector<int>> down(n,vector<int> (n,0));
        //left and up
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    left[i][j] = (j>0) ? left[i][j-1] + 1 : 1;
                    up[i][j] = (i>0) ? up[i-1][j] + 1 : 1;
                }
            }
        }
        //right and down
        for(int j=n-1;j>=0;j--){
            for(int i=n-1;i>=0;i--){
                if(grid[i][j] == 1){
                    right[i][j] = (j<n-1) ? right[i][j+1] + 1 : 1;
                    down[i][j] = (i<n-1) ? down[i+1][j] + 1 : 1;
                }
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ans = max(min({left[i][j],right[i][j],up[i][j],down[i][j]}),ans);
            }
        }
        return ans;
    }
};