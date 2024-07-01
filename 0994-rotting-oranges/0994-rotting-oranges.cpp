class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int freshCnt = 0;
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
                else if(grid[i][j] == 1) freshCnt++;
            }
        }
        if(freshCnt == 0) return 0;

        int ans = 0;
        int delr[4] = {0,+1,0,-1};
        int delc[4] = {+1,0,-1,0};

        while(!q.empty()){
            int size = q.size();
            bool isAnyFresh = false;

            for(int i=0;i<size;i++){
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                for(int j=0;j<4;j++){
                    int nrow = r + delr[j];
                    int ncol = c + delc[j];
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol] == 1){
                        grid[nrow][ncol] = 2;
                        freshCnt--;
                        isAnyFresh = true;
                        q.push({nrow,ncol});
                    }
                }
            }
            if(isAnyFresh == true) ans++;
        }
        return (freshCnt == 0) ? ans : -1;
    }
};