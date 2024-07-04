class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int V, int S) {
        vector<pair<int,int>> adj[V+1];
        for(int i=0;i<times.size();i++){
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        vector<int> dist(V+1,1e9);
        dist[0] = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        //      {dist,Src}
        pq.push({0,S});
        dist[S] = 0;
        while(!pq.empty()){
            int node = pq.top().second;
            int distance = pq.top().first;
            pq.pop();
            for(auto &it : adj[node]){
                int v = it.first;
                int wt = it.second;
                if(dist[node] + wt < dist[v]){
                    dist[v] = dist[node] + wt;
                    pq.push({dist[v],v});
                }
            }
        }
        int ans = *max_element(dist.begin(),dist.end());
        if(ans == 1e9) return -1;
        return ans;
    }
};