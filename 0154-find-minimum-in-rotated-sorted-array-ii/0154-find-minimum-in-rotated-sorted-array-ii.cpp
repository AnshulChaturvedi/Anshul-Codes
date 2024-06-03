class Solution {
public:
    int findMin(vector<int>& arr) {
        int n = arr.size();
        if(n == 1) return arr[0];
        int s = 0, e = n-1;
        int mini = INT_MAX;
        while(s<=e){

            if(arr[s] < arr[e]){
                mini = min(mini,arr[s]);
                break;
            }

            int mid = s + (e-s)/2;
            mini = min(mini,arr[mid]);

            if(arr[s] == arr[mid] && arr[mid] == arr[e]){
                s++;
                e--;
            }
            else if(arr[s] <= arr[mid]){
                mini = min(mini,arr[s]);
                s = mid + 1;
            }
            else{
                mini = min(mini,arr[mid]);
                e = mid - 1;
            }
        }
        return mini;
    }
};