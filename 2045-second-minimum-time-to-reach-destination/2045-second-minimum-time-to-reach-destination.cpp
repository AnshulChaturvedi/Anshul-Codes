class Solution {
public:
    int dijkstra(int src,int dst,unordered_map<int,vector<int>> &adj,int time,int change,int n){
        vector<int> dis1(n+1,1e9),dis2(n+1,1e9);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,src});
        dis1[src] = 0;
        while(!pq.empty()){
            int node = pq.top().second;
            int dist = pq.top().first;
            pq.pop();

            if ((dist / change) % 2 == 1) {
                dist += change - (dist % change);
            }

            for(auto &it : adj[node]){
                int newDist = dist + time;
                if(dis1[it] > newDist){
                    dis2[it] = dis1[it];
                    dis1[it] = newDist;
                    pq.push({newDist,it});
                }
                else if(dis1[it] < newDist && dis2[it] > newDist){
                    dis2[it] = newDist;
                    pq.push({newDist,it});
                }
            }
        }
        return dis2[dst];
    }

    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        unordered_map<int,vector<int>> adj;
        for(auto &it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        return dijkstra(1,n,adj,time,change,n);
    }
};