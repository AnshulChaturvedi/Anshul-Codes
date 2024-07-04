class Solution {
public:
    int delr[4] = {0,+1,0,-1};
    int delc[4] = {+1,0,-1,0};

    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        if(n == 1 && m == 1) return 0;

        vector<vector<int>> dist(n,vector<int> (m,1e9));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0,{0,0}});
        dist[0][0] = 0;
        while(!pq.empty()){
            auto it = pq.top();
            int minEffort = it.first;
            int r = it.second.first;
            int c = it.second.second;
            pq.pop();

            if(r == n-1 && c == m-1){
                return minEffort;
            }
            for(int i=0;i<4;i++){
                int nrow = r + delr[i];
                int ncol = c + delc[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                    int diff = abs(heights[r][c] - heights[nrow][ncol]);
                    if(dist[nrow][ncol] > max(minEffort,diff)){
                        dist[nrow][ncol] = max(minEffort,diff);
                        pq.push({dist[nrow][ncol],{nrow,ncol}});
                    }
                }
            }
        }
        return -1;
    }
};