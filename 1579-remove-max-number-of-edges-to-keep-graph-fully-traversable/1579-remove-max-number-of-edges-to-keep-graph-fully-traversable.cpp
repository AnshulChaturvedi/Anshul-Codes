class dsu{
    public:
        vector<int> parent;
        vector<int> rank;
        int components;

        dsu(int n){
            parent.resize(n+1);
            for(int i=1;i<=n;i++){
                parent[i] = i;
            }

            rank.resize(n+1);
            components = n;
        }

        int find(int a){
            if(parent[a] == a){
                return a;
            }
            return parent[a] = find(parent[a]);
        }

        void Union(int a,int b){
            int a_parent = parent[a];
            int b_parent = parent[b];

            if(a_parent == b_parent){
                return;
            }

            if(rank[a_parent] > rank[b_parent]){
                parent[b_parent] = a_parent;
            }
            else if(rank[a_parent] < rank[b_parent]){
                parent[a_parent] = b_parent;
            }
            else{
                parent[a_parent] = b_parent;
                rank[b_parent]++;
            }
            //reduce the components number by one on doing the union 
            components--;
        }

        bool isSingleComponent(){
            return components == 1;
        }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        dsu Alice(n);
        dsu Bob(n);

        sort(edges.begin(),edges.end(),greater<vector<int>>());
        int edgeCnt = 0;

        for(auto &num : edges){
            int type = num[0];
            int u = num[1];
            int v = num[2];

            if(type == 3){
                bool edgeCountTrue = false;

                if(Alice.find(u) != Alice.find(v)){
                    Alice.Union(u,v);
                    edgeCountTrue = true;
                }

                if(Bob.find(u) != Bob.find(v)){
                    Bob.Union(u,v);
                    edgeCountTrue = true;
                }

                if(edgeCountTrue) edgeCnt++;

            }
            else if(type == 2){
                if(Bob.find(u) != Bob.find(v)){
                    Bob.Union(u,v);
                    edgeCnt++;
                }
            }
            else{
                if(Alice.find(u) != Alice.find(v)){
                    Alice.Union(u,v);
                    edgeCnt++;
                }
            }
        }

        if(Alice.isSingleComponent() == true && Bob.isSingleComponent() == true){
            return edges.size()-edgeCnt;
        }
        return -1;
    }
};