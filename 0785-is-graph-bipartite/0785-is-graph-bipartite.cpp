class Solution {
public:
    bool dfs(int node,vector<int> &color,vector<vector<int>> &graph,int col){
        color[node] = col;
        for(auto &it : graph[node]){
            if(color[it] == -1){
                if(dfs(it,color,graph,!col) == false){
                    return false;
                }
            }
            else if(color[it] == col){
                return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> color(V,-1);
        for(int i=0;i<V;i++){
            if(color[i] == -1){
                if(dfs(i,color,graph,0)==false){
                    return false;
                }
            }
        }
        return true;
    }
};