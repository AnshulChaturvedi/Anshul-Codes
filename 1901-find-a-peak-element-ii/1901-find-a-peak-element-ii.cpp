class Solution {
private:
    int findMax(vector<vector<int>>& mat, int mid){
        int maxi = INT_MIN;
        int maxRow = -1;
        for(int i=0;i<mat.size();i++){
            if(mat[i][mid] > maxi){
                maxi = mat[i][mid];
                maxRow = i;
            }
        }
        return maxRow;
    }

public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int s = 0;
        int e = m-1;
        while(s<=e){
            int mid = s + (e-s)/2; // i.e basically the coloumn
            //find the maximum element in this coloumn
            int maxEleRow = findMax(mat,mid);
            int maxElement = mat[maxEleRow][mid];
            int left = (mid-1 >= 0) ? mat[maxEleRow][mid-1] : -1;
            int right = (mid+1 < m) ? mat[maxEleRow][mid+1] : -1;

            if(maxElement > left && maxElement > right){
                return {maxEleRow,mid};
            }
            else if(maxElement < left){
                e = mid - 1;
            }
            else if(maxElement < right){
                s = mid + 1;
            }
        }
        return {-1,-1};
    }
};