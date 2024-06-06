class Solution {
private:
    bool isFind(vector<int> arr,int target){
        int s = 0;
        int e = arr.size()-1;
        while(s<=e){
            int mid = s + (e-s)/2;
            if(arr[mid] == target){
                return true;
            }
            else if(arr[mid] < target){
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
        }
        return false;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i=0;i<n;i++){
            if(isFind(matrix[i],target)){
                return true;
            }
        }
        return false;
    }
};