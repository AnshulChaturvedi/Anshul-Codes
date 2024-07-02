class Solution {
public:
    bool dfs(int node,vector<int> &vis,vector<int> &pathVis,vector<vector<int>> &adj,vector<int> &check){
        vis[node] = 1;
        pathVis[node] = 1;
        check[node] = 0;
        for(auto &it : adj[node]){
            if(!vis[it]){
                if(dfs(it,vis,pathVis,adj,check)==true)
                    return true;
            }
            else if(pathVis[it]){
                return true;
            }
        }
        pathVis[node] = 0;
        check[node] = 1;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<int> vis(V,0);
        vector<int> pathVis(V,0);
        vector<int> safeNode;
        vector<int> check(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,vis,pathVis,adj,check);
            }
        }
        for(int i=0;i<V;i++){
            if(check[i] == 1)
                safeNode.push_back(i);
        }
        return safeNode;
    }
};