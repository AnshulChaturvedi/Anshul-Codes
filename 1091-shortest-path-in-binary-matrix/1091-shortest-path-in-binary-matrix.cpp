class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] == 1) return -1;
        int n = grid.size();
        if(n == 1 && grid[0][0] == 0) return 1;

        vector<vector<int>> distArr(n,vector<int> (n,1e9));
        queue<pair<int,pair<int,int>>> q;
        // {dist,{r,c}}
        q.push({1,{0,0}});
        distArr[0][0] = 1;
        while(!q.empty()){
            auto it = q.front();
            int dist = it.first;
            int r = it.second.first;
            int c = it.second.second;
            q.pop();

            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    int nrow = r + i;
                    int ncol = c + j;
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && grid[nrow][ncol] == 0 && distArr[nrow][ncol] > dist + 1){
                        distArr[nrow][ncol] = dist + 1;
                        if(nrow == n-1 && ncol == n-1) return dist + 1;
                        q.push({dist + 1,{nrow,ncol}});
                    }
                }
            }
        }
        return -1;
    }
};