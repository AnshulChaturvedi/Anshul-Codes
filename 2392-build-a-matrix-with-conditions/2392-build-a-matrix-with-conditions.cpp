class Solution {
public:
    vector<int> topoSort(vector<vector<int>> &edges,int &V){
        vector<int> adj[V+1];
        vector<int> indegree(V+1,0);
        for(auto &it : edges){
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }
        queue<int> q;
        for(int i=1;i<=V;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        vector<int> order;
        int cnt = 0;
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            order.push_back(node);
            cnt++;
            for(auto &v : adj[node]){
                indegree[v]--;
                if(indegree[v] == 0){
                    q.push(v);
                }
            }
        }
        if(cnt != V) return {};
        return order;
    }

    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> topoRow = topoSort(rowConditions,k);
        vector<int> topoCol = topoSort(colConditions,k);
        if(topoRow.empty() || topoCol.empty()) return {};
        vector<vector<int>> mat(k,vector<int> (k,0));
        for(int i=0;i<k;i++){
            for(int j=0;j<k;j++){
                if(topoRow[i] == topoCol[j]){
                    mat[i][j] = topoRow[i];
                }
            }
        }
        return mat;
    }
};