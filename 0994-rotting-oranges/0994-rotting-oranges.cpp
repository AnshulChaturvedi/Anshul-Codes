class Solution {
public:
    vector<int> delr{1,0,-1,0};
    vector<int> delc{0,-1,0,1};
    int ans = 0;
    
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int> (m,0));
        
        queue<pair<int,int>> q;
        // to store the indexes of rotten orange
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2){//rotten orange
                    q.push({i,j});
                    vis[i][j] = 2;
                }
                //fresh orange
                else if(grid[i][j] == 1){
                    vis[i][j] = 1;
                }
            }
        }
        
        while(!q.empty()){
            int size = q.size();
            ans++;
            
            for(int j=0;j<size;j++){
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                
                for(int i=0;i<4;i++){
                    int nrow = r + delr[i];
                    int ncol = c + delc[i];
                    if( nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol] == 1 &&  vis[nrow][ncol] == 1){
                        q.push({nrow,ncol});
                        vis[nrow][ncol] = 2;
                    }
                }
            }
        }
         for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(vis[i][j] == 1){
                    return -1;
                }
            }
        }
        
        return max(0,ans-1);//to remove the final initial state
    }
};