class Solution {
public:
    int numSquares(int n) {

        //creating [1,4,9,16,25,....]
        int size = sqrt(n);
        vector<int> arr;
        int i = 1;
        while(i<=size){
            arr.push_back(i*i);
            i++;
        }

        vector<int> dp(n+1,INT_MAX);
        //dp[i] represents the mini no. of perfect sq req to make sum n
        dp[0] = 0;

        for(int i=1;i<=n;i++){
            for(int j=0;j<size;j++){
                if(i-arr[j] >= 0)
                    dp[i] = min(dp[i],dp[i-arr[j]]+1);
            }
        }

        return dp[n];
    }
};