class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buyDay = prices[0];
        int maxProfit = 0;
        for(int i=1;i<n;i++){
            if(prices[i] > buyDay){
                maxProfit += prices[i] - buyDay;
                buyDay = prices[i];
            }
            else{
                buyDay = prices[i];
            }
        }
        return maxProfit;
    }
};