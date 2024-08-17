class Solution {
public:
    // int find_Ans(int st,int e,vector<int> &arr,int sum){
    //     int maxSum = sum;
    //     for(int k=st;k<=e;k++){
    //         maxSum = max(maxSum,sum-arr[k]);
    //     }
    //     return maxSum;
    // }
    
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        // int ans = -1e6;
        // for(int i=0;i<n;i++){
        //     int sum = 0;
        //     for(int j=i;j<n;j++){
        //         sum += arr[j];
        //         ans = max(find_Ans(i,j,arr,sum),ans);
        //     }
        // }
        // if(ans == 0){
        //     return *max_element(arr.begin(),arr.end());
        // }
        // return ans;
        int maxEndingHere = arr[0];
        int maxWithOneSkip = 0;
        int ans = arr[0];
        for(int i=1;i<n;i++){
            maxWithOneSkip = max(maxWithOneSkip + arr[i], maxEndingHere);
            maxEndingHere = max(maxEndingHere + arr[i], arr[i]);
            ans = max({ans,maxEndingHere,maxWithOneSkip});
        }
        return ans;
    }
};