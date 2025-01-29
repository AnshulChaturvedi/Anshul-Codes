class Solution {
public:
    vector<int> parent;
    int find_set(int v){
        if(v == parent[v])
            return v;
        return find_set(parent[v]);
    }
    void union_sets(int a, int b){
        a = find_set(a);
        b = find_set(b);
        if(a != b)
            parent[b] = a;
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n+1);

        for(int i=1; i<=n; i++){
            parent[i] = i;
        }

        for(auto edge : edges){
            int root_u = find_set(edge[0]);
            int root_v = find_set(edge[1]);
            if(root_u == root_v){
                return {edge[0], edge[1]};
            }
            else{
                union_sets(edge[0], edge[1]);
            }
        }
        return {};
    }
};