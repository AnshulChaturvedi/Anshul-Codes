class Solution {
public:
    bool bfs(int node, vector<int> adj[], vector<int>& col) {
        queue<int> q;
        q.push(node);
        col[node] = 1;
        while (!q.empty()) {
            int t = q.front();
            q.pop();
            for (auto &it : adj[t]) {
                if (col[it] == -1) {
                    col[it] = 1 - col[t];
                    q.push(it);
                } else if (col[it] == col[t]) {
                    return false; 
                }
            }
        }
        return true;
    }

    bool isbip(vector<int> adj[], int n) {
        vector<int> col(n + 1, -1);
        for (int i = 1; i <= n; i++) {
            if (col[i] == -1) {  
                if (!bfs(i, adj, col)) {
                    return false;
                }
            }
        }
        return true;
    }

    void findcomp(int node, vector<int> adj[], unordered_set<int>& comp, vector<int>& vis) {
        queue<int> q;
        q.push(node);
        vis[node] = 1;
        comp.insert(node);
        while (!q.empty()) {
            int t = q.front();
            q.pop();
            for (auto &it : adj[t]) {
                if (vis[it] == -1) {
                    vis[it] = 1;
                    comp.insert(it);
                    q.push(it);
                }
            }
        }
    }

    int findDist(vector<int> adj[], int n, int node) {
        queue<int> q;
        vector<int> dist(n + 1, -1);
        q.push(node);
        dist[node] = 0;  
        int mx = 0;
        while (!q.empty()) {
            int t = q.front();
            q.pop();
            for (auto &it : adj[t]) {
                if (dist[it] == -1) {
                    dist[it] = dist[t] + 1;
                    q.push(it);
                    mx = max(mx, dist[it]);
                }
            }
        }
        return mx;
    }

    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<int> adj[n + 1];
        vector<int> vis(n + 1, -1);
        
        for (auto it : edges) {
            int u = it[0], v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        if (!isbip(adj, n)) {
            return -1;
        }

        int ans = 0;
        unordered_set<int> comp;
        
        for (int i = 1; i <= n; i++) {
            if (vis[i] != -1) continue;
            comp.clear();
            findcomp(i, adj, comp, vis);

            int res = -1;
            for (auto it : comp) {
                res = max(res, findDist(adj, n, it));
            }
            if (res == -1) {
                return -1;
            }
            ans += res + 1;
        }
        return ans;
    }
};