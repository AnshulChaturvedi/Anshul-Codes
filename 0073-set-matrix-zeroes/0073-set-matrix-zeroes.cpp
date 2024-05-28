class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<pair<int,int>> vec;
        //{row,col}

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j] == 0){
                    vec.push_back({i,j});
                }
            }
        }
        for(int i=0;i<vec.size();i++){
            int row = vec[i].first;
            int col = vec[i].second;
            for(int k=0;k<n;k++){
                matrix[row][k] = 0;
            }
            for(int l=0;l<m;l++){
                matrix[l][col] = 0;
            }
        }
    }
};