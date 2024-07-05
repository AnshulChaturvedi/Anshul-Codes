using ll = long long;
using pll = pair<ll,ll>;
class Solution {
public:
    const int M = 1e9+7;
    int countPaths(int V, vector<vector<int>>& roads) {
        vector<pair<ll,ll>> adj[V];
        for(int i=0;i<roads.size();i++){
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }

        vector<ll> dist(V,LLONG_MAX);
        vector<ll> ways(V,0);
        priority_queue<pll,vector<pll>,greater<pll>> pq;
        //{dist,Src}
        pq.push({0,0});
        dist[0] = 0;
        ways[0] = 1;
        while(!pq.empty()){
            ll node = pq.top().second;
            ll d = pq.top().first;
            pq.pop();
            for(auto &it : adj[node]){
                ll v = it.first;
                ll wt = it.second;
                if((ll)d + wt < dist[v]){
                    dist[v] = (ll)d + wt;
                    ways[v] = ways[node];
                    pq.push({dist[v],v});
                }
                else if((ll)d + wt == dist[v]){
                    ways[v] = (ways[v] + ways[node])%M;
                }
            }
        }
        return ways[V-1]%M;
    }
};