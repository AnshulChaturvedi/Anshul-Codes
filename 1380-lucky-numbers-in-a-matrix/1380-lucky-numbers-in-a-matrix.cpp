class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> ans;
        unordered_set<int> st;
        for(auto &it : matrix){
            int element = *min_element(it.begin(),it.end());
            st.insert(element);
        }
        int n = matrix.size();
        int m = matrix[0].size();
        for(int j=0;j<m;j++){
            int maxi = 0;
            for(int i=0;i<n;i++){
                maxi = max(maxi,matrix[i][j]);
            }
            if(st.find(maxi) != st.end()){
                ans.push_back(maxi);
            }
        }
        return ans;
    }
};