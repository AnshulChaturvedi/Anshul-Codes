class Solution {
public:
    int findMin(vector<int>& arr) {
        //either the minimum is present in the sorted part or may not present
        int n = arr.size();
        int s = 0;
        int e = n-1;
        int mini = INT_MAX;
        while(s<=e){
            // if(arr[s] < arr[e]){
            //     mini = min(mini,arr[s]);
            //     break;
            // }

            int mid = s + (e-s)/2;
            mini = min(mini,arr[mid]);
            
            if(arr[s] <= arr[mid]){// left part is sorted
                mini = min(mini,arr[s]);
                s = mid + 1;
            }
            else{// right part is sorted
                mini = min(mini,arr[mid]);
                e = mid - 1;
            }
        }
        return mini;
    }
};