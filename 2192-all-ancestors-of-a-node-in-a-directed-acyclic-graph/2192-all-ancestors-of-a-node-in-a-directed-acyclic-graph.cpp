class Solution {
public:
    void dfs(int node,int ancestor,vector<int> adjList[],vector<vector<int>> &ans){
        for(auto &it : adjList[node]){
            if(ans[it].empty() || ans[it].back() != ancestor){
                ans[it].push_back(ancestor);
                dfs(it,ancestor,adjList,ans);
            }
        }
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<int> adjList[n];
        for(auto &num : edges){
            adjList[num[0]].push_back(num[1]);
        }

        vector<vector<int>> ans(n);

        for(int i=0;i<n;i++){
            int ancestor = i;
            dfs(i,ancestor,adjList,ans);
        }
        return ans;
    }
};