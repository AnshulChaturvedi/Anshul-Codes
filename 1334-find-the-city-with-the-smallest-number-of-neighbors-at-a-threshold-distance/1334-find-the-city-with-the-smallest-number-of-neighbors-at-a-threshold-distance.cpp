class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        //adjMatrix from edges
        vector<vector<int>> matrix(n ,vector<int> (n,1e9));
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            matrix[u][v] = wt;
            matrix[v][u] = wt;
        }
        for(int i=0;i<n;i++){
            matrix[i][i] = 0;
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    matrix[i][j] = min(matrix[i][j],matrix[i][k] + matrix[k][j]);
                }
            }
        }
        int ans = 0, maxi = -1;
        for(int i=0;i<n;i++){
            int cnt = 0;
            for(int j=0;j<n;j++){
                if(matrix[i][j] > distanceThreshold){
                    cnt++;
                }
            }
            if(cnt>=maxi){
                maxi = cnt;
                ans = i;
            }
        }
        return ans;
    }
};