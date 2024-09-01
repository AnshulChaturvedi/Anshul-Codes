class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& org, int m, int n) {
        int size = org.size();
        if(size != m*n) return {};

        vector<vector<int>> ans(m,vector<int> (n));
        int idx=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans[i][j] = org[idx++];
            }
        }
        return ans;
    }
};