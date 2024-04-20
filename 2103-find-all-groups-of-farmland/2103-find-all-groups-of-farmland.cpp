class Solution {
public:
    vector<int> delr{-1,0,+1,0};
    vector<int> delc{0,+1,0,-1};
    vector<vector<int>> ans;

    void dfs(int i,int j,int &r,int &c,int n,int m,vector<vector<int>> &land){
        if(i<0 || i>=n || j<0 || j>=m || land[i][j] == 0 || land[i][j] == 2){
            return;
        }
        land[i][j] = 2;
        r = max(r,i);
        c = max(c,j);
        for(int k=0;k<4;k++){
            dfs(i+delr[k],j+delc[k],r,c,n,m,land);
        }
    }

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n = land.size();
        int m = land[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(land[i][j] == 1){
                    int r = 0,c = 0;
                    dfs(i,j,r,c,n,m,land);
                    vector<int> result{i,j,r,c};
                    ans.push_back(result);
                }
            }
        }
        return ans;
    }
};