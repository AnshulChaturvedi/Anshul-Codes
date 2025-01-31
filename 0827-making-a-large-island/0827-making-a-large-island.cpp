class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int comp_id = 1;
        vector<vector<int>> comp(n, vector<int> (n,0));
        unordered_map<int,int> mpp;
        int dir[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1 && comp[i][j] == 0){
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    comp[i][j] = comp_id;
                    int size = 0;
                    while(!q.empty()){
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();
                        size++;
                        for(auto &it : dir){
                            int nx = x + it[0];
                            int ny = y + it[1];
                            if(nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == 1 && comp[nx][ny] == 0){
                                comp[nx][ny] = comp_id;
                                q.push({nx,ny});
                            }
                        }
                    }
                    mpp[comp_id] = size;
                    comp_id++;
                }
            }
        }
        int max_size = 0;
        for(auto &it : mpp){
            max_size = max(max_size, it.second);
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 0){
                    unordered_set<int> st;
                    int total = 1;
                    for(auto &it : dir){
                        int nx = i + it[0];
                        int ny = j + it[1];
                        if(nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == 1){
                            st.insert(comp[nx][ny]);
                        }
                    }
                    for(auto &it : st){
                        total += mpp[it];
                    }
                    max_size = max(max_size, total);
                }
            }
        }
        return (max_size != 0) ? max_size : 1;
    }
};