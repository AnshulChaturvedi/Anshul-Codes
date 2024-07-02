class Solution {
public:
    vector<int> findOrder(int V, vector<vector<int>>& pre) {
        //b is prerequisties for a
        // b-->>a
        vector<int> adj[V];
        vector<int> indegree(V,0);
        for(int i=0;i<pre.size();i++){
            adj[pre[i][1]].push_back(pre[i][0]);
            indegree[pre[i][0]]++;
        }
        queue<int> q;
        for(int i=0;i<V;i++){
            if(indegree[i] == 0)
                q.push(i);
        }
        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto &it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        return (topo.size() == V) ? topo : vector<int> ();
    }
};