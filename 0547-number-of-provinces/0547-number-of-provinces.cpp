class Solution {
public:
    void dfs(int node,vector<int> adj[],vector<int> &vis){
        vis[node] = 1;
        for(auto &it : adj[node]){
            if(!vis[it]){
                dfs(it,adj,vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        //adjMatrix -> adjList
        vector<int> adj[V];
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(isConnected[i][j] == 1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int cnt = 0;
        vector<int> vis(V,0);

        for(int i=0;i<V;i++){
            if(!vis[i]){
                cnt++;
                dfs(i,adj,vis);
            }
        }

        return cnt;
    }
};