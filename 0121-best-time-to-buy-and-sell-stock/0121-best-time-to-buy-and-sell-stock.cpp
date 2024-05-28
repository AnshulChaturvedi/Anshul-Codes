class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // int maxi = INT_MIN;
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         if(prices[j] > prices[i]){
        //             int diff = prices[j]-prices[i];
        //             maxi = max(maxi,diff);
        //         }
        //     }
        // }
        // return (maxi == INT_MIN) ? 0 : maxi;
        int i = 0;
        int maxi = INT_MIN;
        int buy = prices[0];
        for(int i=1;i<n;i++){
            if(prices[i]>buy){
                int diff = prices[i] - buy;
                maxi = max(maxi,diff);
            }
            else{
                buy = prices[i];
            }
        }
        return (maxi == INT_MIN) ? 0 : maxi;
    }
};