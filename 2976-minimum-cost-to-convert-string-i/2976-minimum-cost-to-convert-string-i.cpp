using ll = long long;

class Solution {
public:
    // int findShortestPath(int src, int dst, map<int,vector<pair<int,int>>> &adj){
    //     vector<ll> dist(26,1e9);
    //     priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    //     pq.push({0,src});
    //     dist[src] = 0;
    //     while(!pq.empty()){
    //         int node = pq.top().second;
    //         int distance = pq.top().first;
    //         pq.pop();
    //         for(auto &it : adj[node]){
    //             int v = it.first;
    //             int wt = it.second;
    //             if(dist[node] + wt < dist[v]){
    //                 dist[v] = dist[node] + wt;
    //                 pq.push({dist[v],v});
    //             }
    //         }
    //     }
    //     if(dist[dst] == 1e9) return -1;
    //     return dist[dst];
    // }

    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<int>> matrix(26,vector<int> (26,1e9));
        for(int i=0;i<cost.size();i++){
            int x = original[i]-'a', y = changed[i]-'a';
            matrix[x][y] = min(matrix[x][y], cost[i]);
        }
        for(int i=0;i<26;i++){
            matrix[i][i] = 0;
        }

        for(int k=0;k<26;k++){
            for(int i=0;i<26;i++){
                for(int j=0;j<26;j++){
                    if(matrix[i][k] < 1e9 && matrix[k][j] < 1e9)
                        matrix[i][j] = min(matrix[i][j],matrix[i][k] + matrix[k][j]);
                }
            }
        }

        ll ans = 0;
        for(int i=0;i<target.size();i++){
            if(source[i] != target[i]){
                int val = matrix[source[i]-'a'][target[i]-'a'];
                if(val == 1e9) return -1;
                ans += (ll)val;
            }
        }
        return ans;
    }
};