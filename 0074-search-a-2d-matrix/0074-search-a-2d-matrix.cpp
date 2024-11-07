class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int r = 0;
        int c = mat[0].size()-1;
        while(r<mat.size() && c>=0){
            int curr = mat[r][c];
            if(curr == target) return true;
            else if(curr < target) r++;
            else{
                //search in given row vector(B.S)
                return binary_search(mat[r].begin(),mat[r].end(),target);
            }
        }
        return false;
    }
};