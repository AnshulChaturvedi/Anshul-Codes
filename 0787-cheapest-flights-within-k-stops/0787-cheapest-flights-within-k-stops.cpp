class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(int i=0;i<flights.size();i++){
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }

        vector<int> dist(n,1e9);
        queue<pair<int,pair<int,int>>> q;
        // {stops,{src,dist}}
        q.push({0,{src,0}});
        dist[src] = 0;
        while(!q.empty()){
            auto &val = q.front();
            int node = val.second.first;
            int dis = val.second.second;
            int stops = val.first;
            q.pop();

            if(stops > k){
                continue;
            }
            
            for(auto &it : adj[node]){
                int v = it.first;
                int wt = it.second;
                if(dis + wt < dist[v] && stops <= k){
                    dist[v] = dis + wt;
                    q.push({stops+1,{v,dist[v]}});
                }
            }
        }
        if(dist[dst] == 1e9) return -1;
        return dist[dst];
    }
};